#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Person{
public:
	Person(int id, string name, int age, string address);
	Person() = default;
	friend ostream& operator <<(ostream& out, const Person& obj);
	static vector<Person*> people;
	static void add();
	static void display();
	static void write();
	static void read();
protected:
	int id;
	string name;
	int age;
	string address;
};
