#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	long long num, sum;
	cout << "Введите количество номеров  ";
	cin >> n;
	for (int j = 0; j < n; j++) {
		cout << "Введите число  " ;
		cin >> num;
		k = num % 10;
		num = num / 10;
		sum = 0;
		for (int i = 0; i < 12; i++)
		{
			if (i % 2 == 0)
				sum = sum + (num % 10) * 3;
			else
				sum = sum + (num % 10);
			num = num / 10;
		}
		sum = sum % 10;
		sum = 10 - sum;
		if (sum == k)
			cout << "Действительный ISBN-13" << endl;
		else
			cout << "Недействительный ISBN-13" << endl;

	}




}