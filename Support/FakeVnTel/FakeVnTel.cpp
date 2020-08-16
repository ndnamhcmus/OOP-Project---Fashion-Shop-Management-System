#include "FakeVnTel.h"

FakeVnTel::FakeVnTel()
{
	ifstream file;
	string string_temp;
	long number_of_items;
	long temp;


	file.open("fake_tels.txt", ios::in);


	while (_tel.size() < 10)
	{
		//		dịch về cuối file để tính tổng byte của file text
		file.seekg(0L, ios::end);
		number_of_items = file.tellg();
		number_of_items = (number_of_items - 3L);	//	lùi lại 3 byte để ở đầu dòng


		//		tổng số điện thoại trong file text
		file.seekg(0L, ios::beg);
		getline(file, string_temp);
		temp = file.tellg();
		number_of_items = number_of_items / temp;


		//		phát sinh ngẫu nhiên 
		long random_number = rand() % (number_of_items - 0 + 1);
		file.seekg(random_number * temp, ios::beg);


		getline(file, string_temp);
		this->_tel = this->_tel + string_temp;
	}
	while (_tel.size() > 10)
	{
		this->_tel.erase(_tel.size() - 1);
	}
	


	file.close();
}

string FakeVnTel::getVnTel()
{
	return this->_tel;
}