#pragma once
#include <iostream>
using namespace std;
class Person{
public:
	Person(int id, string name, int age, string address);
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
