#include<iostream>
#include<map>
#include "Vector.h"
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"
using namespace std;

template<class Time>
Time Vector<Time>::FindMaxElement()
{
	Time maxElement;
	auto itMultimap = myMap.begin();
	for (; itMultimap != myMap.end(); itMultimap++) {
		if (maxElement < itMultimap->second) {
			maxElement = itMultimap->second;
		}
	}
	cout << "Макс элемент " << maxElement << "\n";

	return maxElement;
}

//НЕ ДОБАВЛЯЕТ В НАЧАЛО(BEGIN НЕ РАБОТАЕТ)
void Vector <Time>::AddMaxElement(Vector myVector,Time maxElement) {
	//myMultimap.emplace(myMultimap.begin(), maxElement);
	multimap<int,Time> tempMap = myMap;
	myMap.clear();
	int i = 1;
	Time tempValue;
	myMap.emplace(0, maxElement);
	for (auto it = tempMap.begin(); it != tempMap.end(); it++) {
		tempValue = it->second;
		myMap.emplace(i, tempValue);
		i++;
	}
	//myVector.Show();;
}

int Vector <Time>:: FindMinElement()
{
	auto it = myMap.begin();
	int number = 0;
	Time minElement = it->second;
	for (; it != myMap.end(); it++) {
		if (minElement > it->second) {
			minElement = it->second;
			number = it->first;
		}
	}
	cout << "Минимальный элемент " << minElement << " " << "Ключ " << number << "\n";
	return number;
}

void Vector<Time>::DeleteMinElement(Vector &myVector, int minElement)
{
	myMap.erase(minElement);
}

Time Vector<Time>:: FindMiddleArith(Vector myVector)
{

	Time summa;
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		summa = summa + it->second;
	}
	return summa / myMap.size();
}

void Vector<Time>:: AddMiddleArith(Vector &myVector, Time middleArith)
{
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		it->second = it->second + middleArith;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int quantity;
	cout << "Введите размер контейнеа ";
	cin >> quantity;

	//создание контейнера
	Vector<Time> myVector(quantity);
	myVector.Show();

	//Нахождение и добавление макс элемента
	Time maxElement=myVector.FindMaxElement();
	myVector.AddMaxElement(myVector, maxElement);
	myVector.Show();

	//Найти и удалить минимальный элемент
	int minElement = myVector.FindMinElement();
	myVector.DeleteMinElement(myVector, minElement);
	myVector.Show();

	//Добавлние среднего ариф
	Time middleArith = myVector.FindMiddleArith(myVector);
	myVector.AddMiddleArith(myVector, middleArith);
	myVector.Show();

}

