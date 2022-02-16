#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int id = 0;
    int day = 0;
    int celsius = 0;
    int deleteTag = false;

    Node* next;
    Node(int _id, int _day, int _celsius) : id(_id), day(_day), celsius(_celsius), next(NULL) {}
};
struct weather {
    Node* first;
    Node* last;
    weather() : first(NULL), last(NULL) {}

    bool is_empty() {
        return first == NULL;
    };
    
    void pushFront() {
        int _id = 1;
        int _day = 0;
        int _celsius = 0;
        cout << "Введите день";
        cin >> _day;
        cout << "Введите градусы";
        cin>> _celsius;
        Node* element = new Node(_id, _day, _celsius);
        if (is_empty()) {
            first = element;
            return;
        }
        Node* temp = element;
        temp->next = first;
        first = temp;
        while (temp->next != NULL) {
            temp = temp->next;
            temp->id++;
        }
        
    }

    void pushBack(int _id) {
        int _day, _celsius = 0;
        cout << "Введите день ";
        cin >> _day;
        cout << "Введите градусы ";
        cin >> _celsius;
        if (!is_empty()) {
            _id = 2;
            Node* temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
                _id++;
            }
        }
        Node* element = new Node(_id,_day, _celsius);
        if (is_empty()) {
            first = element;
            last = element;
            return;
        }
        last->next = element;
        last = element;
    }

    void pushAnyPlace(int _id) {
        int _day = 0, _celsius = 0;
        if (is_empty()) {
            pushFront();
            return;
        }
        if (_id == 1) {
            pushFront();
            return;
        }
        if (_id == last->id) {
            pushBack(_id);
            return;
        }
        cout << "Введите данные для нового элемента: \n";
        cout << "День \n";
        cin >> _day;
        cout << "Градусы \n";
        cin >> _celsius;
        Node* temp = first;
        Node* element = new Node(_id, _day, _celsius);
        while (temp && temp->id != _id - 1) {
            temp = temp->next;
        }
        element->next = temp->next;
        temp->next = element;
    }

    void show() {
        if (is_empty()) {
            return;
        }
        Node* element = first;
        while (element) {
            cout << "\nID " << element->id;
            cout << "\n\tДень " << element->day;
            cout << "\n\tГрадусы " << element->celsius;
            element = element->next;
            cout << endl;
        }
        cout << endl;
    }
    //searh
    /*Node* search() {
        if (is_empty()) {
            return NULL;
        }
        int _id;
        cout << "Какой элемент найти? \n";
        cin >> _id;
        Node* element = first;
        while (element && element->id != _id) {
            element = element->next;
            if (element && element->id == _id) {
                cout << "Нашёлся элемент " << element->id << "\n";
                return element;
            }
        }    
    }*/

    void remove_first() {
        if (is_empty()) {
            return;
        }
        cout << "Удаление первого \n";
        Node* element = first;
        first = element->next;
        delete element;
    }

    void remove_last() {
        if (is_empty()) {
            return;
        }
        cout << "Удаление последнего \n";
        if (first == last) {
            remove_first();
            return;
        }
        Node* element = first;
        while (element->next != last) {
            element = element->next;
        }
        element->next = NULL;
        delete last;
        last = element;
    }

    void remove_any() {
        if (is_empty()) {
            return;
        }
        int removeSelect = 0;
        cout << "Какой элемент удалить? \n";
        cin >> removeSelect;
            if (first->id == removeSelect) {
                remove_first();
                return;
            }
            else if (last->id == removeSelect) {
                remove_last();
                return;
            }
            Node* slow = first;
            Node* fast = first->next;
            while (fast && fast->id != removeSelect) {
                fast = fast->next;
                slow = slow->next;
            }
            if (!fast) {
                cout << "Этот элемент не найден\n";
                return;
            }
            slow->next = fast->next;
            delete fast;
    }

    void correct(int _id) {
        if (is_empty()) {
            cout << "Список пуст!";
            return;
        }
        cout << "Введите новые градусы";
        int newCelsius;
        cin >> newCelsius;
        Node* temp = first;
        while (temp->id != _id) {
            temp = temp->next;
        }
        temp->celsius = newCelsius;
    }

    int CreateID() {
        if (is_empty()) {
            return 0;
        }
        int id = 1;
        Node* temp = first;
        while (temp != NULL) {
            temp->id = id;
            id++;
            temp = temp->next;
        }
        return id;
    }

    void Write() {
        ofstream dataBase;
        dataBase.open("data.txt", ios_base::out);
        if (!dataBase.is_open()) {
            cout << "Файл не может быть открыт!";
            return ;
        }
        Node* temp = first;
        while (temp != NULL) {
            dataBase << " " << temp->id <<" " << temp->day << " " << temp->celsius ;
            temp = temp->next;
        }
        dataBase.close();
        cout << "Запись успешна!\n";
    }

    void Read() {
        ifstream dataBase;
        dataBase.open("data.txt", ios_base::in);
        if (!dataBase.is_open()) {
            cout << "\nФайл не открылся!";
            return;
        }
        if (dataBase.eof()) {
            cout << "Файл пустой!";
            return;
        }
        Node* temp = new Node(0,0,0);
        first = temp;
        while (!dataBase.eof()) {
            dataBase >> temp->id >> temp->day >> temp->celsius;
            cout << "\nID: "<< temp->id <<
                    "\nДень: " << temp->day <<
                    "\nГрадусы: " << temp->celsius;
            if (!dataBase.eof()) {
                temp->next = new Node(0, 0, 0);
            }
            temp = temp->next;
        }
        dataBase.close();
        temp = first;
        while (temp != NULL) {
            last = temp;
            temp = temp->next;
        }
        cout << "\nЧтение успешно!\n";
    }

    int avrCelsius() {
        if (is_empty()) {
            cout << "Список пуст!";
            return 0;
        }
        int avr = 0;
        int i = 0;
        Node* temp = first;
        while (temp != NULL) {
            i++;
            avr += temp->celsius;
            temp = temp->next;
        }
        return avr / i;
    }

    void dayAboveAvr(int avr) {
        if (is_empty()) {
            cout << "Список пуст!";
            return;
        }
        Node* temp = first;
        int i = 0;
        int countList = CreateID();
        int* dayAboveAvr = new int[countList];
        while (temp != NULL) {
            if (temp->celsius > avr) {
                dayAboveAvr[i] = temp->day;
                i++;
            }
            temp = temp->next;
        }
        cout << "\nДни, которые выше средней температуры\n";
        for (int j = 0; j < i; j++) {
            cout << dayAboveAvr[j] << '\n';
        }
        delete[] dayAboveAvr;
    }

    void lenghtsOfDays() {
        if (is_empty()) {
            cout << "Список пуст!";
            return;
        }
        Node* temp = first;
        int lenghts = 0, currentLenghts = 0, prevLenghts = 0;
        while (temp != NULL) {
            if (temp->celsius < 0) {
                currentLenghts++;
            }
            else {
                currentLenghts = 0;
            }
            if (currentLenghts >= 2) {
                prevLenghts = currentLenghts;
            }
            temp = temp->next;
        }
        cout << "Самый длинный отрезок: " << prevLenghts << '\n';
    }  

};

int main() {
    setlocale(LC_ALL, "rus");
    weather w;
    int quantity = 0, celsius = 0, select = 0, avr = 0, countID = 0;;
    int id = 1, day = 1;
    int avrCelsius = 0;
    do {
        cout << "Выберите действие:\n"
            "1) Создание списка.\n"
            "2) Показать список\n"
            "3) Удалить элемент по ID\n"
            "4) Добавление в начало\n"
            "5) Добавление в конец\n"
            "6) Добавление с заданным номером\n"
            "7) Изменения значений\n"
            "8) Запись в файл\n"
            "9) Чтение из файла\n"
            "10) Дни выше средней температуры\n"
            "11) Отрезок дней с -температурой\n";
        cin >> select;
        switch (select) {
            //Создание списка
        case 1:
            cout << "Введите количество дней ";
            cin >> quantity;
            for (int i = 0; i < quantity; i++) {
                w.pushBack(id);
                id++;
                day++;
            }
            w.CreateID();
            break;
            //Печать списка
        case 2:
            w.show();
            break;
            //Удаление любого
        case 3:
            w.remove_any();
            w.CreateID();
            break;
            //Добавлеие вперёд
        case 4:
            w.pushFront();
            w.CreateID();
            break;
            //Добавление в конец
        case 5:
            w.pushBack(id);
            w.CreateID();
            break;
            //Вставка в любое место
        case 6:
            int insert;
            cout << "На какое место вставить новый элемент? \n";
            cin >> insert;
            w.pushAnyPlace(insert);
            w.CreateID();
            break;
            //Изменение значений
        case 7:
            int insert2;
            cout << "Какой элемент изменить?";
            cin >> insert2;
            w.correct(insert2);
            break;
            //Запись в файл
        case 8:
            w.Write();
            break;
            //Чтение
        case 9:
            w.Read();
            break;
            //Количество дней, температура которой выше среднего
        case 10:
            avrCelsius = w.avrCelsius();
            cout << "Средняя температура: " << avrCelsius << '\n';
            w.dayAboveAvr(avrCelsius);
            break;
            //отрезок дней с - температурой
        case 11:
            w.lenghtsOfDays();
            break;
        }
    } while (select != 0);

}

//непонятно методическое указание №3 про пометку удаления