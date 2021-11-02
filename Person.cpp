#include "Person.h"

Person::Person(int id, string name, int age, string address)
	:id(id)
	, name(name)
	, age(age)
	, address(address){}

void Person::add(){
	int id;
	string name;
	int age;
	string address;
	cout << "ID: "; cin >> id;
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "Address: "; cin >> address;
	people.push_back(new Person(id, name, age, address));
}

void Person::display(){
	for(auto& i : people){
		cout << "ID: "<<i->id<<endl;
		cout << "Name: "<<i->name<<endl;
		cout << "Age: "<<i->age<<endl;
		cout << "Address: "<< i->address<<endl;
	}
}

void Person::write(){
	ofstream fout("ppl.dat", ios::trunc | ios::binary);
	if(!fout){
		return;
	}
	for(auto& i : people){
		fout.write((char*) (i), sizeof(Person));
	}
}

void Person::read(){
	if(!people.empty()){
		people.clear();
		people.resize(0);
	}
	ifstream fin("ppl.dat", ios::binary);
	if(!fin){
		return;
	}
	while(!fin.eof()){
		Person* temp = nullptr;
		fin.read((char*) temp, sizeof(Person));
		people.push_back(temp);
	}
}

ostream& operator<<(ostream& out, const Person& obj){
	out << obj.name << "		" << obj.id << "		" << obj.age << "		" << obj.address << endl;
	return out;
}