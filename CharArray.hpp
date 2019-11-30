#pragma once //CharArray.hpp 
namespace ext
{
	using charArray = char*;

	char characterAt(charArray array, int number);
	void concatenate(charArray& first, charArray second);
	void append(charArray& array, char newChar);
	void coutArray(charArray array);
	charArray substring(charArray array, int poz, int length);
	void replaceString(charArray array, charArray& goal, charArray rep);
}
