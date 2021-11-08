#include <iostream>
#include <fstream>
#include <cstdlib>
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
		Person::read();
	} catch(const char* e){
		cout << e << endl;
	}
	try{
		Account::read();
	} catch(const char* e){
		cout << e << endl;
	}
	try{
		Station::read();
	} catch(const char* e){
		cout << e << endl;
	}
	try{
		Bus::read();
	} catch(const char* e){
		cout << e << endl;
	}
}
void commit(){
	try{
		Person::write();
	} catch(const char* e){
		cout << e << endl;
	}
	try{
		Account::write();
	} catch(const char* e){
		cout << e << endl;
	}
	try{
		Station::write();
	} catch(const char* e){
		cout << e << endl;
	}
	try{
		Bus::write();
	} catch(const char* e){
		cout << e << endl;
	}
}

void add(type t){
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
}
void read(type t){
	switch(t){
		case type::Account:
			try{
				Account::read();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		case type::Bus:
			try{
				Bus::read();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		case type::Person:
			try{
				Person::read();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		case type::Station:
			try{
				Station::read();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		default:
			break;
	}
}
void write(type t){
	switch(t){
		case type::Account:
			try{
				Account::write();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		case type::Bus:
			try{
				Bus::write();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		case type::Person:
			try{
				Person::write();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		case type::Station:
			try{
				Station::write();
			} catch(const string& e){
				cout << e << endl;
			}
			break;
		default:
			break;
	}
}
void display(type t){
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
}

void reg(type t){
	bool running = true;
	while(running){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "[1] add" << endl
			<< "[2] read" << endl
			<< "[3] write" << endl
			<< "[4] view" << endl
			<< "[0] close" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		
		int c;
		if(!(cin >> c)||c<0||c>4){
			cout << "Please enter a valid choice" << endl;
			cin.clear();
			cin.get();
		}
		system("cls");
		switch(c){
			case 0:
				running = false;
				break;
			case 1:
				add(t);
				break;
			case 2:
				read(t);
				break;
			case 3:
				write(t);
				break;
			case 4:
				display(t);
				break;
			default:
				break;
		}
		cout << "perss any key to continue...";
		cin.clear();
		cin.get();
		system("cls");
	}
}

int main(){

	init();

	bool running = true;

	while(running){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout<< "[1] Manage people information" << endl
			<< "[2] Manage account information" << endl
			<< "[3] Manage bus information" << endl
			<< "[4] Manage Station information" << endl
			<< "[0] exit" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;

		int c;
		if(!(cin >> c) || c < 0 || c>4){
			cout << "please enter a valid choice";
			cin.clear();
			cin.get();
		}
		system("cls");
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
	}

	 commit();

	cin.get();
}