#include "Bus.h"

Bus::Bus(int lisc_no, Station* from, Station* to)
	:lisc_no(lisc_no), from(from), to(to){}

void Bus::add(){
	int lisc;
	string fs;
	string ts;
	cout << "liscense no: "; cin >> lisc;
	cout << "From Station: "; cin >> fs;
	cout << "To Station: "; cin >> ts;
	buses.push_back(new Bus(lisc, Station::find(fs), Station::find(ts)));
}

void Bus::display(){
	cout << "liscense no: " << lisc_no << endl
		<< "From Station: " << from->display() << endl
		<< "To Station: " << to->display() << endl;
}

void Bus::write(){
	ofstream fout("bus.dat", ios::trunc | ios::binary);
	if(!fout){
		return;
	}
	for(auto& i : buses){
		fout.write((char*) (*i), sizeof(Bus));
	}
}

void Bus::read(){
	if(!buses.empty()){
		buses.clear();
		buses.resize(0);
	}
	ifstream fin("bus.dat", ios::binary);
	if(!fin){
		return;
	}
	while(!fin.eof()){
		Bus* temp = nullptr;
		fin.read((char*) temp, sizeof(Bus));
		buses.push_back(temp);
	}
}