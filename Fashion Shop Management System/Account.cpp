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

void Account::setAccountInfo()
{

}

string Account::findLastAccount_ID_InFile()
{

	return string();
}

void Account::addAccountToFile(Account account)
{
	/*readFile;
	vector <Account> accounts;
	for (size_t i = 0; i < length; i++)
	{
		accounts.push_back(readFile);
	}


	sign_up;
	accounts.push_back(sign_up);
	for (size_t i = 0; i < length; i++)
	{
		writeFile(vector);
	}*/
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

void Account::sign_up()
{

}

void Account::showBillList()
{

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
