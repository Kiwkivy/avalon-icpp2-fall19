#include "CharArray.hpp"
#include <iostream>
using namespace std;

namespace ext
{
	int coutLength(charArray first) {  //Подсчёт символов
		int length = 0;
		while (first[length] != '\0')
		{
			++length;
		}
		return length;
	}


	char characterAt(charArray str, int number)
	{
		return str[number - 1];
	}



	/*void append(charArray array, char sum)
	{
		int length = coutLength(array);

	}
*/


	void concatenate(charArray & first, charArray second) {
		int lengthFirst = coutLength(first);
		int lengthSecond = coutLength(second);

		charArray result = new char[lengthFirst + lengthSecond + 1];

		for (int i = 0; i < lengthFirst; ++i) {
			result[i] = first[i];
		}
		for(int i = 0; i < lengthSecond; ++i)
		{
			result[lengthFirst + i] = second[i];
		}
		result[lengthFirst + lengthSecond] = '\0';
		delete[] first;
		first = result;
	}

}