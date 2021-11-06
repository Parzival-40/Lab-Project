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
	Bus::buses.push_back(new Bus(lisc, Station::find(fs), Station::find(ts)));
}

void Bus::display(){
	for(auto& i : Bus::buses){
		cout << "liscense no: " << i->lisc_no << endl;
		cout << "From Station: "; i->from->display();
		cout << "To Station: "; i->to->display();
	}
}

void Bus::write(){
	ofstream fout("bus.dat", ios::trunc | ios::binary);
	if(!fout){
		return;
	}
	for(auto& i : Bus::buses){
		fout.write((char*) (i), sizeof(Bus));
	}
}

void Bus::read(){
	if(!Bus::buses.empty()){
		Bus::buses.clear();
		Bus::buses.resize(0);
	}
	ifstream fin("bus.dat", ios::binary);
	if(!fin){
		return;
	}
	while(!fin.eof()){
		Bus* temp = nullptr;
		fin.read((char*) temp, sizeof(Bus));
		Bus::buses.push_back(temp);
	}
}