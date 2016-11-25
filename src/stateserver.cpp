#include "stateserver.h"

StateServer::StateServer() {
	this->send_bip=false;
	this->direct_close=false;
	this->closewait=0;
}