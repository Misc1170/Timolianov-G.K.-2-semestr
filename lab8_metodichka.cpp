#include <iostream>
#include <vector>
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab8_metodichka\1lst.h"
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab8_metodichka\2lst.h"
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab8_metodichka\binaryTree.h"
using namespace std;
vector<char> myVector;

//ОДНОНАПРАВЛЕННЫЙ
point1* CreateList1(int n)
{
    point1* begin1;
    point1* pActually;
    point1* pTemp;
    begin1 = new point1;
    cout << "Введите данные первого элемента ";
    cin >> begin1->data;
    begin1->next = nullptr;
    pActually = begin1;
    cout << "\nВведите данные элемента \n";
    for (int i = 0; i < n - 1; i++) {
        pTemp = new point1;
        cin >> pTemp->data;
        // pTemp->data = i + 2;
        pTemp->next = nullptr;
        pActually->next = pTemp;
        pActually = pTemp;
    }
    return begin1;
}
void ShowList1(point1* begin1)
{
    point1* pTemp = begin1;
    int i = 0;
    cout << "Данные списка \n";
    while (pTemp != nullptr) {
        cout << i + 1 << ". " << pTemp->data << "\n";
        pTemp = pTemp->next;
        i++;
    }
}
point1* Delete(point1* begin1)
{
    point1* pTemp = begin1;
    point1* pDelete = new point1;
    while (pTemp->next != nullptr) {
        if (pTemp->data % 2 == 1) {
            pDelete = pTemp->next;
            pTemp->next = pDelete->next;
            delete pDelete;
            if (pTemp->next != nullptr) {
                pTemp = pTemp->next;
            }
        }
        else {
            pTemp = pTemp->next;
        }
    }
    return begin1;
}
point1* ClearList1(point1* begin1)
{
    point1* pTemp = begin1;
    point1* pDelete = new point1;
    while (pTemp != nullptr) {
        pDelete = pTemp;
        pTemp = pTemp->next;
        delete pDelete;
    }
    cout << "\nОднонапрвленный список ПУСТ!\n";
    return begin1;
}

//ДВУНАПРАВЛЕННЫЙ
point2* CreateOneElem()
{
    point2* pTemp2 = new point2;
    pTemp2->next = 0;
    pTemp2->previously = 0;
    char str[50];
    cout << "Введите строку для одного элемента ";
    cin >> str;
    pTemp2->dataString = new char[strlen(str) + 1];
    strcpy(pTemp2->dataString, str);
    return pTemp2;
}
point2* CreateList2(int n)
{
    point2* begin2;
    point2* pActually2;
    point2* pTemp2;
    begin2 = new point2;
    cout << "\nПервый элемент ";
    begin2 = CreateOneElem();
    pActually2 = begin2;
    for (int i = 0; i < n; i++) {
        pTemp2 = new point2;
        pTemp2 = CreateOneElem();
        pTemp2->next = nullptr;
        pActually2->next = pTemp2;
        pActually2->previously = pActually2;
        pActually2 = pTemp2;
    }
    return begin2;
}
void ShowList2(point2* begin2)
{
    point2* pTemp2 = begin2;
    char* prevously;
    char* next;
    cout << "Данные Двунаправленного списка \n";
    while (pTemp2->next != nullptr) {
        cout << "\nДанные предыдущего элемента: " << pTemp2->previously->dataString << "\n";
        cout << "Данные данного элемента: " << pTemp2->dataString << "\n";
        cout << "Данные следующего элемента " << pTemp2->next->dataString << "\n";
        pTemp2 = pTemp2->next;
    }
}
point2* AddElement(point2* begin2, int k)
{
    point2* pTemp2 = begin2;
    point2* pNew = new point2;
    point2* pTmp = new point2;
    char str2[50];
    cout << "Введите строку для нового элемента ";
    pNew = CreateOneElem();
    if (k == 0) {
        pNew->next = begin2;
        begin2 = pNew;
        return begin2;
    }
    //for (int i = 0; i < k && pTemp2!=nullptr; i++) {
    //    pTemp2 = pTemp2->next;
    //    if (i==k-2) {
    //        pNew->next = pTemp2->next;
    //        pTemp2 = pNew;
    //        pTemp2->next = pNew->next;
    //        //pTemp2->next = pNew;
    //    }
    //    if (i==k-1) {
    //        pTemp2->previously = pNew;
    //    }
    //}
    int i = 0;
    while (pTemp2 != nullptr) {
        if (i == k - 2) {
            pNew->next = pTemp2->next;
            pTemp2->next = pNew;
        }
        else {
            pTemp2 = pTemp2->next;
        }
        if (i == k - 1) {
            pTemp2->previously = pNew;
        }
        i++;
    }
    return begin2;
}
point2* ClearList1(point2* begin2)
{
    point2* pTemp2 = begin2;
    point2* pDelete2 = new point2;
    while (pTemp2 != nullptr) {
        pDelete2 = pTemp2;
        pTemp2 = pTemp2->next;
        delete pDelete2;
    }
    cout << "\nДВУНАПРАВЛЕННЫЙ список ПУСТ!\n";
    return begin2;
}

//БИНАРНОЕ ДЕРЕВО
binaryTree* CreateNode(char data)
{
    binaryTree* node = new binaryTree;
    node->Data = data;
    node->leftBranch = nullptr;
    node->rightBranch = nullptr;
    return node;
}

binaryTree* IdealBalanceTree(int size, binaryTree* tree)
{
    binaryTree* temp;
    int sizeRight;
    int sizeLeft;
    if (size == 0) {
        tree = nullptr;
        return tree;
    }
    sizeLeft = size/2;
    sizeRight = size-sizeLeft - 1;
    temp = new binaryTree;
    cout << "Введите символ для идеально сбалансированного дерева ";
    cin >> temp->Data;
    myVector.push_back(temp->Data);
    temp->leftBranch = (IdealBalanceTree(sizeLeft, temp->leftBranch));
    temp->rightBranch = (IdealBalanceTree(sizeRight, temp->rightBranch));
    tree = temp;
    return tree;
}

void SearchTree(char data, binaryTree*& tree)
{
    if (tree == nullptr) {
        return;
    }

    if (data <= tree->Data) {
         SearchTree(data, tree->leftBranch); 
        }
    
    else {
         SearchTree(data, tree->rightBranch);
    }

}
void PrintTree(binaryTree* tree) {
    if (tree == nullptr) {
        return;
    }
    else{
        cout << tree->Data<<"\n";
        if (tree->leftBranch != nullptr) {
            PrintTree(tree->leftBranch);
        }
        if (tree->rightBranch != nullptr) {
            PrintTree(tree->rightBranch);
        }
    }
}
void PrintSorted(binaryTree* tree)
{
    if (tree != nullptr) {
        PrintSorted(tree->leftBranch);
        cout << tree->Data << "\n";
        PrintSorted(tree->rightBranch);
    }
}

//Функция нахождения одинаковых ключей
int amount = 0;
void FindAmountGivenKey(char numberKey, binaryTree* aBranch)
{
    if (aBranch == nullptr) return;
    FindAmountGivenKey(numberKey, aBranch->leftBranch);
    if (aBranch->Data == numberKey) {
        amount++;
    }
    FindAmountGivenKey(numberKey, aBranch->rightBranch);

    return;
}
//Освобождение памяти
void FreeTree(binaryTree* aBranch)
{
    if (!aBranch) return;
    FreeTree(aBranch->leftBranch);
    FreeTree(aBranch->rightBranch);
    delete aBranch;
    return;
}

int main()
{
    setlocale(LC_ALL, "ru");
        int select;
     cin >> select;
     do
     {
         switch (select) {

             //ОДНОНАПРАВЛЕННЫЙ
         case 1:
             cout << "ОДНОНАПРАВЛЕННЫЙ\n";
             int quantity;
             //создание списка
             cout << "Введите размер Однонаправленного списка ";
             cin >> quantity;
             point1 *begin1=CreateList1(quantity);
             ShowList1(begin1);
             //Удаление чётных элементов
             cout << "\nСписок, после удаления чётных чисел \n";
             Delete(begin1);
             ShowList1(begin1);
             //Очищение списка
             ClearList1(begin1);
             break;

             //ДВУНАПРАВЛЕННЫЙ
         case 2:
             cout << "\n\n===============================================\n"<<
                 "Двунаправленный список\n";
             int quantity2;
             int position;

             //Создание
             cout <<"Введите размер Двунаправленного списка ";
             cin >> quantity2;
             point2* begin2 = CreateList2(quantity2);
             ShowList2(begin2);

             //Добавление
             cout << "\nВведите на какое место вставить новую строку ";
             cin >> position;
             AddElement(begin2, position);
             ShowList2(begin2);

             //Очищение
             ClearList1(begin2);
             break;

             //БИНАРНОЕ ДЕРЕВО
         case 3:
             cout << "\n\n=================================================\nБИНАРНОЕ ДЕРЕВО\nВведите кол-во элементов для будущего дерева: ";
             Branch* Root = 0;
             int quantityBT;
             char str;

             //Создание
             cin >> quantityBT;
             cout << "\n";
             Root = IdealTree(quantityBT, Root);
             cout << "Вывод бинарного дерева: \n";
             print(Root);

             //Нахождение ключа
             char numberKey;
             cout << "Введите строку для поиска ключа ";
             cin >> numberKey;
             FindAmountGivenKey(numberKey, Root);
             if (amount == 0) {
                 cout << "Нет такого числа\n ";
             }
             else {
                 cout << "Количество ключей с заданным значением " << amount << "\n";
             }
             is_Empty(Root);

             //Очищение памяти
             FreeTree(Root);
             cout << "\nВся динамическая память очищена..." << endl;
             break;
         }

     } while (select!=0);
    int quantity;
      //создание списка
      cout << "Введите размер Однонаправленного списка ";
      cin >> quantity;
      point1 *begin1=CreateList1(quantity);
      ShowList1(begin1);
      //Удаление чётных элементов
      cout << "\nСписок, после удаления чётных чисел \n";
      Delete(begin1);
      ShowList1(begin1);
      //Очищение списка
      ClearList1(begin1);
     //ДВУНАПРАВЛЕННЫЙ
       cout << "\n\n===============================================\n"<<
           "Двунаправленный список\n";
       int quantity2;
       int position;

       //Создание
       cout <<"Введите размер Двунаправленного списка ";
       cin >> quantity2;
       point2* begin2 = CreateList2(quantity2);
       ShowList2(begin2);

       //Добавление
       cout << "\nВведите на какое место вставить новую строку ";
       cin >> position;
       AddElement(begin2, position);
       ShowList2(begin2);
       //Очищение
       ClearList1(begin2);

       cout << "\n\n=================================================\nБИНАРНОЕ ДЕРЕВО\nВведите кол-во элементов для будущего дерева: ";
       Branch* Root = 0;
       int quantityBT;
       char str;
       //Создание
       cin >> quantityBT;
       cout << "\n";
       for (int i = 0; i < quantityBT; i++) {
           cout << "Ввеите строку ";
           cin >> str;
           Add(str, Root);
       }

    cout << "\n\n=================================================\nБИНАРНОЕ ДЕРЕВО\n";
    binaryTree* root = 0;
    int quantityBT;

    //Создание Идеально сбалансированное дерева
    cout << "\nВведите размер будущего дерева ";
    cin >> quantityBT;
    root=IdealBalanceTree(quantityBT, root);
    int j = myVector.size();
    cout << "SIZE VECTOR " << j << "\n";
    // ПЕЧАТЬ ДЕРЕВА
    cout << "\nПечать дерева \n";
    PrintTree(root);
    
    //ПРЕОБРАЗОВАНИЕ ИДЕАЛЬНОГО В ПОИСК
    SearchTree(myVector[0], root);
    cout << "\nДерево после сортировки \n";
    PrintSorted(root);

    //Нахождение ключа
    char numberKey;
    cout << "\nВведите строку для поиска ключа ";
    cin >> numberKey;
    FindAmountGivenKey(numberKey, root);
    if (amount == 0) {
        cout << "Нет такого числа\n ";
    }
    else {
        cout << "Количество ключей с заданным значением " << amount << "\n";
    }



    //Очищение памяти
    FreeTree(root);
    cout << "\nВся динамическая память очищена..." << endl;

}
