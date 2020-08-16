#include "FakeAddress.h"

////	Fake house number	////
string FakeHouseNumber::generateRandomHouseNumber()
{
	string house_number;
	stringstream writer;
	int rand_num;
	int n = 1 + rand() % (3 - 1 + 1);


	//	Generate random number
	for (int i = 0; i < n; i++)
	{
		rand_num = 1 + rand() % (99 - 1 + 1);

		writer << to_string(rand_num);
	}

	house_number = writer.str();

	if (house_number.size() > 2)
	{
		// Generate random "/"
		/*n = 2 + rand() % (_number.size() - 1 - 2 + 1);
		for (int i = 0; i < n; i++)
		{
			if (i % 2 && i != _number.size() - 2)
			{
				_number.insert(i + 1, "/");
			}
		}*/


		int n = (house_number.size() / 2) - 1;
		int number_of_slash = 1 + rand() % (n - 0 + 1);
		int rand_pos = 1 + rand() % (house_number.size() - 2 - 1 + 1);
		int count = 0;


		/// <summary>
		/// Thêm dấu "/"
		/// </summary>
		for (int i = 0; i < number_of_slash; ++i)
		{
			house_number.insert(rand_pos, "/");
			rand_pos = 1 + rand() % (house_number.size() - 2 - 1 + 1);
		}


		/// <summary>
		/// Kiểm tra "/" kế nhau
		/// </summary>

		for (int i = 0; i < house_number.size(); i++)
		{
			int i_idx = 0, j_idx = 0;
			for (int i_idx = 0; i_idx < house_number.size() - 1; i_idx++)
			{
				for (int j_idx = i_idx + 1; j_idx < house_number.size(); j_idx++)
				{
					if (house_number[i_idx] == house_number[j_idx])
					{
						while (house_number[i_idx] == house_number[j_idx] && house_number[i_idx] == '/')
						{
							rand_pos = 1 + rand() % (house_number.size() - 2 - 1 + 1);
							swap(house_number[i_idx], house_number[rand_pos]);
						}
					}
					break;
				}
			}
		}
	}
	return house_number;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Address::Address()
{
	ifstream file_in;

	////	Street file
	file_in.open("street.txt", ios::in);
	int rand_num = 1 + rand() % (25 - 1 + 1);
	int i = 0;
	while (i < rand_num)
	{
		getline(file_in, this->_street);
		i++;
	}
	file_in.close();
	

	////	Ward file
	file_in.open("ward.txt", ios::in);
	rand_num = 1 + rand() % (40 - 1 + 1);
	i = 0;
	while (i < rand_num)
	{
		getline(file_in, this->_ward);
		i++;
	}
	file_in.close();


	////	District file
	file_in.open("district.txt", ios::in);
	rand_num = 1 + rand() % (6 - 1 + 1);
	i = 0;
	while (i < rand_num)
	{
		getline(file_in, this->_district);
		i++;
	}
	file_in.close();


	////	City
	this->_city = "Ho Chi Minh city";
}

string Address::get_Number()
{
	return this->_number;
}

string Address::get_Street()
{
	return _street;
}

string Address::get_Ward()
{
	return _ward;
}

string Address::get_District()
{
	return _district;
}

string Address::get_City()
{
	return _city;
}

string Address::Address_to_string()
{
	stringstream writer;
	//writer << _number.FakeHouseNumber_to_string() << " " << _street << ", " << _ward << ", " << _district << ", " << _city;
	writer << FakeHouseNumber::generateRandomHouseNumber() << " " << _street << ", " << _ward << ", " << _district << ", " << _city;
	return writer.str();
}

Address::operator string()
{
	return Address_to_string();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Address FakeHCMAddress::next()
{
	Address address;
	return address;
}

ostream& operator<<(ostream& out, Address address)
{
	out << address.get_Number() << " " << address.get_Street() << ", " << address.get_Ward() << ", " << address.get_District() << ", " << address.get_City();
	return out;
}