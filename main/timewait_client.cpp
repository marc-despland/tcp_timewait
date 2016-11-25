#include <iostream>
#include "options.h"
#include "log.h"
#include "client.h"


int main(int argc, char **argv) {
	cout << " Starting"<<endl;
	Log::logger->setLevel(NOTICE);
	Options options(argv[0], "1.0.0", "TimeWait test client");
	try {
		options.add('d', "debug", "Start on debug mode", false, false);
		options.add('f', "fromport", "Local port", true, true);
		options.add('t', "target", "Target host", true, true);
		options.add('c', "dstport", "Destination port on target", true, true);
		options.add('s', "scenario", "Scenario to use", true, true);
	} catch(ExistingOptionException &e ) {
	}
	try {
		options.parse(argc, argv);
		if (options.get('d')->isAssign()) Log::logger->setLevel(DEBUG);
		Client * client=new Client(options.get("fromport")->asInt(), options.get("dstport")->asInt(), options.get("target")->asChars());
		client->run(options.get("scenario")->asInt());
		
	} catch (OptionsStopException &e) {
	} catch (UnknownOptionException &e) {
		cout << " Request unknown option"<<endl;
	}

}