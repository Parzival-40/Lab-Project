#include "Account.h"

Account::Account(Person* account_holder, int accno)
	:account_holder(account_holder)
	, account_no(accno)
	, balance(0) {
	account_holder->setacc(this);
	min_bal = 100;
}

void Account::withdraw(int b){
	if(b + min_bal <= balance){
		throw("Not enough balance");
	}
	
	balance -= b;
	cout << "Ticket Confirmed" << endl;
	
}

void Account::add_money(int b){
	if(b < 0)return;
	balance += b;
}

void Account::set_min_bal(int b){
	min_bal = b;
}

void Account::add(){
	int id;
	int accno;
	cout << "ID: "; cin >> id;
	cout << "Account No.: "; cin >> accno;
	accounts.push_back(new Account(Person::find(id), accno));
}

void Account::display(){
	for(auto& i : accounts){
		cout << "Account holder info: " << endl;
		i->account_holder->print();
	}
}

void Account::write(){
	ofstream fout("acc.dat", ios::trunc | ios::binary);
	if(!fout){
		return;
	}
	for(auto& i : accounts){
		fout.write((char*) (i), sizeof(Account));
	}
}

void Account::read(){
	if(!accounts.empty()){
		accounts.clear();
		accounts.resize(0);
	}
	ifstream fin("acc.dat", ios::binary);
	if(!fin){
		return;
	}
	while(!fin.eof()){
		Account* temp = nullptr;
		fin.read((char*) temp, sizeof(Account));
		accounts.push_back(temp);
	}
}
