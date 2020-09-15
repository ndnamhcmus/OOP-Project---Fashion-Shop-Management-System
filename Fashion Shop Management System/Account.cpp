#include "Account.h"


Account::Account(string account_id, Customer customer, MembershipLevel membership_level)
{
	_account_id = account_id;
	
	_customer = customer;

	_membership_level = membership_level;
}

void Account::sort(vector<Account> accounts, string sort_by)
{
	if (sort_by == "id") {
		for (int i = 0; i < accounts.size() - 1; i++)
			for (int j = i + 1; j < accounts.size(); j++)
				if (stoi(accounts[i]._account_id) > stoi(accounts[j]._account_id)) 
						swap(accounts[i], accounts[j]);
		return;
	}
	else if (sort_by == "membership_level") {
		for (int i = 0; i < accounts.size() - 1; i++)
			for (int j = i + 1; j < accounts.size(); j++)
				if (accounts[i]._bills.size() > accounts[j]._bills.size())
					swap(accounts[i], accounts[j]);
		return;
	}

}

Account Account::search(vector<Account> accounts, string search_by)
{
		for (int i = 0; i < accounts.size(); i++)
			if (accounts[i]._account_id == search_by)
				return accounts[i];
}

void Account::setAccountInfo(vector<string>Tok)
{
	_account_id = Tok[0];

	vector<string>tokens = Tokenizer::parse(Tok[2], "/");

	Date d(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));

	tokens.clear();

	tokens = Tokenizer::parse(Tok[4], "-");

	Address ad(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);

	_customer = Customer(Tok[1], d, Tok[3], ad, Tok[5]);

	_bills.resize(0);

	_membership_level = Tok[6];
}

string Account::findLastAccount_ID_InFile()
{
	vector<Account> acc;

	Account::openAccountFile(acc);
	
	return acc[acc.size() - 1]._account_id;
}

void Account::addAccountToFile(Account account)
{
	vector<Account> acc;

	Account::openAccountFile(acc);

	acc.push_back(account);

	ExcelFstream file;
	file.open("Account.csv", ios::app);

	file.writeExcelString(account.toString());

	file.close();
}

void Account::deleteAccountInFile(string account_id)
{
	vector<Account> acc;

	Account::openAccountFile(acc);

	Account::deleteAccount(acc, account_id);

	ExcelFstream file;
	file.open("Account.csv", ios::out);

	for (auto& Account : acc) {
		file.writeExcelString(Account.toString());
	}
	file.close();
}

/*void Account::modifyAccountInFile(string account_id)
{

}*/

vector<Bill> Account::getBillListFromFile(string account_id)
{
	vector<Account> acc;

	Account::openAccountFile(acc);

	for (int i = 0; i < acc.size(); i++) {
		if (acc[i]._account_id == account_id) {

			return acc[i]._bills;

		}
	}
}

string Account::getAccount_ID()
{
	return _account_id;
}

string Account::getMemberShipLevel()
{
	return _membership_level.getLevel();
}

double Account::getDiscount()
{
	return _membership_level.getDiscount(_membership_level.getLevel());
}

void Account::sign_in(string account_id)
{
	vector<Account> acc;

	Account::openAccountFile(acc);

	for (int i = 0; i < acc.size(); i++) 

		if (acc[i]._account_id == account_id) {

			 acc[i].showAccountInfo();
		}
}

void Account::sign_up(vector<Account>&accounts)
{
	vector<string> st;
	string s;

	st.push_back(to_string(stoi(Account::findLastAccount_ID_InFile()) + 1));

	cout << "Full Name: ";
	getline(cin, s);
	st.push_back(s);

	cout << "Date of birth: ";
	getline(cin, s);
	st.push_back(s);

	cout << "Phone number: ";
	getline(cin, s);
	st.push_back(s);

	cout << "Address: ";
	getline(cin, s);
	st.push_back(s);

	st.push_back(to_string(stoi(_customer.getCustomerID()) + 1));

	st.push_back("0");  //membership level

	Account account;

	account.setAccountInfo(st);

	accounts.push_back(account);
}

void Account::showBillList()
{
	for (int i = 0; i < _bills.size(); i++) {
		cout << i + 1<<endl; 
		_bills[i].showBillInfo();
		cout << endl;
	}
}

void Account::showAccountInfo()
{
	cout << "Account ID: " << _account_id << endl;

	cout << _customer.toString() << endl;

	cout << "Number of bill: " << _bills.size() << endl;

	cout << _membership_level.getLevel() << endl;
}

void Account::saveAccountToFile(vector<Account>accounts)
{
	string buffer;
	ExcelFstream file;
	file.open("Account.csv", ios::out);

	for (int i = 0; i < accounts.size(); i++)
	{
		buffer = accounts[i].toString();
		file.writeExcelString(buffer);
	}

	file.close();
}

void Account::deleteAccount(vector<Account>&acc, string account_id)
{
	for (int i = 0; i < acc.size(); i++) 
		if (acc[i]._account_id == account_id) {
			acc.erase(acc.begin() + i);
			break;
		}
}

/*string Account::modifyAccount()
{

	return string();
}*/

void Account::openAccountFile(vector <Account>& accounts, string path)
{
	ExcelFstream file;
	file.open(path, ios::in);

	vector <vector <string>> container;
	file.readExcelString(container);

	for (int i = 0; i < container.size(); i++)
	{
		Account acc;
		acc.setAccountInfo(container[i]);
		accounts.push_back(acc);
	}

	file.close();
}

string Account::toString()
{
	stringstream w;

	w << _account_id << " - " << _customer.getName() << " - " << _customer.getDoB().toString()
		<< " - " << _customer.getPhoneNumber() << " - " << _customer.getAddress().toString() << " - "
		<< _customer.getCustomerID() << " - " << _membership_level.getLevel();

	return w.str();
}
