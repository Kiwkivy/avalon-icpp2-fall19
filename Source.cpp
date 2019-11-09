#include <iostream>
#include "Extention.hpp"
#include <string>

using namespace std;
using namespace ext;
struct Student {
	int Id;
	int Grade;
	string Name;
};

int main() {
	//Задание 1
	setlocale(LC_ALL, "rus");
	setlocale(0, "");
	//Student array[100];
	//string date;
	//string let;
	//string sort;
	//for (int i = 0; i < 100; i++) {
	//	array[i].Id = GetRandomValue(1, 1000);
	//	array[i].Grade = GetRandomValue(0, 100);
	//	int length = GetRandomValue(3, 6);
	//	char let = GetRandomValue('A', 'Z');
	//	date += let;
	//	for (int j = 1; j < length; ++j) {
	//		date += GetRandomValue('a', 'z');
	//	}
	//	array[i].Name += date;
	//	date = "";
	//}
	//cout << "Введите предмет сортировки" << endl;
	//cin >> sort;

	//if (sort == "Id") {
	//	for (int j = 0; j < 100; j++) {
	//		for (int k = 99; k > j; k--) {
	//			if (array[k].Id < array[k - 1].Id) {
	//				swap(array[k].Id, array[k - 1].Id);
	//			}
	//		}
	//	}
	//}
	//else if (sort == "Grade") {
	//	for (int j = 0; j < 100; j++) {
	//		for (int k = 99; k > j; k--) {
	//			if (array[k].Grade < array[k - 1].Grade) {
	//				swap(array[k].Grade, array[k - 1].Grade);
	//			}
	//		}
	//	}
	//}
	//else if (sort == "Name") {
	//	for (int j = 0; j < 100; j++) {
	//		for (int k = 99; k > j; k--) {
	//			if (array[k].Name < array[k - 1].Name) {
	//				swap(array[k].Name, array[k - 1].Name);
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	cout << "Данные введены некорректно" << endl;
	//}
	//for (int i = 0; i < 100; i++) {
	//	cout << "" << array[i].Id << " " << array[i].Grade << " " << array[i].Name << endl;
	//}




	////Задание 2
	//for (int j = 0; j < 100; j++) {
	//	for (int k = 99; k > j; k--) {
	//		if (array[k].Grade < array[k - 1].Grade) {
	//			swap(array[k].Grade, array[k - 1].Grade);
	//		}
	//	}
	//}
	//cout << "Чтобы стать лучше ";
	//cout << "25 % студентов нужно получить " << (array[25].Grade + 1) << " баллов" << endl;
	//cout << "50 % студентов нужно получить " << (array[50].Grade + 1) << " баллов" << endl;
	//cout << "75 % студентов нужно получить " << (array[75].Grade + 1) << " баллов" << endl;


	//Задание 3
	struct Agent
	{
		int monthlySales[12]; //зарплата
	};
	Agent array2[10];
	int med, med1, sum, rabsum;
	sum = 0;
	int kolvo, kolvo2;
	for (int b = 0; b < 10; b++) {
		kolvo = GetRandomValue(1, 7); // количество минус единиц
		kolvo2 = GetRandomValue(0, 12); // с какого месяца
		for (int i = 0; i < kolvo2; ++i)
		{
			array2[b].monthlySales[i] = GetRandomValue(100, 1000);
		}
		for (int i = kolvo2; i < kolvo + kolvo2; ++i)
		{
			array2[b].monthlySales[i] = -1;
		}
		for (int i = kolvo + kolvo2; i < 12; ++i)
		{
			array2[b].monthlySales[i] = GetRandomValue(100, 1000);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 12; j > i; j--) {
				if ((array2[i].monthlySales[j] != -1) && (array2[i].monthlySales[j] < array2[i].monthlySales[j - 1])) {
					swap(array2[i].monthlySales[j], array2[i].monthlySales[j - 1]);
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << "Агент № " << i << endl;
		for (int j = 0; j < 10; j++)
			cout << "" << array2[i].monthlySales[j] << endl;
		cout << endl;
	}


	for (int i = 0; i < 10; i++) {
		rabsum = 0;
		for (int j = 0; j < 12; j++) {
			if (array2[i].monthlySales[j] == -1) {
				rabsum++;
			}
		}
		if (rabsum % 2 == 0) {
			med = rabsum / 2;
			cout << "Медиана Агента № " << i << " равна " << array2[i].monthlySales[med] << endl;
		}
		else
		{
			med = rabsum / 2;
			med1 = med + 1;
			cout << "Медиана Агента № " << i << " равна " << array2[i].monthlySales[med] << " и " << array2[i].monthlySales[med1] << endl;
		}
	}
}
