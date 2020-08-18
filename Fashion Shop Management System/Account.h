#ifndef _ACCOUNT_
#define _ACCOUNT_


#include <iostream>
#include <string>
#include <vector>
#include "Bill.h"
#include "Person_Customer_Staff_Seller_Security.h"
#include "MembershipLevel.h"

using namespace std;

class Account
{
private:

	string _account_id;
	Customer _customer;
	vector <Bill> _bills;
	MembershipLevel _membership_level;

public:
	Account();
	~Account();





	friend class ExcelFstream;

	friend ofstream& operator<<(ofstream& file_out, const Account& account);

	friend ifstream& operator>>(ifstream& file_out, Account& account);
};


#endif // !_ACCOUNT_