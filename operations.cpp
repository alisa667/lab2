#include "operations.h"
#include "exceptions.h"
#include <iostream>

void Add::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 2) {
		throw stack_error("At least two elements on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("Addition doesn't need arguments");
	}
	else {
		double arg1 = context.pop();
		double arg2 = context.pop();
		double sum = arg1 + arg2;
		context.push(sum);
	}
}


void Subtract::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 2) {
		throw stack_error("At least two elements on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("Subtraction doesn't need arguments");
	}
	else {
		double arg1 = context.pop();
		double arg2 = context.pop();
		double diff = arg1 - arg2;
		context.push(diff);
	}
}

void Multiply::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 2) {
		throw stack_error("At least two elements on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("Multiplication doesn't need arguments");
	}
	else {
		double arg1 = context.pop();
		double arg2 = context.pop();
		double product = arg1 * arg2;
		context.push(product);
	}
}

void Divide::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 2) {
		throw stack_error("At least two elements on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("Division doesn't need arguments");
	}
	else {
		double arg1 = context.peek();
		double arg2 = context.peek();
		if (arg2 == 0) {
			throw arithmetic_error("Can't divide by 0");
		}
		else {
			double quotient = arg1 / arg2;
			double arg1 = context.pop();
			double arg2 = context.pop();
			context.push(quotient);
		}
	}
}

void Sqrt::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 1) {
		throw stack_error("At least one element on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("SQRT doesn't need arguments");
	}
	else {
		double arg = context.peek();
		if (arg < 0) {
			throw arithmetic_error("Can't take sqrt of a negative number");
		}
		else {
			arg = sqrt(arg);
			context.pop();
			context.push(arg);
		}
	}
}

void Push::execute(const std::list<std::string>& args, Context& context) {
	if (args.size() != 1) {
		throw arguments_error("One argument required");
	}
	else {
		char ch = args.begin()->data()[0];
		double newNumber;
		// push const argument
		if ((ch >= '0' && ch <= '9') || (ch == '-')) {
			newNumber = std::stod(args.begin()->data());
		}
		//push variable
		else {
			std::string varName = args.begin()->data();
			newNumber = context.getVar(varName);
		}
		context.push(newNumber);
	}
}

void Pop::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 1) {
		throw stack_error("At least one element on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("POP doesn't need arguments");
	}
	else {
		context.pop();
	}
}

void Print::execute(const std::list<std::string>& args, Context& context) {
	if (context.stackSize() < 1) {
		throw stack_error("At least one element on the stack required");
	}
	if (args.size() != 0) {
		throw arguments_error("PRINT doesn't need arguments");
	}
	else {
		double arg = context.peek();
		std::cout << arg << std::endl;
	}
}

void Define::execute(const std::list<std::string>& args, Context& context) {
	if (args.size() != 2) {
		throw arguments_error("Define needs two arguments");
	}
	else {
		auto it = args.begin();
		std::string newName = *it;
		double newVar = std::stod(*(++it));
		context.pushVar(newVar, newName);
	}
}

void Comment::execute(const std::list<std::string>& args, Context& context) {
	
}
