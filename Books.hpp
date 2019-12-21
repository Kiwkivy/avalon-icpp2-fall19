#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Book
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};

void AddBook() {
	Book book{};
	cout << "-- ДОБАВЛЕНИЕ НОВОЙ КНИГИ --" << endl;
	cout << endl;
	cout << "Введите название книги: ";
	cin >> book.Title;
	cout << "Введите автора книги: ";
	cin >> book.Author;
	cout << "Введите цену книги: ";
	cin >> book.Price;
	cout << "Введите количество книг: ";
	cin >> book.Quantity;
	cout << "----------------------------" << endl;
	
	ifstream fileId("nextId.txt", iostream::app);
	if (!fileId.is_open())	// ïðîâåðêà óñïåøíîñòè îòêðûòèÿ ôàéëà
	{
		cout << "Cannot open file in" << endl;
		exit(1);
	}
	fileId >> book.Id;
	fileId.close();

	ofstream fileIdOut("nextId.txt");
	if (!fileIdOut.is_open())	// ïðîâåðêà óñïåøíîñòè îòêðûòèÿ ôàéëà
	{
		cout << "Cannot open file out" << endl;
		exit(1);
	}
	else
	{
		fileIdOut << book.Id + 1;
	}

	fileIdOut.close();



	ofstream fout("Books.bin", istream::out | istream::binary | istream::app);

	fout.write(reinterpret_cast<char*>(&book), sizeof(Book));

	fout.close();
}


void EditById() {
	ifstream fin("Books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end); 
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* book = new Book[count];
	fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
	fin.close();
	int id;
	cout << "Введите id интересубщей вас книги: ";
	cin >> id;
	cout << endl;


	Book* ptr = nullptr;
	for (int i = 0; i < count; ++i)
	{
		if (id == book[i].Id)
		{
			ptr = &book[i];
			break;
		}
	}

	cout << "----ПЕРЕЗАПИСЬ ИНФОРМАЦИИ О КНИГЕ ---- " << endl;
	cout << endl;
	cout << "Введите название книг: " ;
	cin >> ptr->Title;
	cout << "Введите автора книги:  ";
	cin >> ptr->Author;
	cout << "Введите цену книги: " ;
	cin >> ptr->Price;
	cout << "Введите количество книг: ";
	cin >> ptr->Quantity;
	cout << "Спасибо за предоставленную информацию ";
	cout << endl;
	cout << "----------------------------" << endl;
}


	void FindBook(){

		ifstream fin("Books.bin", istream::in | istream::binary);

		fin.seekg(0, ios_base::end); // óñòàíîâêà êóðñîðà íà êîíåö ôàéëà
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);

		Book* book = new Book[count];
		fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
		fin.close();

		string title;
		cout << "Введите название интересующей вас книги: ";
		cin >> title;
		cout << endl;
		Book* ptr = nullptr;
		for (int i = 0; i < count; ++i)
		{
			string temp(book[i].Title);
			if (title == temp)
			{
				ptr = &book[i];
				break;
			}
		}

		if (ptr == nullptr)
		{
			cout << "Книга под названием <<" << title << ">> не найдена" << endl;
		}
		else
		{

			cout << "---- ИНФОРМАЦИИ О КНИГЕ ----" << endl;
			cout << endl;
			cout << "Id книги: " << ptr->Id << endl;
			cout << "Автор книги: " << ptr->Author << endl; 
		    cout << "Цена книги: " << ptr->Price << endl;
			cout << "Количество книг: " << ptr->Quantity << endl;
			cout << endl;
			cout << "----------------------------" << endl;
		}
	}


	void ShowListOfBooks(){
		ifstream fin("Books.bin", istream::in | istream::binary);

		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);

		Book* book = new Book[count];
		fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
		fin.close();
		int k = 0;
		cout << "-- Отсортированный список --" << endl;
		for (int i = 0; i < count; i++) {
				for (int j = count - 1; j > i; j--) {
					string temp1(book[j].Author);
					temp1 += string(book[j].Title);
					string temp2(book[j + 1].Author);
					temp2 += string(book[j+1].Title);
					if (temp1 > temp2) {
						swap(book[i], book[i+1]);
					}
				}
				// if (sort == "Id") {
					//	for (int j = 0; j < 100; j++) {
					//		for (int k = 99; k > j; k--) {
					//			if (array[k].Id < array[k - 1].Id) {
					//				swap(array[k].Id, array[k - 1].Id);
					//			}
					//		}
		}
		for (int i = 0; count > i; i++) {
			cout << book[i].Id << " " << book[i].Title << " " << book[i].Author << " " << book[i].Price << " " << book[i].Quantity << endl;
		}
	}

	void ShowStatistics()
	{
		ifstream fin("Books.bin", istream::in | istream::binary);

		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);

		Book* book = new Book[count];
		int sum_price, sum_quantity;
		sum_price = 0;
		sum_quantity = 0;
		//fin.open("Books.bin", ios_base::in);
		fin.read(reinterpret_cast<char*>(book), sizeof(Book) * count);
		fin.close();

		for (int i = 0; i < count; ++i)
		{
			sum_price += book[i].Price;
			sum_quantity += book[i].Quantity;
		}
		cout << "Общая стоимость книг: " << sum_price << endl;
		cout << "Общее количество книг: " << sum_quantity << endl;
	}