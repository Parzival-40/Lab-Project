#include "Station.h"

int Station::count = 0;
vector<Station*> Station::stations;

Station::Station(string name):name(name){
	dist = Station::count++;
}

void Station::print(){
	cout << "Name: " << name << endl;
}

int Station::get_fare(Station* from, Station* to){
	return abs(from->dist - to->dist) * 120;
}

Station* Station::find(string name){
	for(auto& i : Station::stations){
		if(name == i->name)return i;
	}
	throw "no station named " + name;
}

void Station::add(){
	string name;
	cout << "Station Name: "; cin >> name;
	Station::stations.push_back(new Station(name));
}

void Station::display(){
	for(auto& i : Station::stations){
		cout << "Name: " << i->name << endl;
	}
}

void Station::write(){
	ofstream fout("station.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Station database write error!!!";
	}
	for(auto& i : Station::stations){
		fout.write((char*)i, sizeof(Station));
	}
}

void Station::read(){
	if(!Station::stations.empty()){
		Station::stations.clear();
	}
	ifstream fin("station.dat", ios::binary);
	if(!fin){
		throw "Station database read error!!!";
	}
	while(!fin.eof()){
		Station temp;
		fin.read((char*)&temp, sizeof(Station));
		Station::stations.push_back(&temp);
	}
}