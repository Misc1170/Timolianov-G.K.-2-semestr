#include <iostream>
#include <string>
#include"Vector.h"
#include"Error.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	try	{
		int n;
		cout << "Введите размер Вектора ";
		cin >> n;
		Vector x(n);
		cout << x;

		// Доступ по индексу[]
		cout << "\nВведите номер индекса ";
		int i;
		cin >> i;
		cout << x[i] << endl;

		//Определение размера вектора
		cout << "Размер вектора (" << x.operator()(x) << ")" << endl;

		//добавляет константу
		cout << "Элементы вектора после добавления константы " << endl;
		x = x + add;

		//удаляет
		int del;
		cout << "\nВведите количество элементов для удаления ";
		cin >> del;
		x = x - del;
	}
	catch (error e)	{
		e.what();
	}
	return 0;
}