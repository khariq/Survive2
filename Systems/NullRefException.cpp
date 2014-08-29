#include "NullRefException.h"

using namespace Survive;

NullRefException::NullRefException()
{
	_message = NULL;
}


NullRefException::~NullRefException()
{
	if (_message != NULL)
	{
		delete _message;
	}
}

NullRefException::NullRefException(char* msg)
{
	int len = strlen(msg);
	_message = new char[len];
	strcpy(_message, msg);
}

const char* NullRefException::what() const
{
	return _message;
}