using namespace std;
#include <iostream>
#include <fstream>
#include "Books.hpp"

int main(){
	setlocale(LC_ALL, "rus");
	int choice;
	cout << "----------- МЕНЮ -----------" << endl;
	cout << endl;
	cout << "1. Добавить книгу" << endl;
	cout << "2. Редактировать книгу по id" << endl;
	cout << "3. Искать книгу" << endl;
	cout << "4. Просмотреть список книг" << endl;
	cout << "5. Показать статистику" << endl;
	cout << endl;
	cout << "----------------------------" << endl;
	cout << "Ваш выбор: " ;
	cin >> choice;


	switch (choice) {
	case 1:
		AddBook();
		break;
	case 2:
		EditById();
		break;
	case 3:
		FindBook();
		break;
	case 4:
		ShowListOfBooks();
		break;
	case 5:
		ShowStatistics();
		break;
	default:
		break;
	}	
}


//добавлять книгу
//редактировать книгу(по id)
//искать книгу(по названию)
//просматривать список книг(отсортированный по автору и затем по названию)
//показывать статистику(всего книг в библиотеке, общая стоимость всех книг)

//идентификационный номер(уникальное значение)
//название книги
//автор книги
//цена
//количество экземпляров книги в библиотеке