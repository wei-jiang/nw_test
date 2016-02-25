var fs = require('fs');

var app = require('express')();
var server = require('http').Server(app);
var io = require('socket.io')(server);
var addon = require('bindings')('turnstile');
var ap_dealer = require('./routes/ap_route');

server.listen(12345);
app.use(require('express').static(__dirname + '/public'));
// app.get('/', function (req, res) {
//   res.sendfile(__dirname + '/index.html');
// });

io.on('connection', function(socket){
    setInterval(
        function (params) {
            
            socket.emit('from_svr_period', addon.test_cpp() );
        },
        90
    )
    socket.on('peer_online', function (data) {
        console.log("peer_online"+JSON.stringify(data) );
    });
    socket.on('cli_cmd1', function(data){
        console.log("cli_cmd1"+JSON.stringify(data) );
        socket.emit('from_svr1', addon.get_ver() );
    });
    socket.on('cli_cmd2', function(data){
        console.log("cli_cmd2"+JSON.stringify(data) );
        var s_ret = addon.load_dll() == 0 ? "加载dll成功" : "加载dll失败";
        socket.emit('from_svr2', s_ret );
    });
});

require('./alipay_config').alipay.route(app);
app.get('/create_direct_pay_by_user', ap_dealer.create_direct_pay_by_user);