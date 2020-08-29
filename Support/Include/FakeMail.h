#ifndef _FAKE_EMAIL_
#define _FAKE_EMAIL_


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <FakeName.h>
#include <Tokenizer.h>
#include <Random.h>

using namespace std;

class FakeEmailDomain
{
private:

	string _domain_list[10] = { "gmail.com", "microsoft.com", "apple.com", "amazom.com", "samsung.com", "instagram.com", "facebook.com", "yahoo.com", "youtube.com", "twitter.com" };

private:

	void generateRandomDomain(string& domain);

private:

	string _domain;

public:
	FakeEmailDomain(string domain = "");

	string getDomain();
};


class FakeEmail
{
private:

	FakeEmailDomain domain;
	string _fake_email;

public:

	FakeEmail();

public:

	string getFakeEmail();
};


#endif // !_FAKE_EMAIL_