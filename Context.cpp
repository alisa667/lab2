#include "Context.h"
#include "exceptions.h"

int Context::stackSize() {
	return stk.size();
}

void Context::push(double& elem) {
	stk.push(elem);
}

void Context::pushVar(double& elem, std::string& name) {
	vars[name] = elem;
}

double Context::pop() {
	double top_elem = stk.top();
	stk.pop();
	return top_elem;
}

double Context::peek() {
	return (stk.top());
}

double Context::getVar(std::string& name) {
	auto search = vars.find(name);
	if (search == vars.end())
		throw variable_error("No variable with such name");
	else
		return search->second;
}