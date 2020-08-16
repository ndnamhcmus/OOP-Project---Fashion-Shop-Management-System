#include "Sequence.h"

int Sequence::_bill = 0;

int Sequence::next()
{
	this->_bill = this->_bill + this->_step;
	return this->_bill;
}

Sequence::Sequence(const int& start, const int& step)
{
	this->_bill = start;
	this->_step = step;
}
