#pragma once
#include "Operation.h"
#include "IOperationMaker.h"
#include "exceptions.h"


class OperationFactory {

public:
	static OperationFactory& getInstance();
	Operation* create(std::string& name) const;
};

OperationFactory& OperationFactory::getInstance() {
	static OperationFactory factory;
	return factory;
}

Operation* OperationFactory::create(std::string& name) const{
	if (name == "+") {
		return new Add;
	}
	else if (name == "-") {
		return new Subtract;
	}
	else if (name == "*") {
		return new Multiply;
	}
	else if (name == "/") {
		return new Divide;
	}
	else if (name == "SQRT") {
		return new Sqrt;
	}
	else if (name == "PUSH") {
		return new Push;
	}
	else if (name == "POP") {
		return new Pop;
	}
	else if (name == "PRINT") {
		return new Print;
	}
	else if (name == "DEFINE") {
		return new Define;
	}
	else if (name == "#") {
		return new Comment;
	}
	else throw operation_error("Incorrect operation");
}