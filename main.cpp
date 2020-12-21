#include <iostream>
#include <list>
#include <fstream>

#include "Calculator.h"

int main(int argc, char* argv[]){
	Calculator calculator;
	if (argc == 1) {
		calculator.calculate(std::cin);
	}
	else {
		std::ifstream file;
		file.open(argv[1]);
		std::istream& stream = file;
		calculator.calculate(stream);
		file.open(argv[1]);
	}
}

