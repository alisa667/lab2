#pragma once
#include <string>
#include <stdexcept>

class MyException {
private:
	std::string message;
public:
	MyException(std::string error) {
		message = error;
	}
	const char* what() {
		return message.c_str();
	}
};