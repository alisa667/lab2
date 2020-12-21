#pragma once
#include <list>
#include <string>
#include "Context.h"
#include "OperationMaker.h"

class Operation {
public:
	virtual void execute(const std::list<std::string> &args, Context& context) = 0;
};

