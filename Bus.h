#pragma once
#include "Station.h"
#include <iostream>
#include <vector>

using namespace std;

//////////////////////////////////
///								//
/// A bus having a license no.	//
/// drives from one station to	//
/// another on a regular basis	//
///								//
//////////////////////////////////

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
