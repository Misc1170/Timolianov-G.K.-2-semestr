#include"Time.h"
#include"file_work.h"
#include<fstream>
#include <iostream>
#include <string>
using namespace std;

void main()
{
    setlocale(LC_ALL, "ru");
    Time x;
    Time y;
    Time t,tl,t2;
    int k, c;
    char fileName[30];
    do {
        cout << "\n\n==================";
        cout << "\n1.Создать файл";
        cout << "\n2.Показать содержимое файла";
        cout << "\n3.Удалить все записи равные заданному значению";
        cout << "\n4.Увеличить все записи равные заданному значению";
        cout << "\n5.Добавить К записей после элемента с заданным номером";
        cout << "\n0.Выход\n";
        cin >> c;
     switch (c) {
        case 1: cout << "Введите имя файла ";
            cin >> fileName;
            k = make_file(fileName);
            if (k < 0) {
                cout << "Не могу открыть файл!";
            }
            break;
        case 2:
            cout << "Введите имя файла ";
            cin >> fileName;
            k = print_file(fileName);
            if (k == 0) {
                cout << "Пусто!";
            }
            if (k < 0) {
                cout << "Не могу прочитать файл";
            }
            break;
        case 3:
            cout << "Введите имя файла ";
            cin >> fileName;
            cout << "Удалить все записи \n";
            k = DeleteTimeByCondition(fileName);
            if (k < 0) {
                cout << "Can't read file";
            }
            break;
        case 4:
            cout << "Введите имя файла ";
            cin >> fileName;
            cout << "Увеличить все записи ";
            k = UpTimeByCondition(fileName);
            if (k < 0) {
                cout << "Не прочитать файл";
            }
            break;
        case 5:
            cout << "Введите имя файла ";
            cin >> fileName;
            cout << "Добавить К записей после элемента с заданным номером";
            k = AddNRecordAfterByNumber(fileName);
            if (k < 0) {
                cout << "Не могу прочитать файл";
            }
            break;
     }
    } while (c!=0);
}
