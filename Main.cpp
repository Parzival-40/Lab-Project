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

using namespace std;

enum class type{
	Account, Bus, Person, Station, Driver, Ticket, Passenger
};

void reg(type t){
	cout << "1.. add a bus to the database." << endl
		<< "2.. read data from the database." << endl
		<< "3.. write data to the database." << endl
		<< "4.. view data from the database." << endl;
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
				case default:
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
				case default:
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
				case default:
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
				case default:
					break;
			}
			break;
	}
}

int main(){
	cout << "1.. for Account" << endl
		<< "2.. for Bus" << endl
		<< "3.. for Person" << endl
		<< "4.. for Station" << endl;
	int c;
	cin >> c;
	switch(c){
		case 1:
			reg(type::Account);
			break;
		case 2:
			reg(type::Bus);
			break;
		case 3:
			reg(type::Person);
			break;
		case 4:
			reg(type::Station);
			break;
		default:
			break;
	}
}