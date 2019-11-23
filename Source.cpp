#include "CharString.hpp"

using namespace ext;

int main()
{
	charString* s1 = new charString{ 'h' };
	charString* s2 = new charString{ 'e' };
	charString* s3 = new charString{ 'l' };

	charString* ptr = nullptr;
	ptr = s1;
	s1->nextSymbol = s2;
	s2->nextSymbol = s3;

	append(ptr, 'l');
	print(ptr);
}