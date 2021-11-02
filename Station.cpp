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
	string name;
	cout << "Station Name: "; cin >> name;
	stations.push_back(new Station(name));
}

void Station::display(){
	for(auto& i : stations){
		cout << "Name: " << i->name << endl;
	}
}

void Station::write(){
	ofstream fout("station.dat", ios::trunc | ios::binary);
	if(!fout){
		return;
	}
	for(auto& i : stations){
		fout.write((char*)(i), sizeof(Station));
	}
}

void Station::read(){
	if(!stations.empty()){
		stations.clear();
		stations.resize(0);
	}
	ifstream fin("station.dat", ios::binary);
	if(!fin){
		return;
	}
	while(!fin.eof()){
		Station* temp = nullptr;
		fin.read((char*)temp, sizeof(Station));
		stations.push_back(temp);
	}
}