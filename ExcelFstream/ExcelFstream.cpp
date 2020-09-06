#include "ExcelFstream.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////		EXCEL IN/OUT FILE STREAM		////

void ExcelFstream::open(const string& path, ios_base::openmode mode)
{
	_file.open(path, ios::in | ios::out | mode);


	try
	{
		if (!(_file))
		{
			throw ExcelFstreamException("File is not open");
			exit(EXIT_FAILURE);
		}
	}
	catch (const std::exception& mess)
	{
		cout << mess.what() << endl;
	}
}

void ExcelFstream::close()
{
	_file.close();
}

void ExcelFstream::readExcelString(vector<vector <string>>& container)
{
	string buffer;
	vector <string> Tok;
	while (getline(_file, buffer))
	{
		Tok = Tokenizer::parse(buffer, ",");
		container.push_back(Tok);
	}
}

void ExcelFstream::writeExcelString(const string& String)
{
	vector <string> Tok = Tokenizer::parse(String, " ");
	vector <string>::iterator iter;
	for (iter = Tok.begin(); iter != Tok.end(); iter++)
	{
		_buffer << *iter << ",";
	}
	_buffer << endl;


	_file << _buffer.str();
}
