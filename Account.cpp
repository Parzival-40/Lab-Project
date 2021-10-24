#include "Account.h"

Account::Account(Person* account_holder, int accno)
	:account_holder(account_holder)
	, account_no(accno){}

void Account::withdraw(int b){
	if(b + 100 <= balance){
		cout << "Can't Withdraw" << endl;
	} else{
		balance -= b;
		cout << "Ticket Confirmed" << endl;
	}
}

void Account::add_money(int b){
	if(b < 0)return;
	balance += b;
}

void Account::add(){
	//TODO
	//complete in accordance to bus class
}

void Account::display(){
	//TODO
	//complete in accordance to bus class
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

ostream& operator<<(ostream& out, const Account& obj){
	out << obj.account_no << "    " << obj.balance << endl;
	return out;
}