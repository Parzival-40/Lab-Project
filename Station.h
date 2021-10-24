#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Station{
public:
	Station(string name);
	static int get_fare(Station* from, Station* to);
	static int count;
	static Station* find(string name);
	static vector<Station*> stations;
	static void add();
	static void display();
	static void write();
	static void read();
private:
	string name;
	int dist;
};
