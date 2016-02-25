node-gyp rebuild 
npm install nw-builder -g
nw-gyp clean
nw-gyp rebuild --target=0.12.3 --msvs_version=2013

nwbuild -p win32,win64,osx64,linux32,linux64 .
nwbuild -p win32 -v 0.12.3 .