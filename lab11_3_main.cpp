#include <iostream>
#include "Vector.h"
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "ru");
    int quantity = 0;
    Time maxElement;
    Time middleArith;
    int position=0;
    cout << "Введите размер вектора ";
    cin >> quantity;
    Vector<Time>myVector(quantity);
    myVector.Show();
    maxElement=myVector.FindMaxElment();
    myVector.AddMaxElement(maxElement);
    myVector.Show();
    position = myVector.FindMinElement();
    myVector.DeleteMinElement(position);
    myVector.Show();
    middleArith = myVector.MiddleArith();
    cout << "Среднее " << middleArith << "\n";
    myVector.AddMiddleArrith(middleArith);
    myVector.Show();
}
