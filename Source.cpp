#include <iostream>

using namespace std;

using Data = int*; //�� �������� int* �� Data

void resizeArray(int* & ptr, int oldSize, int inc) {    
	Data newPtr = new int[oldSize + inc];
	for (int i = 0; i < oldSize; ++i)
	{
		newPtr[i] = ptr[i];
	}
	delete[] ptr;

	ptr = newPtr;
}  

int main() {
	setlocale(LC_ALL, "rus");

	int n = 5;
	Data ptr = new int[n] {2, 4, 6, 8, 10}; // * - ���������
	// ����� ���������� ���� ������ �� ptr, ����� add watch, ����� "ptr, 100" ������

	int newValue;
	cin >> newValue;

	resizeArray(ptr, n, 1);

	for (int i = 0; i < n + 1; ++i)
	{
		cout << ptr[i] << " "; //2;4;6;8;10; newValue
	}
}

