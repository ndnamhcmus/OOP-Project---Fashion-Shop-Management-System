#include <iostream>
#include <Clock.h>
#include <Date.h>
#include <FakeAddress.h>
#include <FakeBirthday.h>
#include <FakeMail.h>
#include <FakeName.h>
#include <FakeVnTel.h>
#include <MyTime.h>
#include <Tokenizer.h>

int main()
{
	srand(time(0));
	FakeVnTel tel;
	cout << tel.getVnTel();

}