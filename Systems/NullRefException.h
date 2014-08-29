#pragma once
#include <exception>

namespace Survive
{

	class NullRefException :
		public std::exception
	{
	private:
		char* _message;
	public:
		NullRefException();
		NullRefException(char* msg);
		~NullRefException();

		const char* what() const;
	};

}