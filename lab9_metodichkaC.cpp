#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct abt {
	bool valid = false;
	char surname[20];
	char name[20];
	char middlename[20];
	int gr;
	int ocenki[3];
	float att;
	int id;
};

void View(abt st) { //Просмотр 
	if (st.valid == true) {
		printf("\n=============");
		printf("Абитуриент: %d \n", st.id);
		printf("Фамилия %s \n", st.surname);
		printf("Имя %s\n", st.name);
		printf("Отчество %s\n", st.middlename);
		printf("Год рождения %d\n", st.gr);
		printf("Оценки за 3 экзамена \n");
		printf("\tИнформатика %d\n", st.ocenki[0]);
		printf("\tАлгебра %d\n", st.ocenki[1]);
		printf("\tРусский язык %d\n", st.ocenki[2]);
		printf("Ср. балл аттестата %10.1f\n", st.att);
	}
}
//Создание
void Create() {
	int i;
	int k = 3;
	abt st;
	FILE* file;
	if ((file = fopen("file.bin", "wb")) == NULL) {
		puts("Не могу открыть файл!!! ");
		exit;
	}
	for (i = 0; i < k; i++) {
		printf("\nАбитуриент %d\n", i + 1);
		st.id = i + 1;
		printf("Фамилия ");
		scanf("%s", &st.surname);
		printf("Имя ");
		scanf("%s", &st.name);
		printf("Отчество ");
		scanf("%s", &st.middlename);
		printf("Год рождения ");
		scanf("%d", &st.gr);
		printf("Оценки за 3 экзамена \n");
		printf("\tИнформатика ");
		scanf("%d", &st.ocenki[0]);
		printf("\tАлгебра ");
		scanf("%d", &st.ocenki[1]);
		printf("\tРусский язык ");
		scanf("%d", &st.ocenki[2]);
		printf("Ср. балл аттестата ");
		scanf("%f", &st.att);
		st.valid = true;
		fwrite(&st, sizeof(abt), 1, file);
		if (ferror(file) == NULL) {
			exit;
		}
	}
	fclose(file);
}
//Чтение
void Read()
{
	int i = 0;
	int k = 3;
	const int A = 5;
	abt abbts[A];
	FILE* file;

	if ((file = fopen("file.bin", "rb, ccs=UTF-8")) == NULL) {
		puts("Не могу открыть файл!!");
		exit;
	}
	while (!feof(file) && i <= A) {
		fread(&abbts[i], sizeof(abt), 1, file);
		i++;
	}
	for (int i = 0; i < A; i++) {
		View(abbts[i]);
	}
	fclose(file);
}
//Удаление
void Delete() {
	int i = 0, selection, n;
	int k = 3;
	const int A = 3;
	abt abbts[A];
	abt tmp[A - 1];
	FILE* file;
	if ((file = fopen("file.bin", "rb")) == NULL) {
		puts("\nНе могу открыть файл");
		exit;
	}
	while (!feof(file) && i <= A) {
		fread(&abbts[i], sizeof(abt), 1, file);
		i++;
	}
	for (i = 0; i < A; i++) {
		View(abbts[i]);
		if (ferror(file) == NULL) {
			exit;
		}
	}
	fclose(file);
	printf("\nВыберите абт для удаления: ");
	scanf("%d", &n);
	n--;
	if ((file = fopen("file.bin", "wb")) == NULL) {
		puts("\nНе могу открыть файл");
		exit;
	}
	for (i = 0; i < k; i++) {
		tmp[i] = abbts[i];
	}
	for (i = n; i < k; i++) {
		tmp[i] = abbts[i + 1];
	}
	for (i = 0; i < A - 1; i++) {
		View(tmp[i]);
		fwrite(&tmp[i], sizeof(abt), 1, file);
		if (ferror(file) == NULL) {
			exit;
		}
	}
	if ((A - 1) == 0) {
		printf("\nВсе аббитуриенты были удалены");
		exit;
	}
	fclose(file);
}
//Вставка
void Insert() { 
	int i = 0, selection, n;
	int k = 3;
	const int A = 3;
	abt abbts[A];
	abt tmp[A + 1];
	FILE* file;
	if ((file = fopen("file.bin", "rb")) == NULL) {
		puts("\nНе могу открыть файл");
		exit;
	}
	while (!feof(file) && i <= A) {
		fread(&abbts[i], sizeof(abt), 1, file);
		i++;
	}
	for (i = 0; i < A; i++) {
		View(abbts[i]);
		if (ferror(file) == NULL) {
			exit;
		}
	}
	fclose(file);
	int found = 0;
	if ((file = fopen("file.bin", "wb")) == NULL) {
		puts("\nНе могу открыть файл");
		exit;
	}
	// Записываем нового студента
	abt st;
	int flag = 0;
	for (i = 0; i < A; i++) {
		if (i == 0) {
			printf("\nВведите данные нового элемента ");
			printf("\n===========Абитуриент %d\n", i + 1);
			st.id = i + 1;
			printf("Фамилия ");
			scanf("%s", &st.surname);
			printf("Имя ");
			scanf("%s", &st.name);
			printf("Отчество ");
			scanf("%s", &st.middlename);
			printf("Год рождения ");
			scanf("%d", &st.gr);
			printf("Оценки за 3 экзамена \n");
			printf("\tИнформатика ");
			scanf("%d", &st.ocenki[0]);
			printf("\tАлгебра ");
			scanf("%d", &st.ocenki[1]);
			printf("\tРусский язык ");
			scanf("%d", &st.ocenki[2]);
			printf("Ср. балл аттестата ");
			scanf("%f", &st.att);
			st.valid = true;
			tmp[i] = abbts[i];
			tmp[i] = st;
			flag = 1;
			//continue;
		}
		int j = i;
		if (flag == 1) {
			j++;
		}
		tmp[j] = abbts[i];
	}
	for (i = 0; i < A + 1; i++) {
		fwrite(&tmp[i], sizeof(abt), 1, file);
		if (ferror(file) == NULL) {
			exit;
		}
		View(tmp[i]);
	}
	fclose(file);
}

	int main() {
		setlocale(LC_ALL, "Rus");
		int select;
		do {
			printf("\n\nВыберите действие: ");
			printf("\n1.Создание аббитуриента ");
			printf("\n2.Отображение ");
			printf("\n3.Удаление ");
			printf("\n4.Вставить ");
			printf("\n0.Выход \n");
			scanf("%d", &select);
			if (select == 1) {
				Create();
			}
			if (select == 2) {
				Read();
			}
			if (select == 3) {
				Delete();
			}
			if (select == 4) {
				Insert();
			}
		} while (select != 0);

		return 0;
	}