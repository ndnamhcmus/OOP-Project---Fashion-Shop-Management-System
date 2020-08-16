#ifndef _FAKE_EMAIL_
#define _FAKE_EMAIL_


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <FakeName.h>
#include <Tokenizer.h>

using namespace std;

class FakeEmailDomain
{
private:
	string _domain;
public:
	FakeEmailDomain(const string& domain = "");	

	string getDomain();

	void readFile();
};


class FakeEmail
{
private:
	FakeEmailDomain domain;
	string _fake_email;
public:
	FakeEmail();

	string getFakeEmail();
};


#endif // !_FAKE_EMAIL_