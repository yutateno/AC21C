#pragma once
#include <memory>


class Manager
{
public:
	Manager();
	~Manager();


	void init();
	void ctrl();
	void disp();
	void dest();

private:
	struct Impl;
	std::unique_ptr<Impl> impl;
};

