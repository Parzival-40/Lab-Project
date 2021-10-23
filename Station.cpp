#include "Station.h"

Station::Station(string name):name(name){
	dist = count++;
}

int Station::get_fare(Station* from, Station* to){
	return abs(from->dist - to->dist) * 120;
}

Station* Station::find(string name){
	for(auto& i : stations){
		if(name == i->name)return i;
	}
	return nullptr;
}

void Station::add(){
	//TODO
	//complete in accordance to bus class
}

void Station::display(){
	//TODO
	//complete in accordance to bus class
}

void Station::write(){
	//TODO
	//complete in accordance to bus class
}

void Station::read(){
	//TODO
	//complete in accordance to bus class
}