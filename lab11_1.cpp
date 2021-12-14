#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef vector<double>Vector;
Vector MakeVector(int n)
{
	Vector myVector;
	for (int i = 0; i < n; i++) {
		double value = (double)rand() / (double)RAND_MAX * 50;
		myVector.push_back(value);
	}
	return myVector;
}

void ShowVector(Vector myVector)
{
	for (int i = 0; i < myVector.size(); i++) {
		cout << i + 1 << ".  " << myVector[i] << endl;;
	}
	cout << endl;
}

double FindMiddleAtirhNumber(Vector myVector)
{
	double temp = 0;
	double result = 0;
	for (int i = 0; i < myVector.size(); i++) {
		temp += myVector[i];
	}
	result = temp / myVector.size();
	cout << "\nСреднее арифметическое Вектора " << result;
	return result;
}


double FindMaxElement(Vector myVector)
{
	double maxElem = 0;
	for (int i = 0; i < myVector.size(); i++) {
		if (maxElem < myVector[i]) {
			maxElem = myVector[i];
		}
	}
	cout << "\nМаксимальный элемент " << maxElem << endl;
	return maxElem;
}

int FindMinElement(Vector myVector)
{
	double minElem = myVector[0];
	int numMinElem = 0;
	for (int i = 0; i < myVector.size(); i++) {
		if (minElem > myVector[i]) {
			minElem = myVector[i];
			numMinElem = i;
		}
	}
	cout << "\nНомер минимального элемента " << numMinElem + 1 << endl;
	cout << "Минимальный элемент " << minElem << endl;
	return numMinElem;
}

Vector UpEachElementOnMiddleArith(Vector myVector, double middleArith)
{
	Vector tempVector;
	double value;
	for (int i = 0; i < myVector.size(); i++) {
		value = myVector[i] + middleArith;
		tempVector.push_back(value);
	}
	return tempVector;
}

int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		vector <double>myVector;
		vector<double>tempVector;
		vector<double>::iterator vectorIterator = myVector.begin();
		int numbers;
		cout << "Введите размер Вектора ";
		cin >> numbers;
		myVector = MakeVector(numbers);
		ShowVector(myVector);
		double middleArith = FindMiddleAtirhNumber(myVector);
		double maxElement = FindMaxElement(myVector);
		myVector.insert(myVector.begin(), maxElement);
		ShowVector(myVector);
		int numMinElem = FindMinElement(myVector);
		myVector.erase(myVector.begin() + numMinElem);
		ShowVector(myVector);
		cout << "Элементы вектора после добавления среднего арифметического \n";
		tempVector = UpEachElementOnMiddleArith(myVector, middleArith);
		ShowVector(tempVector);
	}
	catch (int)
	{
		cout << "Ошибка ";
	}

}
