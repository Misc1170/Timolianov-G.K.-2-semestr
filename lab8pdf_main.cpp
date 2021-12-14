#include"Person.h"
#include"Student.h"
#include"Dialog.h"
#include"Vector.h"

void main() {
	setlocale(LC_ALL, "ru");

	cout << "\n\nPART 1 \n";

	cout << "Человек ";
	Person* a = new Person;
	a->Input();
	a->Show();
	
	cout << "\nСтудент ";
	Student* b = new Student;
	b->Input();
	b->Show();

	cout << "\n\nPART 2 \n";
	Vector v(3);

	Object* p = a;
	v.Add(p);

	p = b;
	v.Add(p);

	cout << "\n\nРазмер Вектора " << v();

	v.Show();
	v.Del();
	
	cout << "\n\nPART 3 \n";


	Dialog D;
	D.Execute();

}