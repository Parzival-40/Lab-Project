#include "Person.h"

vector<Person*> Person::people;

Person::Person(int id, string name, int age, string address)
	:id(id)
	, name(name)
	, age(age)
	, address(address)
	, acc(nullptr){}

Person* Person::find(const int& checkid){
	for(auto& i : Person::people){
		if(i->id == checkid)return i;
	}
	throw "person with id: " + to_string(checkid) + " not found in person database!!!";
}

void Person::add(){
	int id;
	string name;
	int age;
	string address;
	cout << "ID: "; cin >> id;
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "Address: "; cin >> address;
	Person::people.push_back(new Person(id, name, age, address));
}

void Person::display(){
	for(auto& i : Person::people){
		i->print();
	}
}

void Person::write(){
	ofstream fout("ppl.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "People database write error!!!";
	}
	for(auto& i : Person::people){
		fout.write((char*) i, sizeof(Person));
	}
	fout.close();
}

void Person::read(){
	if(!Person::people.empty()){
		Person::people.clear();
	}
	ifstream fin("ppl.dat", ios::binary);
	if(!fin){
		throw "People database read error!!!";
	}
	while(!fin.eof()){
		Person temp ;
		fin.read((char*) &temp, sizeof(Person));
		Person::people.push_back(&temp);
	}
	fin.close();
}

void Person::print(){
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Address: " << address << endl;
}

void Person::setacc(Account* account){
	acc = account;
}
