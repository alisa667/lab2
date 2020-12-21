#pragma once
#include "MyException.h"

class stack_error :public MyException {
public:
	stack_error(const std::string& message) : MyException(message) {};
};

class arguments_error :public MyException {
public:
	arguments_error(const std::string& message) : MyException(message) {};
};

class arithmetic_error :public MyException {
public:
	arithmetic_error(const std::string& message) : MyException(message) {};
};

class operation_error :public MyException {
public:
	operation_error(const std::string& message) : MyException(message) {};
};

class variable_error :public MyException {
public:
	variable_error(const std::string& message) : MyException(message) {};
};