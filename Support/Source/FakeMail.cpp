#include "FakeMail.h"

FakeEmailDomain::FakeEmailDomain(string domain)
{
	if (domain == "")
	{
		generateRandomDomain(domain);
	}
	this->_domain = domain;
}

string FakeEmailDomain::getDomain()
{
	return this->_domain;
}

void FakeEmailDomain::generateRandomDomain(string& domain)
{
	Random rng;
	domain = _domain_list[rng.next(0, 9)];
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


	stringstream writer;
	writer << _fake_email << "@" << domain.getDomain();
	_fake_email = writer.str();
}

string FakeEmail::getFakeEmail()
{
	return this->_fake_email;
}