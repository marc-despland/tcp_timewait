#ifndef _STATE_H
#define _STATE_H


class State {
public:
	State();
	unsigned int readwait;
	bool shutdown_done;
	bool close_after_read;
	bool use_shutdown;
	bool connected;
	bool not_closing_on_close_detected;
	bool close_after_connect;
protected:


};

#endif