#include <iostream>
#include <vector>
#include <stack>
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"
#include "Vector.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int quantity = 0;
    cout << "Введите размер контейнера ";
    cin >> quantity;
    Vector<Time>myVector(quantity);
    myVector.Show();
}
