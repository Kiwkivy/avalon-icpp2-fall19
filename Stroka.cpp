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

	cout<<("������� ������")<< endl;
	cin>> char1;
	cout<<("������� ������� ")<< endl;
	cin >>poz;
	cout<<("������� ������ ") << endl;
	cin>> length;
	cout<<("������� ������� ��� ������ ") << endl;
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



	/*replaceString - ������� ��������� ��� ���������,
	������ �� ������� �������� ������������ ������� : �������� ������, ������� ������, ���������� �����.
	������� ������ �������� ������ ������� ������, ������� ���� � �������� ������ �� ���������� �����.
	��������, ���� �������� ������ - 'abcdabee', ������� ������ - 'ab', � ���������� ����� - 'xyz', �� ����� ������ ������� �������� ������ ������ ��������� - 'xyzcdxyzee'.

	}*/
}