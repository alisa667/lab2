#pragma once
#include <stack>
#include <map>
#include <string>

class Context {
	std::stack <double> stk;
	std::map<std::string, double> vars;
public:
	int stackSize();
	void push(double& elem);
	void pushVar(double& elem, std::string& name);
	double pop();
	double peek();
	double getVar(std::string& name);
};