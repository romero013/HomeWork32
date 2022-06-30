#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


// ������� � �������� ������� ���������
int binarySystem(int n) {
	int bin = 0;
	for (int i = 0; n > 0; i++) {
		bin += (n % 2) * pow(10, i);
		n /= 2;

	}
	return bin;
}

// ������ 1. ���������� � ������� � ������� �������� ������
int power(int &n) {
	int m = 2;
	if (n < 0)
		throw invalid_argument("������� ������������� �����");
	else
		if (n == 0)
			return 1;
		else {
			for (int i = 1; i < n; i++)
				m <<= 1;
			return m;
		}
}

// ������ 2. ������� ����������� ������
int number_of_units(int n) {
	int count = 0;
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == char(49))
			count++;
	}
	return count;
}

// ������ 3. ������� �������
char numberIndex(int n, int &index) {
	string newStr;
	string str = to_string(n);
	if (index < 0 || index > str.size())
		throw invalid_argument("������������ ����� �������");
	for (int i = str.size(); i >= 0; i--)
		newStr += str[i];
	return newStr[index + 1];
}

int main() {
	setlocale(LC_ALL, "ru");
	int n, index;
	bool f = false;

	// ������ 1.
	do {
		cout << "������ 1.\n\n";
		try {
			cout << "� ����� ������� �������� 2?\n������� ����� : ";
			cin >> n;
			cout << "����� 2 � ������� " << n << " = " << power(n) << "\n\n";
			f = true;
		}
		catch (const invalid_argument& ex) {
			cout << "������! " << ex.what() << ".\n\n";
		}
		system("pause");
		system("cls");
	} while (f == false);


	// ������ 2.
	cout << "������ 2.\n\n������� �����: ";
	cin >> n;
	cout << "����������� ������ ����� " << n << " � ��� �������� �������������� = " << number_of_units(binarySystem(n)) << ".\n\n";
	system("pause");
	system("cls");


	// ������ 3.
	try {
		cout << "������ 3.\n\n������� �����: ";
		cin >> n;
		cout << "������� ������: ";
		cin >> index;
		cout << "������ " << index << " ����� " << n << " � �������� ��� ������������� = " << numberIndex(binarySystem(n), index) << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "������! " << ex.what() << ".\n\n";
	}

	return 0;
}