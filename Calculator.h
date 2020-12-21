#pragma once
#include <istream>
#include "Context.h"
#include "Operation.h"
#include "operations.h"
#include "OperationFactory.h"

class Calculator {
public:
	void calculate(std::istream& stream);
};

void Calculator::calculate(std::istream& stream) {
	Context context;
	std::string str = "";
	while (std::getline(stream, str) && str != "QUIT") {
		std::list <std::string> args;
		std::string command;
		std::size_t ind = str.find(' ');
		command = str.substr(0, ind); 
		while (ind != std::string::npos) {
			str = str.substr(ind+1, str.length());
			ind = str.find(' ');
			std::string arg;
			if (ind != std::string::npos) {
				arg = str.substr(0, ind);
			}
			else {
				arg = str;
			}
			if (arg != "") {
				args.push_back(arg);
			}
		}
		try {
			Operation* operation(OperationFactory::getInstance().create(command));
			operation->execute(args, context);
		}
		catch (MyException &ex) {
			std::cerr << ex.what() << std::endl;
		}
		
	}
}