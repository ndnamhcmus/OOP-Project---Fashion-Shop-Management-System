#include "Account.h"


Account::Account(string account_id, Customer customer, MembershipLevel membership_level)
{
	_account_id = account_id;
	_membership_level = membership_level;
	_customer = customer;
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
	this->_account_id = Tok[0];
	//this->_customer = ...Tok[1];
	//this->_bills = ... Tok[2];
	this->_membership_level = Tok[3];
}

string Account::findLastAccount_ID_InFile()
{

	return string();
}

void Account::addAccountToFile(Account account)
{
	
}

void Account::deleteAccountInFile(string account_id)
{

}

void Account::modifyAccountInFile(string account_id)
{

}

vector<Bill> Account::getBillListFromFile(string account_id)
{

	return vector<Bill>();
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

void Account::sign_up(vector<Account>&accounts)
{
	vector<string> st;
	string s;

	cout << "Full Name: ";
	getline(cin, s);
	st.push_back(s);

	cout << "Date of birth: ";
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

	//còn id của customer với id của account

	Account account(/*truyền vào mấy cái lấy được*/);

	//accounts.push_back(account);
}

void Account::showBillList()
{
	for (int i = 0; i < _bills.size(); i++) {
		cout << i + 1<<endl; 
		_bills[i].showBillInfo();
	}
}

void Account::showAccountInfo()
{

}

Account Account::saveAccount()
{

	return Account();
}

string Account::deleteAccount()
{

	return string();
}

string Account::modifyAccount()
{

	return string();
}
