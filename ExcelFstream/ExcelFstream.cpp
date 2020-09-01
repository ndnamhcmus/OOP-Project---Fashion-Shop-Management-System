#include "ExcelFstream.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////		EXCEL IN/OUT FILE STREAM		////


void ExcelFstream::open(string directory, ios_base::openmode mode)
{
	ExcelOfstream::open(directory, mode);
	ExcelIfstream::open(directory, mode);
}

void ExcelFstream::close()
{
	ExcelOfstream::close();
	ExcelIfstream::close();
}
