#pragma once
#include <iostream>
namespace ext
{
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};

	void append(charString* &str, char symbol);
	void print(charString* str);

}