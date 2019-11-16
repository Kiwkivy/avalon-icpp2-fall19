#include "CharArray.hpp"
#include <iostream>

using namespace std;
using namespace ext;

int main() {
	charArray str = new char[6]{ "hello" };
	charArray str2 = new char[7]{ " world" };
	int poz;
	cin >> poz;
	/*char result = characterAt(str, poz);*/
	/*cout << result;*/
	concatenate(str, str2); // str -> "hello world"
	cout << str;
}



