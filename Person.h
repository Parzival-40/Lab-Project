#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Account.h"

using namespace std;

//////////////////////////////////
//								//		
//	A person with no privacy	//
//								//
//////////////////////////////////


class Person{
public:
	Person(int id, string name, int age, string address);
	Person() = default;

	void print();
	void setacc(Account*);
	
	static vector<Person*> people;
	static Person* find(const int&);
	static void add();
	static void display();
	static void write();
	static void read();

protected:
	int id;
	string name;
	int age;
	string address;
	Account* acc;
};
