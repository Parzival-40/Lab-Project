#include "Ticket.h"

Ticket::Ticket(Bus* bus, Station* from, Station* to, Passenger* holder)
	:bus(bus), from(from), to(to), holder(holder){
	fare = Station::get_fare(from, to);
}