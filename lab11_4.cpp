#include <iostream>
#include <stack>
#include <vector>
#include "C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"

typedef stack<Time>Stack;
typedef vector<Time>Vector;

Stack CreateStack(int n)
{
    Stack myStack;
    Time time;
    for (int i = 0; i < n; i++) {
        cout << "Введите данные для Stack:\n";
        cin >> time;
        myStack.push(time);
    }
    return myStack;
}

void ShowStack(Stack myStack)  
{
    int i = 0;
    cout << "\nДанные Stack\n";
    
    while (!myStack.empty()) {
        cout << i+1 << ".  " << myStack.top() << "\n";
        myStack.pop();
        i++;
    }
}

//void ShowStack(Stack myStack)  2 вариант(визуально легче)
//{
//    int i = 0;
//    cout << "\nДанные Stack\n";
//    int position = myStack.size();
//    while (!myStack.empty()) {
//        cout << position << ".  " << myStack.top() << "\n";
//        myStack.pop();
//        position--;
//    }
//}

Vector CopyStackToVector(Stack myStack)
{
    Vector myVector;
    while (!myStack.empty()) {
        myVector.push_back(myStack.top());
        myStack.pop();
   }
    return myVector;
}

Stack CopyVectorToStack(Vector myVector)
{
    Stack myStack;
    for (int i = 0; i < myVector.size(); i++) {
        myStack.push(myVector[i]);
    }
    return myStack;
}

Time FindMaxElement(Stack myStack)
{
    Vector myVector = CopyStackToVector(myStack);
    Time maxElement = myStack.top();
    myStack.pop();
    while (!myStack.empty()) {
        if (maxElement < myStack.top()) {
            maxElement = myStack.top();
        }
        myStack.pop();
    }
    cout << "\nМаксимальное значение " << maxElement << "\n";
    myStack = CopyVectorToStack(myVector);
    return maxElement;
}

void AddMaxElement(Stack &myStack,Time maxElement)
{
    Vector temp = CopyStackToVector(myStack);
    Vector myVector;
    Time time;
    int i = 0;
    for (int i = 0; i < temp.size(); i++) {
        time = temp[i];
        myVector.push_back(time);
    }
    myVector.push_back(maxElement);
    myStack = CopyVectorToStack(myVector);
}

int FindMinElement(Stack myStack)
{
    Vector myVector = CopyStackToVector(myStack);
    Time minElement = myStack.top();
    myStack.pop();
    int position = myStack.size();
    while (!myStack.empty()) {
        if (minElement > myStack.top()) {
            minElement = myStack.top();
        }
        myStack.pop();
        position--;
    }
    cout << "\nНомер минимального элемента " << position + 1
            <<" Минимальный элемент "<<minElement << "\n";
    myStack = CopyVectorToStack(myVector);
    return position;
}

void DeleteMinElement(Stack &myStack, int position)
{
    int i = 0;
    Vector myVector;
    Time time;
    while (!myStack.empty()) {
        time = myStack.top();
        if (i != position) {
            myVector.push_back(time);
        }
        myStack.pop();
        i++;
    }
    myStack = CopyVectorToStack(myVector);
}

Time FindMiddleArith(Stack myStack)
{
    Vector myVector = CopyStackToVector(myStack);
    Time summa;
    int numbers = myStack.size();
    while (!myStack.empty()) {
        summa =summa+ myStack.top();
        myStack.pop();
    }
    cout << "\nСумма " << summa << "\n";
    myStack = CopyVectorToStack(myVector);
    return summa / numbers;
}

void AddMiddleArith(Stack &myStack, Time middleArith)
{
    Vector myVector = CopyStackToVector(myStack);
    Vector temp;
    Time time;
    int i = 0;
    while (!myStack.empty()) {
        time = myStack.top() + middleArith;
        myStack.pop();
        temp.push_back(time);
    }
    myStack = CopyVectorToStack(temp);
}

int main()
{
    setlocale(LC_ALL, "ru");
    Time time;
    Stack myStack;
    Time maxElement;
    Time middleArith;
    int position;
    int quantity;
    cout << "Введите размер Stack ";
    cin >> quantity;
    //создание стека
    myStack = CreateStack(quantity);
    ShowStack(myStack);
    //Найти и добав макс эелемент в начало
    maxElement = FindMaxElement(myStack);
    AddMaxElement(myStack,maxElement);
    cout << "Stack после добавления максимального элемента ";
    ShowStack(myStack);
    //Найти и удалить мин элемент из стека
    position = FindMinElement(myStack);
    DeleteMinElement(myStack, position);
    cout << "Stack после удаления минимального элемента ";
    ShowStack(myStack);
    //Добавление среднего арифметичческого
    middleArith = FindMiddleArith(myStack);
    cout << "Среднее арифметическое " << middleArith;
    AddMiddleArith(myStack, middleArith);
    ShowStack(myStack);
}
