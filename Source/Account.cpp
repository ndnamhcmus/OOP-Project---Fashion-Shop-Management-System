#include "Account.h"

#include <FakeName.h>
#include <FakeAddress.h>
#include <FakeBirthday.h>
#include <FakeVnTel.h>

Account::Account(string account_id, Customer customer, MembershipLevel membership_level)
{
	_account_id = account_id;
	
	_customer = customer;

	_membership_level = membership_level;
}

void Account::addBill(Bill bill)
{
	_bills.push_back(bill);
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
	if (search_by == "cancel")
	{
		throw exception("Cancel!!!");
	}
	for (int i = 0; i < accounts.size(); i++)
		if (accounts[i]._account_id == search_by)
			return accounts[i];

	throw exception("Account not found");
}

void Account::setAccountInfo(vector<string>Tok)
{
	_account_id = Tok[0];

	vector<string>tokens = Tokenizer::parse(Tok[2], "/");

	if (tokens.size() != 3)
	{
		throw exception("Invalid, try again!!!");
	}
	Date d(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]));

	tokens.clear();

	tokens = Tokenizer::parse(Tok[4], "-");
	if (tokens.size() != 5)
	{
		throw exception("Invalid, try again!!!");
	}
	Address ad(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);

	if (Tok[3][0] != '0')
	{
		Tok[3].insert(0, "0");
	}
	_customer = Customer(Tok[1], d, Tok[3], ad, Tok[5]);

	_bills.resize(0);

	_membership_level.setCumulativePoints(stoi(Tok[6]));

	_membership_level.setLevel(Tok[7]);
}

string Account::getLastCustomerID(vector <Account> accounts)
{
	return accounts[accounts.size() - 1]._customer.getCustomerID();
}

string Account::getLastAccountID(vector <Account> accounts)
{
	return accounts[accounts.size() - 1]._account_id;
}

void Account::addAccountToFile(Account account)
{
	vector<Account> acc;

	Account::openAccountList(acc);

	acc.push_back(account);

	ExcelFstream file;
	file.open("Account.csv", ios::app);

	file.writeExcelString(account.toString());

	file.close();
}

void Account::deleteAccountInFile(string account_id)
{
	vector<Account> acc;

	Account::openAccountList(acc);

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

vector<Bill> Account::getBillListFromFile(string bill_id)
{
	vector<Bill> bills;

	Bill::openBillList(bills);

	for (int i = 0; i < bills.size(); i++) {
		if (bills[i].getID() != bill_id) {
			bills.erase(bills.begin() + i);
		}
	}

	return bills;
}

string Account::getID()
{
	return _account_id;
}

string Account::getMembershipLevel()
{
	return _membership_level.getLevel();
}

MembershipLevel Account::getMemberShip()
{
	return _membership_level;
}

void Account::setMemberShip(MembershipLevel membership)
{
	_membership_level = membership;
}

double Account::getDiscount()
{
	return _membership_level.getDiscount(_membership_level.getLevel());
}

Account Account::sign_in(vector<Account> accounts, string account_id)
{
	if (account_id == "cancel")
	{
		throw exception("Cancel!!!");
	}


	bool is_found = false;
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]._account_id == account_id) {
			is_found = true;
			accounts[i].showAccountInfo();
			return accounts[i];
		}
	}


	if (!is_found)
	{
		throw AccountException("Account is not found");
	}
}

Account Account::sign_up(vector<Account>&accounts)
{
	vector<string> st;
	string s;

	st.push_back(to_string(stoi(getLastAccountID(accounts)) + 1));

	cout << "Full Name: ";
	getline(cin, s);
	if (s == "cancel")
	{
		throw exception("Cancel!!!");
	}
	st.push_back(s);

	cout << "Date of birth (Form: DD/MM/YYYY): ";
	getline(cin, s);
	if (s == "cancel")
	{
		throw exception("Cancel!!!");
	}
	st.push_back(s);

	cout << "Phone number: ";
	getline(cin, s);
	if (s == "cancel")
	{
		throw exception("Cancel!!!");
	}
	st.push_back(s);

	cout << "Address (Form: Number-Street-Ward-District-City): ";
	getline(cin, s);
	if (s == "cancel")
	{
		throw exception("Cancel!!!");
	}
	st.push_back(s);


	/*/// <summary>
	///		Fake test		///
	/// </summary>
	st.push_back(string(FakeName::next()));

	st.push_back(FakeBirthday::next().toString());

	FakeVnTel tel;
	st.push_back(tel.toString());

	st.push_back(FakeHCMAddress::next().toString());
	/// <summary>
	///		Fake test		///
	/// </summary>*/

	st.push_back(to_string(stoi(getLastCustomerID(accounts)) + 1));

	st.push_back("0");

	st.push_back("none");  //membership level


	if (st.size() != 8)
	{
		throw exception("Invalid, try again!!!");
	}
	this->setAccountInfo(st);

	accounts.push_back(*this);

	return *this;
}

void Account::showBillList()
{
	for (int i = 0; i < _bills.size(); i++) {
		_bills[i].setMembershipLevel(getMembershipLevel());
		_bills[i].showBillInfo();
		cout << endl;
	}
}

void Account::showAccountInfo()
{
	cout << "Account ID: " << _account_id << endl;

	cout << "Name\tCustomer ID\tDate of Birth\tPhone Number\tAddress\n\n";
	cout << _customer.toString() << endl;

	cout << "Number of bill: " << _bills.size() << endl;

	cout << "Level: " << _membership_level.getLevel() << endl;
}

void Account::openAccountList(vector <Account>& accounts, string directory)
{
	ExcelFstream file;
	file.open(directory, ios::in);

	vector <vector <string>> container;
	file.readExcelString(container);

	for (int i = 0; i < container.size(); i++)
	{
		Account acc;
		try
		{
			acc.setAccountInfo(container[i]);
		}
		catch (const std::exception&)
		{
			throw exception("Something happened while Account was setting up information");
		}
		
		accounts.push_back(acc);
	}

	file.close();


	if (!(accounts.size()))
	{
		throw exception("Account list is empty");
	}
}

void Account::saveAccountList(vector<Account>accounts, string directory)
{
	string buffer;
	ExcelFstream file;
	file.open(directory, ios::out);

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

string Account::toString()
{
	stringstream w;

	w << _account_id << " - " << _customer.getName() << " - " << _customer.getDoB().toString()
		<< " - " << _customer.getPhoneNumber() << " - " << _customer.getAddress().toString() << " - "
		<< _customer.getCustomerID() << " - " << to_string(_membership_level.getCummulativePoints()) << " - " << _membership_level.getLevel();

	return w.str();
}
