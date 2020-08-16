#include "FakeMail.h"

FakeEmailDomain::FakeEmailDomain()
{
	ifstream file;
	file.open("FakeEmailDomains.txt", ios::in);
	if (!file)
	{
		cout << "Fail\n";
	}
	else
	{
		int random_number = rand() % (10 + 1);
		int idx = 0;
		while (idx <= random_number)
		{
			getline(file, this->_domain);
			++idx;
		}
	}
}

string FakeEmailDomain::getDomain()
{
	return this->_domain;
}

FakeEmail::FakeEmail()
{
	string name;
	name = FakeName::next().FullName_to_string();


	vector <string> temp = Tokenizer::parse(name, " ");


	for (int i = 0; i < temp.size(); i++)
	{
		if (i == temp.size() - 1)
		{
			_fake_email = _fake_email + temp[i];
		}
		else
		{
			_fake_email = _fake_email + temp[i][0];
		}
	}
	

	for (int i = 0; i < _fake_email.length(); i++)
	{
		_fake_email[i] = tolower(_fake_email[i]);
	}


	_fake_email = _fake_email + "@" + domain.getDomain();
}

string FakeEmail::getFakeEmail()
{
	return this->_fake_email;
}