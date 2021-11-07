#include "Bus.h"

vector<Bus*> Bus::buses;

Bus::Bus(int lisc_no, Station* from, Station* to)
	:lisc_no(lisc_no), from(from), to(to){}

void Bus::print(){
	cout << "liscense no: " << lisc_no << endl;
	cout << "From Station: "; from->print();
	cout << "To Station: "; to->print();
}

void Bus::add(){
	int lisc;
	string fs;
	string ts;
	cout << "liscense no: "; cin >> lisc;
	cout << "From Station: "; cin >> fs;
	cout << "To Station: "; cin >> ts;
	Station* fss = nullptr;
	Station* tss = nullptr;
	try{
		fss = Station::find(fs);
		tss = Station::find(ts);
	} catch(const string& e){
		cout << e << endl;
		return;
	}
	Bus::buses.push_back(new Bus(lisc, fss, tss));

}

void Bus::display(){
	for(auto& i : Bus::buses){
		i->print();
	}
}

void Bus::write(){
	ofstream fout("bus.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Bus database write error!!!";
	}
	for(auto& i : Bus::buses){
		fout.write((char*) i, sizeof(Bus));
	}
	fout.close();
}

void Bus::read(){
	if(!Bus::buses.empty()){
		Bus::buses.clear();
	}
	ifstream fin("bus.dat", ios::binary);
	if(!fin){
		throw "Bus database read error!!!";
	}
	while(!fin.eof()){
		Bus temp;
		fin.read((char*) &temp, sizeof(Bus));
		Bus::buses.push_back(&temp);
	}
	fin.close();
}