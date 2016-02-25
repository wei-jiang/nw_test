var alipay = require('../alipay_config').alipay;

alipay.on('verify_fail', function(){console.log('emit verify_fail')})
	.on('create_direct_pay_by_user_trade_finished', function(out_trade_no, trade_no){
        console.log('emit create_direct_pay_by_user_trade_finished')
        })
	.on('create_direct_pay_by_user_trade_success', function(out_trade_no, trade_no){
        console.log('emit create_direct_pay_by_user_trade_success')
        })	
	.on('refund_fastpay_by_platform_pwd_success', function(batch_no, success_num, result_details){
        console.log('emit refund_fastpay_by_platform_pwd_success')
        })
	.on('create_partner_trade_by_buyer_wait_buyer_pay', function(out_trade_no, trade_no){
        console.log('emit create_partner_trade_by_buyer_wait_buyer_pay')
        })
	.on('create_partner_trade_by_buyer_wait_seller_send_goods', function(out_trade_no, trade_no){
        console.log('emit create_partner_trade_by_buyer_wait_seller_send_goods')
        })
	.on('create_partner_trade_by_buyer_wait_buyer_confirm_goods', function(out_trade_no, trade_no){
        console.log('emit create_partner_trade_by_buyer_wait_buyer_confirm_goods')
        })
	.on('create_partner_trade_by_buyer_trade_finished', function(out_trade_no, trade_no){
        console.log('emit create_partner_trade_by_buyer_trade_finished')
        })
	.on('send_goods_confirm_by_platform_fail', function(error){
        console.log('emit send_goods_confirm_by_platform_fail')
        })
	.on('send_goods_confirm_by_platform_success', function(out_trade_no, trade_no, xml){
        console.log('emit send_goods_confirm_by_platform_success')
        })
	.on('trade_create_by_buyer_wait_buyer_pay', function(out_trade_no, trade_no){
        console.log('emit trade_create_by_buyer_wait_buyer_pay')
        })
	.on('trade_create_by_buyer_wait_seller_send_goods', function(out_trade_no, trade_no){
        console.log('emit trade_create_by_buyer_wait_seller_send_goods')
        })
	.on('trade_create_by_buyer_wait_buyer_confirm_goods', function(out_trade_no, trade_no){
        console.log('emit trade_create_by_buyer_wait_buyer_confirm_goods')
        })
	.on('trade_create_by_buyer_trade_finished', function(out_trade_no, trade_no){
        console.log('emit trade_create_by_buyer_trade_finished')
        });	
	
function randomString(sl) {
	var chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghiklmnopqrstuvwxyz";
	var string_length = sl ? sl : 8;
	var randomstring = '';
	for (var i=0; i<string_length; i++) {
		var rnum = Math.floor(Math.random() * chars.length);
		randomstring += chars.substring(rnum,rnum+1);
	}
	return randomstring;
}
exports.create_direct_pay_by_user = function(req, res){
	var _GET = req.query;
    console.log( JSON.stringify(_GET) );
    var pro_id = _GET['product_id'];		
    var data = {
            //订单号
            out_trade_no:randomString() 
            //订单名称
            ,subject:'测试订单' 
            //付款金额
            ,total_fee:0.01
            //订单描述 
            ,body: '测试订单的描述'
            //商品展示地址
            ,show_url:'http://ily365.cn'
        };		
    
    alipay.create_direct_pay_by_user(data, res);		

}
