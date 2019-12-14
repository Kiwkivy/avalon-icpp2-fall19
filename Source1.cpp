#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char FirstName[20];
	char LastName[20];
};



int main() {
	ifstream fin("student.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end); // установка курсора на конец файла
	int size = fin.tellg();
	int count = size / sizeof(Student);
	fin.seekg(0, ios_base::beg);

	Student* student = new Student[count];
	fin.read(reinterpret_cast<char*>(student), sizeof(Student) * count);
	fin.close();

	string name;
	getline(cin, name);

	Student* ptr = nullptr;
	for (int i = 0; i < count; ++i)
	{
		string temp(student[i].FirstName);
		if (name == temp)
		{
			ptr = &student[i];
			break;
		}		
	}

	if (ptr == nullptr)
	{
		cout << "student with name " << name << " not found" << endl;
	}
	else
	{
		cout << ptr->Id << " " << ptr->FirstName << " " << ptr->LastName << endl;
	}
}