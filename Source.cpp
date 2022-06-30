#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


// Перевод в двоичную систему счисления
int binarySystem(int n) {
	int bin = 0;
	for (int i = 0; n > 0; i++) {
		bin += (n % 2) * pow(10, i);
		n /= 2;

	}
	return bin;
}

// Задача 1. Возведение в степень с помощью битового сдвига
int power(int &n) {
	int m = 2;
	if (n < 0)
		throw invalid_argument("Введите положительное число");
	else
		if (n == 0)
			return 1;
		else {
			for (int i = 1; i < n; i++)
				m <<= 1;
			return m;
		}
}

// Задача 2. Возврат колличества единиц
int number_of_units(int n) {
	int count = 0;
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == char(49))
			count++;
	}
	return count;
}

// Задача 3. Возврат индекса
char numberIndex(int n, int &index) {
	string newStr;
	string str = to_string(n);
	if (index < 0 || index > str.size())
		throw invalid_argument("Недопустимое число индекса");
	for (int i = str.size(); i >= 0; i--)
		newStr += str[i];
	return newStr[index + 1];
}

int main() {
	setlocale(LC_ALL, "ru");
	int n, index;
	bool f = false;

	// Задача 1.
	do {
		cout << "Задача 1.\n\n";
		try {
			cout << "В какую степень возвести 2?\nВведите число : ";
			cin >> n;
			cout << "Число 2 в степени " << n << " = " << power(n) << "\n\n";
			f = true;
		}
		catch (const invalid_argument& ex) {
			cout << "Ошибка! " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (f == false);


	// Задача 2.
	cout << "Задача 2.\n\nВведите число: ";
	cin >> n;
	cout << "Колличество единиц числа " << n << " в его двоичном передставлении = " << number_of_units(binarySystem(n)) << ".\n\n";
	system("pause");
	system("cls");


	// Задача 3.
	try {
		cout << "Задача 3.\n\nВведите число: ";
		cin >> n;
		cout << "Введите индекс: ";
		cin >> index;
		cout << "Индекс " << index << " числа " << n << " в двоичном его представлении = " << numberIndex(binarySystem(n), index) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "Ошибка! " << ex.what() << ".\n\n";
	}

	return 0;
}