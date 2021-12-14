#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "mariculant.h"
using namespace std;



//С++ Создание массива
Matriculant* CreateMatriculant(int sizeStructure)
{
	Matriculant* matriculant = new Matriculant[sizeStructure];

	for (int i = 0; i < sizeStructure; i++) {
		cout << "\n=====Аббитуриент " << i + 1 << "=====\n";
		cout<<"\nВведите имя ";
		cin>>matriculant[i].name;
		cout << "\nВведите фамилию ";
		cin >> matriculant[i].surName ;
		cout << "\nВведите Отчество ";
		cin >> matriculant[i].middleName;
		cout << "\nВведите год рождения ";
		cin >> matriculant[i].yearBirthday;
		cout << "\nВведите оценки вступительных экзаменов:\n ";
		cout << "\nРусский язык ";
		cin >> matriculant[i].rus ;
		cout << "\nМатематика ";
		cin >> matriculant[i].math ;
		cout << "\nИнформатика ";
		cin >> matriculant[i].computerScience ;
		cout << "\nСредний балл аттестата ";
		cin >> matriculant[i].averageScore ;
	}
	return matriculant;
}

//Отображение в консоли
void ShowMatriculant(int sizeStructure, Matriculant* matriculant)
{
	for (int i = 0; i < sizeStructure; i++) {
		cout << "\n=====Аббитуриент " << i + 1 << "=====\n";
		cout << "\n имя ";
		cout << matriculant[i].name;
		cout << "\n фамилию ";
		cout << matriculant[i].surName;
		cout << "\n Отчество ";
		cout << matriculant[i].middleName;
		cout << "\n год рождения ";
		cout << matriculant[i].yearBirthday;
		cout << "\n оценки вступительных экзаменов: ";
		cout << "\n\tРусский язык ";
		cout << matriculant[i].rus;
		cout << "\n\tМатематика ";
		cout << matriculant[i].math;
		cout << "\n\tИнформатика ";
		cout << matriculant[i].computerScience;
		cout << "\nСредний балл аттестата ";
		cout << matriculant[i].averageScore;
		cout << "\n\n";
	}
}

//Запись в файл
void WritingToFile(int sizeStructure, Matriculant* matriculant)
{
	matriculant = new Matriculant[sizeStructure];
	fstream file;
	file.open("file.txt", ios::out);
	for (int i = 0; i < sizeStructure; i++) {
		file << matriculant[i].name << "\n";
		file << matriculant[i].surName << "\n";
		file << matriculant[i].middleName << "\n";
		file << matriculant[i].yearBirthday << "\n";
		file << matriculant[i].rus << "\n";
		file << matriculant[i].math << "\n";
		file << matriculant[i].computerScience << "\n";
		file << matriculant[i].averageScore << "\n";
	}
	file.close();
}

//Чтение из файла в консоль
void ReadingFromFile(int sizeStructure,Matriculant matriculant)
{
	ifstream file;
	file.open("file.txt", ios::in);
	Matriculant temp;
	int i = 1;
	int j = 0;
	do {
		cout << "\n\n=====Аббитуриент " << i << "=====\n";
		file >> temp.name;
		cout << "\nИмя " << temp.name;
		file >> temp.surName;
		cout << "\nФамилия " << temp.surName;
		file >> temp.middleName;
		cout << "\nОтччество " << temp.middleName;
		file >> temp.yearBirthday;
		cout << "\nГод рождения " << temp.yearBirthday;
		cout << "\nОценки вступительных экзаменов:\n";
		file >> temp.rus;
		cout << "\n\tРусский язык " << temp.rus;
		file >> temp.math;
		cout << "\n\tМатематика " << temp.math;
		file >> temp.computerScience;
		cout << "\n\tИнформатика " << temp.computerScience;
		file >> temp.averageScore;
		cout << "\nСредний балл аттестата " << temp.averageScore;
		i++;
		j ++;
		if (j==sizeStructure) {
			break;
		}
	} while (!file.eof());
	file.close();
}

//Удаление элемента
void DeleteElement(int delElem,int sizeStructure, Matriculant matriculant)
{
	fstream file("file.txt", ios::in);
	if (file.is_open()) {
		cout << "FILE OPEN!\n";
	}
	else {
		cout << "FILE NO OPEN\n";
	}

	fstream temp("temp.txt", ios::out);
	if (temp.is_open()) {
		cout << "TEMP OPEN\n";
	}
	else {
		cout << "TEMP NO OPEN!\n";
	}

	Matriculant matrTmp;
	for (int i = 0; i < sizeStructure; i++) {
		if (i+1 != delElem) {
			file >> matrTmp.name;
			temp << matrTmp.name << "\n";
			file >> matrTmp.surName;
			temp << matrTmp.surName << "\n";
			file >> matrTmp.middleName;
			temp << matrTmp.middleName << "\n";
			file >> matrTmp.yearBirthday;
			temp << matrTmp.yearBirthday << "\n";
			file >> matrTmp.rus;
			temp << matrTmp.rus << "\n";
			file >> matrTmp.math;
			temp << matrTmp.math << "\n";
			file >> matrTmp.computerScience;
			temp << matrTmp.computerScience << "\n";
			file >> matrTmp.averageScore;
			temp << matrTmp.averageScore << "\n\n";
		}
	}
	file.close();
	temp.close();
	if (remove("file.txt") != 0) {
		cout << "\nНЕ УДАЛИЛСЯ!\n";
	}
	else {
		cout << "\n\nУДАЛИЛСЯ!\n";
	}

	if (rename("temp.txt", "file.txt") == 0) {
		cout << "\nФайл переименован успешно\n";
	}
	else {
		cout << "\nБОРОДА!!!\n";
	}


}

//Добавление элементов
void AddElementsInBeginFile(int amount, int sizeStructure, Matriculant *matriculant)
{
	fstream file("file.txt", ios::in);
	if (file.is_open()) {
		cout << "FILE OPEN!\n";
	}
	else {
		cout << "FILE NO OPEN\n";
	}

	fstream temp("temp.txt", ios::out);
	if (temp.is_open()) {
		cout << "TEMP OPEN\n";
	}
	else {
		cout << "TEMP NO OPEN!\n";
	}

	Matriculant *matrTmp = new Matriculant[sizeStructure];
	//создание новых элементов
		matrTmp = CreateMatriculant(amount);

	for (int i = 0; i < amount; i++) {
		temp << matrTmp[i].name << "\n";
		temp << matrTmp[i].surName << "\n";
		temp << matrTmp[i].middleName << "\n";
		temp << matrTmp[i].yearBirthday << "\n";
		temp << matrTmp[i].rus << "\n";
		temp << matrTmp[i].math << "\n";
		temp << matrTmp[i].computerScience << "\n";
		temp << matrTmp[i].averageScore << "\n";
	}

	for (int i = 0; i < sizeStructure; i++) {
		temp << matriculant[i].name << "\n";
		temp << matriculant[i].surName << "\n";
		temp << matriculant[i].middleName << "\n";
		temp << matriculant[i].yearBirthday << "\n";
		temp << matriculant[i].rus << "\n";
		temp << matriculant[i].math << "\n";
		temp << matriculant[i].computerScience << "\n";
		temp << matriculant[i].averageScore << "\n";
	}
	file.close();
	temp.close();
	if (remove("file.txt") != 0) {
		cout << "\nНЕ УДАЛИЛСЯ!\n";
	}
	else {
		cout << "\n\nУДАЛИЛСЯ!\n";
	}

	if (rename("temp.txt", "file.txt") == 0) {
		cout << "\nФайл переименован успешно\n";
	}
	else {
		cout << "\nБОРОДА!!!\n";
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	int sizeStructure =0;
	int delElem;
	int amount;
	int choice = 0;
	Matriculant* matriculant = new Matriculant;
	cout << "Введите количество аббитуриентов ";
	cin >> sizeStructure;
		//СОЗДАНИЕ
		cout << "Создание\n";
		matriculant = CreateMatriculant(sizeStructure);
		cout << "\nВывод на экран!!!!!!!:\n";
		ShowMatriculant(sizeStructure, matriculant);
		//ЗАПИСЬ В ФАЙЛ
		cout << "\nЗАПИСЬ В ФАЙЛ \n";
		WritingToFile(sizeStructure, matriculant);
		//ЧТЕНИЕ ИЗ ФАЙЛА
		cout << "\nЧТЕНИЕ ИЗ ФАЙЛА\n";
		ReadingFromFile(sizeStructure, *matriculant);
		//УДАЛЕНИЕ
		cout << "\nВведите, какой элемент удалить ";
		cin >> delElem;
		DeleteElement(delElem, sizeStructure, *matriculant);
		//ДОБАВЛЕНИЕ В НАЧАЛО
		cout << "Введите количество новых элементов для добавление в начало ";
		cin >> amount;
		AddElementsInBeginFile(amount, sizeStructure, matriculant);
		cout << "\nВывод на экран!!!!!!!:\n";
		ReadingFromFile(sizeStructure + amount, *matriculant);
	
	

}
