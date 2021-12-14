#include<vector>
#include<iostream>
#include <algorithm>
#include"C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"
using namespace std;

typedef vector<Time>Vector;
Vector CreateVector(int n)
{
	Time value;
	Vector myVector;
	for (int i = 0; i < n; i++) {
		cout << "Введите данные контейнера ";
		cin >> value;
		myVector.push_back(value);
	}
	return myVector;
}

void Show(Vector myVector)
{
	cout << "Данные контейнера \n";
	for (int i = 0; i < myVector.size(); i++) {
		cout << i + 1 << ". " << myVector[i] << "\n";
	}
}

Time FindMiddleArith(Vector myVector)
{
	Time middleArith;
	for (int i = 0; i < myVector.size(); i++) {
		middleArith = middleArith + myVector[i];
	}
	return middleArith/myVector.size();
}

void AddMiddleArith(Vector& myVector, Time middleArith)
{
	
	for (int i = 0; i < myVector.size(); i++) {
		myVector[i] = myVector[i] + middleArith;
	}
}

typedef vector<Time>Vector;
Time maxElement;
struct maxElementstr
{
	bool operator()(Time time)
	{
		return time == maxElement;		
	}
};

typedef vector<Time>Vector;
Time minElement;
struct minElementstr
{
	bool operator()(Time time)
	{
		return time == minElement;
	}

};


int main()
{
	setlocale(LC_ALL, "ru");
	int quantity;
	Time newValue;
	cout << "Введите размер контейнера ";
	cin >> quantity;

	//СОздание
	Vector myVector = CreateVector(quantity);
	Show(myVector);

	//Удаление и замена максимального
	auto maxIt=max_element(myVector.begin(), myVector.end());
	maxElement = *(maxIt);
	cout << "Максимальный элемент " << maxElement << "\n";
	cout << "Введите новое значения\n ";
	cin >> newValue;
	replace_if(myVector.begin(), myVector.end(), maxElementstr(), newValue);
	Show(myVector);
	
	//Найти и удалить миним элемент
	auto minIt = min_element(myVector.begin(), myVector.end());
	minElement = *(minIt);
	cout << "Минимальный элемент " << minElement << "\n";
	auto elForDel=remove_if(myVector.begin(), myVector.end(), minElementstr());
	myVector.erase(elForDel, myVector.end());
	Show(myVector);

	//Добавление среднего ариф
	Time middlearith = FindMiddleArith(myVector);
	cout << "Среднее ариф " << middlearith << "\n";
	AddMiddleArith(myVector, middlearith);
	Show(myVector);
}
