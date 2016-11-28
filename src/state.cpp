#include "state.h"

State::State() {
	this->readwait=0;
	this->shutdown_done=false;
	this->close_after_read=false;
	this->use_shutdown=false;
	this->connected=false;
	this->not_closing_on_close_detected=false;
	this->close_after_connect=false;
}