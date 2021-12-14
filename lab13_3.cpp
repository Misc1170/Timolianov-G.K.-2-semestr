
#include <iostream>
#include"C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef set<Time>Set;

Set CreateSet(int n)
{
	Set mySet;
	Time value;
	cout << "Введите данные ";
	for (int i = 0; i < n; i++) {
		cin >> value;
		mySet.emplace(value);
	}
	return mySet;
}

void ShowSet(Set mySet)
{
	cout << "Данные контейнера Сет:\n";
	for (auto itSet : mySet) {
		int i = 1;
		cout <<	i << ". " << itSet << "\n";
	}
}

Time FindMiddleArith(Set mySet)
{
	vector<Time> myVector;
	Time tmp;
	Time middleArith;
	int i = 0;
	for (auto itSet:mySet) {
		myVector.push_back(itSet);
		middleArith = middleArith + myVector[i];
		i++;
	}
	return middleArith / mySet.size();
}

void AddMiddleArith(Set &mySet, Time middleArith)
{
	vector<Time>myVector;
	for (auto itSet:mySet) {
		myVector.push_back(itSet);
	}
	mySet.clear();
	for (int i = 0; i < myVector.size(); i++) {
		myVector[i] = myVector[i] + middleArith;
		mySet.insert(myVector[i]);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int quantity;
	Set mySet;
	cout << "Введите размер контерйнера ";
	cin >> quantity;

	//Создание стека

	mySet = CreateSet(quantity);
	ShowSet(mySet);

	//Найти и заменить макс элемент
	Time newValue;
	auto itMax = max_element(mySet.begin(), mySet.end());
	cout << "Введите данные нового значения ";
	cin >> newValue;
	mySet.erase(itMax);
	mySet.insert(newValue);
	cout << "После добавления максимального:\n";
	ShowSet(mySet);

	//Найти и удалить минимальный элемент
	auto itMin = min_element(mySet.begin(), mySet.end());
	mySet.erase(itMin);
	cout << "После удаления минимального:\n";
	ShowSet(mySet);

	//Среднее арифметическое
	Time middleArith;
	FindMiddleArith(mySet);
	middleArith = FindMiddleArith(mySet);
	cout << "Среднее арифметическое " << middleArith;
	AddMiddleArith(mySet, middleArith);
	ShowSet(mySet);
	return 0;
}
