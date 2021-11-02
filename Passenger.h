#pragma once
#include "Station.h"
#include "Bus.h"
#include "Person.h"
#include "Account.h"
#include "Ticket.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
//																		//
// A Passenger buys a ticket from a station to another station by bus	//
//																		//
//////////////////////////////////////////////////////////////////////////

class Passenger:Person{
public:
	Passenger(Person*);
	~Passenger();
	Passenger() = default;
	void issueTicket(Bus*, Station*, Station*);
private:
	Ticket* hisTicket;
};
