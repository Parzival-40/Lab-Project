#pragma once
#include "Station.h"
#include <iostream>
#include <vector>
using namespace std;
class Bus{
public:
	Bus(int lisc_no, Station* from, Station* to);
	Bus() = default;
	static vector<Bus*> buses;
	static void add();
	static void display();
	static void write();
	static void read();
private:
	int lisc_no;
	Station* from;
	Station* to;
};
