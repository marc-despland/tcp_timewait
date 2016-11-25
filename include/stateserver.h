#ifndef _STATESERVER_H
#define _STATESERVER_H


class StateServer {
public:
	StateServer();
	bool send_bip;
	bool direct_close;
	int closewait;


};

#endif