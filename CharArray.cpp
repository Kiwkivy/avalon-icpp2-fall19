#include "CharArray.hpp"     //CharArray.cpp 
#include <iostream> 
using namespace std;

namespace ext
{
	int coutLength(charArray first) { //Ïîäñ÷¸ò ñèìâîëîâ 
		int length = 0;
		while (first[length] != '\0')
		{
			++length;
		}
		return length;
	}

	void coutArray(charArray array) {
		int length = coutLength(array);
		for (int i = 0; i < length + 1; ++i) {
			cout << array[i];
		}
		cout << endl;
	}


	char characterAt(charArray str, int number)
	{
		return str[number - 1];
	}



	void append(charArray& array, char newChar)
	{
		int length = coutLength(array);
		/* charArray result = new char[length + 1];*/
		charArray result = new char[length + 2];
		for (int i = 0; i < length; ++i) {
			result[i] = array[i];
		}
		result[length] = newChar;
		result[length + 1] = '\0';
		delete[] array;
		array = result;
	}


	void concatenate(charArray& first, charArray second) {
		int lengthFirst = coutLength(first);
		int lengthSecond = coutLength(second);

		charArray result = new char[lengthFirst + lengthSecond + 1];

		for (int i = 0; i < lengthFirst; ++i) {
			result[i] = first[i];
		}
		for (int i = 0; i < lengthSecond; ++i)
		{
			result[lengthFirst + i] = second[i];
		}
		result[lengthFirst + lengthSecond] = '\0';
		delete[] first;
		first = result;
	}

	charArray substring(charArray array, int poz, int length) {
		poz--;
		int lengthArray = coutLength(array);
		charArray result = new char[length];

		for (int i = 0; poz < lengthArray - 1; ++i) {
			result[i] = array[poz];
			poz++;
		}
		result[length] = '\0';
		return result;
	}

	void replaceString(charArray array, charArray& goal, charArray rep) {
		int length = coutLength(array);
		int goalLength = coutLength(goal);
		int repLength = coutLength(rep);
		int repsNum = 0;
		int numTrue = 0;


		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < goalLength; j++) {
				if (array[i + j] == goal[j]) {
					numTrue++;
				}
				if (numTrue == goalLength) {
					repsNum++;
					for (int k = 0; k < goalLength; ++k)
						array[i + k] = '0';
				}
			}
			numTrue = 0;
		}




		int resultSize = length - goalLength * repsNum + repLength * repsNum;
		charArray result = new char[resultSize];
		int ilen = 0;

		for (int i = 0; i < resultSize; ++i) {
			if (array[ilen] == '0') {
				for (int j = 0; j < repLength; ++j) {
					result[i + j] = rep[j];
				}
				i = i + goalLength;
				ilen = ilen + repLength;
			}
			else {
				result[i] = array[ilen];
			}

			i++;

		}
	}

	/*replaceString - функция принимаем три параметра,
	каждый из которых является динамической строкой : исходная строка, целевая строка, заменяемый текст.
	Функция должна заменить каждую целевую строку, которая есть в исходной строке на заменяемый текст.
	Например, если исходная строка - 'abcdabee', целевая строка - 'ab', и заменяемый текст - 'xyz', то после работы функции исходная строка должна содержать - 'xyzcdxyzee'.*/

}