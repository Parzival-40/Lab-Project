#pragma once
#include "Station.h"
#include "Bus.h"
#include "Person.h"
#include "Ticket.h"
class Passenger:Person{
public:
	Passenger(Station* from, Station* to);
	Passenger() = default;
	void issueTicket(Bus*, Station*, Station*);
private:
	Station* from;
	Station* to;
	Ticket* hisTicket;
};
