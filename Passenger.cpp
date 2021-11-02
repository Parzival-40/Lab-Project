#include "Passenger.h"

Passenger::Passenger(Person* ref)
	:Passenger::Person(*ref){}

Passenger::~Passenger(){
	delete(hisTicket);
}

void Passenger::issueTicket(Bus* bus, Station* from, Station* to){
	hisTicket = new Ticket(bus, from, to);
	try{
		acc->withdraw(hisTicket->getFare());

	} catch(const string& e){
		cout << e << endl;
	}
}
