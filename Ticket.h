#pragma once
#include "Bus.h"
#include "Passenger.h"
#include "Station.h"
class Ticket{
public:
	Ticket(Bus* bus, Station* from, Station* to);
	Ticket() = default;
private:
	Bus* bus;
	Station* from;
	Station* to;
	Passenger* holder;
	int fare;
};
