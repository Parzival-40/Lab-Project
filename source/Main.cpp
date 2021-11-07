#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "Account.h"
#include "Bus.h"
#include "Person.h"
#include "Station.h"
#include "Driver.h"
#include "Ticket.h"
#include "Passenger.h"

enum class type{
	Account,
	Bus,
	Person,
	Station,
	Driver,
	Ticket,
	Passenger

};

void init(){
	try{
		Account::read();
		Bus::read();
		Person::read();
		Station::read();
	} catch(const string& e){
		cout << e << endl;
	}
}
void commit(){
	try{
		Account::write();
		Bus::write();
		Person::write();
		Station::write();
	} catch(const string& e){
		cout << e << endl;
	}
}
void reg(type t){
	cout << "[1] add" << endl
		<< "[2] read" << endl
		<< "[3] write" << endl
		<< "[4] view" << endl;
	int c;
	cin >> c;
	switch(c){
		case 1:
			switch(t){
				case type::Account:
					Account::add();
					break;
				case type::Bus:
					Bus::add();
					break;
				case type::Person:
					Person::add();
					break;
				case type::Station:
					Station::add();
					break;
				default:
					break;
			}
			break;
		case 2:
			switch(t){
				case type::Account:
					Account::read();
					break;
				case type::Bus:
					Bus::read();
					break;
				case type::Person:
					Person::read();
					break;
				case type::Station:
					Station::read();
					break;
				default:
					break;
			}
			break;
		case 3:
			switch(t){
				case type::Account:
					Account::write();
					break;
				case type::Bus:
					Bus::write();
					break;
				case type::Person:
					Person::write();
					break;
				case type::Station:
					Station::write();
					break;
				default:
					break;
			}
			break;
		case 4:
			switch(t){
				case type::Account:
					Account::display();
					break;
				case type::Bus:
					Bus::display();
					break;
				case type::Person:
					Person::display();
					break;
				case type::Station:
					Station::display();
					break;
				default:
					break;
			}
			break;
	}
}

int main(){

	//init();

	bool running = true;

	while(running){
		cout << "[1] Manage people information" << endl
			<< "[2] Manage account information" << endl
			<< "[3] Manage bus information" << endl
			<< "[4] Manage Station information" << endl
			<< "[0] exit" << endl;

		int c;
		cin >> c;
		try{
			switch(c){
				case 0:
					running = false;
					break;
				case 1:
					reg(type::Person);
					break;
				case 2:
					reg(type::Account);
					break;
				case 3:
					reg(type::Bus);
					break;
				case 4:
					reg(type::Station);
					break;
				default:
					break;
			}
		} catch(const string& e){
			cout << e << endl;
		}
	}

	 //commit();

	cin.get();
}