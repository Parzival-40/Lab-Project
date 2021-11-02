#pragma once
#include "Person.h"
#include "Bus.h"
class Driver:Person{
public:
	Driver() = default;
private:
	int driving_lisc_no;
	Bus* driving;
};
