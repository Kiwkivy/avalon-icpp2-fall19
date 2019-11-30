#include "CharArray.hpp" //Stroka.cpp 
#include <iostream> 

using namespace std;
using namespace ext;

int main()
{
	setlocale(LC_ALL, "rus");
	char char1;
	int poz, length;

	charArray str = new char[7]{ "hello " };
	charArray str2 = new char[6]{ "world" };
	charArray str3 = new char[8]{ "Goodbye" };
	charArray str4 = new char[13]{ "abccabcabc" };
	charArray goal = new char[3]{ "ca" };
	charArray rep = new char[4]{ "def" };

	cout<<("Введите символ")<< endl;
	cin>> char1;
	cout<<("Введите позицию ")<< endl;
	cin >>poz;
	cout<<("Введите длинну ") << endl;
	cin>> length;
	cout<<("Введите символы для замены ") << endl;
	cin>> rep;



	char result1 = characterAt(str, 1); // h 
	char result2 = characterAt(str, 3); // l 
	//concatenate(str, str2); // str -> " hello world" 
	//append(str3, char1); // str3 -> "Goodbye!"; 
	//charArray subArray = substring(str3, poz, length);
	replaceString(str4, goal, rep);


	//cout << "CharacterAt: " << result1 << " or " << result2 << endl;
	//cout<< "Append: ";
	//coutArray(str3);
	//cout << "Concatenate: ";
	//coutArray(str);
	//cout << "Substring: ";
	//coutArray(subArray);
	cout << "ReplaceString: ";
	coutArray(str4);



	/*replaceString - функция принимаем три параметра,
	каждый из которых является динамической строкой : исходная строка, целевая строка, заменяемый текст.
	Функция должна заменить каждую целевую строку, которая есть в исходной строке на заменяемый текст.
	Например, если исходная строка - 'abcdabee', целевая строка - 'ab', и заменяемый текст - 'xyz', то после работы функции исходная строка должна содержать - 'xyzcdxyzee'.

	}*/
}