#include "FakeVnTel.h"

void FakeVnTel::generateRandomHeader(string& telephone_number)
{
	Random rng;
	telephone_number = _header_list[rng.next(0, 29)];
}

FakeVnTel::FakeVnTel(string telephone_number)
{
	if (telephone_number == "")
	{
		generateRandomPhoneNumber(telephone_number);
	}
	_telephone_number = telephone_number;
}

void FakeVnTel::generateRandomPhoneNumber(string& telephone_number)
{
	generateRandomHeader(telephone_number);


	Random rng;
	stringstream writer;
	writer << telephone_number;


	while (writer.str().size() < 10)
	{
		writer << to_string(rng.next(0, 9));
	}
	telephone_number = writer.str();
}

string FakeVnTel::toString()
{
	return this->_telephone_number;
}

FakeVnTel::operator string()
{
	return toString();
}