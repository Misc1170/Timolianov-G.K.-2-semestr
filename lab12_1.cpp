#include <iostream>
#include <map>
using namespace std;

typedef multimap<int, double>Tmultimap;
typedef Tmultimap::iterator It;

Tmultimap CreateMultiMap(int n)
{
	Tmultimap myMultimap;
	double value;
	for (int i = 0; i < n; i++) {
		double value = (double)rand() / (double)RAND_MAX * 50;
		myMultimap.emplace(make_pair(i, value));
	}
	return myMultimap;
}

void ShowMultiMap(Tmultimap myMultimap)
{
	cout << "Данные для контейнера \n";
	auto itMultimap = myMultimap.begin();
	for (; itMultimap !=myMultimap.end(); itMultimap++)	{
		cout << itMultimap->first <<": " << itMultimap->second << " \n";
	}
}

double FindMaxElement(Tmultimap myMultimap)
{
	double maxElement = 0;
	auto itMultimap = myMultimap.begin();
	for ( ; itMultimap != myMultimap.end(); itMultimap++) {
		if (maxElement< itMultimap->second) {
			maxElement = itMultimap->second;
		}
	}
	cout << "Макс элемент " << maxElement << "\n";
	
	return maxElement;
}

//НЕ ДОБАВЛЯЕТ В НАЧАЛО(BEGIN НЕ РАБОТАЕТ)
void AddMaxElement(Tmultimap myMultimap, double maxElement) {
	//myMultimap.emplace(myMultimap.begin(), maxElement);
	Tmultimap tempMap=myMultimap;
	myMultimap.clear();
	int i = 1;
	double tempValue;
	myMultimap.emplace(0, maxElement);
	for (auto it = tempMap.begin(); it != tempMap.end(); it++) {
		tempValue = it->second;
		myMultimap.emplace(i, tempValue);
		i++;
	}
	ShowMultiMap(myMultimap);
}

int FindMinElement(Tmultimap myMultimap)
{
	auto it = myMultimap.begin();
	int number = 0;
	double minElement = it->second;
	for (; it !=myMultimap.end(); it++) {
		if (minElement > it->second) {
			minElement = it->second;
			number = it->first;
		}
	}
	cout << "Минимальный элемент " << minElement <<" "<< "Ключ " << number << "\n";
	return number;
}

double FindMiddleArith(Tmultimap myMultimap)
{
	
	double summa = 0;
	for (auto it = myMultimap.begin(); it != myMultimap.end(); it++) {
		summa = +it->second;
	}
	return summa / myMultimap.size();
}

void AddMiddleArith(Tmultimap& myMultimap, double middleArith)
{
	for (auto it = myMultimap.begin(); it !=myMultimap.end(); it++)	{
		it->second=it->second + middleArith;
	}
	//return myMultimap;
}


void main()
{
	setlocale(LC_ALL, "ru");
	int quantity;
	cout << "Введите размер контейнера ";
	cin >> quantity;
	//создание
	Tmultimap myMultimap = CreateMultiMap(quantity);
	ShowMultiMap(myMultimap);
	//Нахождение и добавление макс элемента
	double maxElement = FindMaxElement(myMultimap);
	AddMaxElement(myMultimap, maxElement);
	//Мин элемент и удаление
	int minElement = FindMinElement(myMultimap);
	myMultimap.erase(minElement);
	ShowMultiMap(myMultimap);
	//Добавление среднего арифметического
	double middleArith = FindMiddleArith(myMultimap);
	cout << "Среднее арифметичское " << middleArith << "\n";
	AddMiddleArith(myMultimap, middleArith);
	ShowMultiMap(myMultimap);
}
