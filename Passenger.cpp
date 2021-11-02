#include "Passenger.h"

Passenger::Passenger(Station* from, Station* to)
	:from(from)
	,to(to){}

void Passenger::issueTicket(Bus* bus, Station* from, Station* to){
	hisTicket = new Ticket(bus, from, to);
}
