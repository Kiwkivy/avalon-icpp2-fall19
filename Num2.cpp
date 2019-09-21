#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int v, k, ves;
	long long num, sum;
	cout << "Введите версию ISBN  ";
	cin >> v;
    cout << "Введите число  " ;
	cin >> num;
	k = num % 10;
	num = num / 10;
	sum = 0;
	ves = 2;

	if (v == 13) {
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
	}
	else 
	{
		for (int i = 0; i < 10; i++)
		{
			sum = sum + (num % 10) * ves;
			ves++;
			num = num / 10;
		}
		sum = sum % 11;
		sum = 11 - sum;
	}


	if (sum == k)
		cout << "Действительный ISBN-" << v << endl;
	else
		cout << "Недействительный ISBN-" << v << endl;

}