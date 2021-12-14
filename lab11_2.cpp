#include<iostream>
#include<vector>
#include<cstdlib>
#include "Time.h"
using namespace std;

typedef vector<Time>Vector;
Vector MakeVector(int n)
{
	Vector myVector;
	cout << "Введите Вектор \n";
	for (int i = 0; i < n; i++) {
		Time classVector;
		cin >> classVector;
		myVector.push_back(classVector);
	}
	return myVector;
}

void ShowVector(Vector myVector)
{
	cout << "Элементы вектора \n";
	for (int i = 0; i < myVector.size(); i++) {
		cout <<i+1<<"."<<" "<< myVector[i] << "\n";
	}
}

int FindMaxElement(Vector myVector,const Time&classVector)
{
	Time temp;
	int maxElement = 0;
	for (int i = 0; i < myVector.size(); i++){
		if (temp < classVector) {
			temp = classVector;
			maxElement = i;
		}
	}
	cout << "Номер максимального элемента " << maxElement;
	return maxElement;
}

void main() 
{
	setlocale(LC_ALL, "ru");
	vector<Time>myVector;
	Time classVector;
	int quantity = 0;
	int maxElement = 0;
	int minElement = 0;
	cout << "Введите размер вектора ";
	cin >> quantity;
	myVector=MakeVector(quantity);
	ShowVector(myVector);
	maxElement = FindMaxElement(myVector, classVector);
}