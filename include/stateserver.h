#ifndef _STATESERVER_H
#define _STATESERVER_H


class StateServer {
public:
	StateServer();
	bool send_bip;
	bool direct_close;
	int closewait;
	bool not_closing_on_close_detected;
	bool send_bip_on_close;


};

#endif