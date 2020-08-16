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
	FakeEmailDomain();	


	string getDomain();
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