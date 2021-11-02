#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
using namespace std;
class Account{
public:
	Account(Person* account_holder, int accno);
	Account() = default;
	void withdraw(int b);
	void add_money(int b);
	friend ostream& operator <<(ostream& out, const Account& obj);
	static vector<Account*> accounts;
	static void add();
	static void display();
	static void write();
	static void read();
private:
	Person* account_holder;
	int account_no;
	int balance;
};
