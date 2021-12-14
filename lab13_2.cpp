#include <iostream>
#include"C:\Users\sloop\OneDrive\Рабочий стол\Тичинг в ПОЛИКе\Основы алгоритмизации и програмирования\Лабораторные 2 семсетр\lab11_2\Time.h"
#include<stack>
#include <vector>
#include<algorithm>
using namespace std;

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
        cout << i + 1 << ".  " << myStack.top() << "\n";
        myStack.pop();
        i++;
    }
}

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

Time FindMiddleArith(Stack myStack)
{
    Vector myVector = CopyStackToVector(myStack);
    Time summa;
    int numbers = myStack.size();
    while (!myStack.empty()) {
        summa = summa + myStack.top();
        myStack.pop();
    }
    cout << "\nСумма " << summa << "\n";
    myStack = CopyVectorToStack(myVector);
    return summa / numbers;
}

void AddMiddleArith(Stack& myStack, Time middleArith)
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

typedef stack<Time>Stack;
Time maxElement;
struct maxElementstr {
    bool operator()(Time time) {
        return time == maxElement;
    }
};

typedef stack<Time>Stack;
Time minElement;
struct minElementstr {
    bool operator()(Time time) {
        return time == minElement;
    }
};


int main()
{
    setlocale(LC_ALL,"ru");
    int quantity;
    Stack myStack;
    Vector myVector;
    cout << "Введите размер Stack ";
    cin >> quantity;
    //создание стека
    myStack = CreateStack(quantity);
    ShowStack(myStack);

    //Найти и заменить максим элемент
    Time newValue;
    myVector = CopyStackToVector(myStack);
    auto maxIt = max_element(myVector.begin(), myVector.end());
    maxElement = *(maxIt);
    cout << "Максимальный элемент " << maxElement << "\n";
    myVector = CopyStackToVector(myStack);
    cout << "Введите новый элемент ";
    cin >> newValue;
    replace_if(myVector.begin(), myVector.end(), maxElementstr(), newValue);
    myStack = CopyVectorToStack(myVector);
    ShowStack(myStack);

    //Найти и удалить минимальный элемент
    myVector = CopyStackToVector(myStack);
    auto minIt = min_element(myVector.begin(), myVector.end());
    minElement = *(minIt);
    cout << "Минимальный элемент " << minElement << "\n";
    auto elForDel = remove_if(myVector.begin(), myVector.end(), minElementstr());
    myVector.erase(elForDel, myVector.end());
    myStack = CopyVectorToStack(myVector);
    ShowStack(myStack);

    //Добавление среднего арифметичческого
    Time middleArith = FindMiddleArith(myStack);
    cout << "Среднее арифметическое " << middleArith;
    AddMiddleArith(myStack, middleArith);
    ShowStack(myStack);
}
