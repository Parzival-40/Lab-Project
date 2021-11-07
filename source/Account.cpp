#include "Account.h"

vector<Account*> Account::accounts;

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
	Person* temp = nullptr;
	try{
		temp=Person::find(id);
	} catch(const string& e){
		cout << e << endl;
		return;
	}
	Account::accounts.push_back(new Account(temp, accno));
}

void Account::display(){
	for(auto& i : Account::accounts){
		cout << "Account holder info: " << endl;
		i->account_holder->print();
	}
}

void Account::write(){
	ofstream fout("acc.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Account database write error!!!";
	}
	for(auto& i : Account::accounts){
		fout.write((char*) i, sizeof(Account));
	}
	fout.close();
}

void Account::read(){
	if(!Account::accounts.empty()){
		Account::accounts.clear();
	}
	ifstream fin("acc.dat", ios::binary);
	if(!fin){
		throw "Acount database write error!!!";
	}
	while(!fin.eof()){
		Account temp;
		fin.read((char*) &temp, sizeof(Account));
		Account::accounts.push_back(&temp);
	}
	fin.close();
}
