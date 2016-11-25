#include <iostream>
#include "options.h"
#include "log.h"
#include "server.h"


int main(int argc, char **argv) {
	cout << " Starting"<<endl;
	Log::logger->setLevel(NOTICE);
	Options options(argv[0], "1.0.0", "TimeWait test serevr");
	try {
		options.add('d', "debug", "Start on debug mode", false, false);
		options.add('p', "port", "Port to listen to", true, true);
		options.add('s', "scenario", "Scenario to use", true, true);
	} catch(ExistingOptionException &e ) {
	}
	try {
		options.parse(argc, argv);
		if (options.get('d')->isAssign()) Log::logger->setLevel(DEBUG);
		Server * server=new Server(options.get("port")->asInt());
		server->run(options.get("scenario")->asInt());
		
	} catch (OptionsStopException &e) {
	} catch (UnknownOptionException &e) {
		cout << " Request unknown option"<<endl;
	}

}