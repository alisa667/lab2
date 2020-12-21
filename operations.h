#pragma once
#include "Operation.h"

class Add : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Subtract : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Multiply : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Divide : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Sqrt : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Push : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Pop : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Print : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Define : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

class Comment : public Operation {
	void execute(const std::list<std::string>& args, Context& context) override;
};

