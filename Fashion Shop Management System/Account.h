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
	Account(string account_id = "", MembershipLevel membership_level = MembershipLevel(), Customer customer = Customer());
	~Account();






	friend class ExcelFstream;

	friend class ExcelIfstream;

	friend class ExcelOfstream;
};


#endif // !_ACCOUNT_