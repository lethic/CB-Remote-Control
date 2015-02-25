all:
	g++ cbctrl.cpp cbredisclient.cpp /usr/local/lib/libhiredis.a -o cbctrl
