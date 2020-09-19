#include "ExcelFstream.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////		EXCEL IN/OUT FILE STREAM		////

void ExcelFstream::open(const string& path, ios_base::openmode mode)
{
	_file.open(path, mode);


	try
	{
		if (!(_file))
		{
			throw ExcelFstreamException("File is not open");
		}
	}
	catch (const std::exception& mess)
	{
		cout << mess.what() << endl;
		exit(EXIT_FAILURE);
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
		if (!(Tok.size()))
		{
			continue;
		}
		container.push_back(Tok);
	}
}

void ExcelFstream::writeExcelString(const string& String, const string& needle)
{
	vector <string> Tok = Tokenizer::parse(String, needle);
	for (auto iter = Tok.begin(); iter != Tok.end(); iter++)
	{
		_buffer << *iter << ",";
	}
	_buffer << endl;


	_file << _buffer.str();


	_buffer.str("");
	_buffer.clear();
}
