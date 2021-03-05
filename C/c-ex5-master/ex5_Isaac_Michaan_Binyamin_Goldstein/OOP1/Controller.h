#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class Controller
{
private:
	std::vector<std::shared_ptr<Shape>> v;
public:
	Controller();
	~Controller();
	void run();
};

