#include "Person.h"
Person::Person() {

}
Person::Person(int age, string name, bool isMale) {
	this->age = age;
	this->name = name;
	this->isMale = isMale;
}

void Person::Print() {
	cout << "Age = " << age << ", name = " << name << ", isMale = " << isMale;
}


void TestPerson() {
	cout << "size of int = " << sizeof(int) << ", size of string = " << sizeof(string) << ", size of bool = " << sizeof(bool);
	cout << "\nsize of int* = " << sizeof(int*) << ", size of string* = " << sizeof(string*) << ", size of bool* = " << sizeof(bool*);
	cout << "\nsize of void* = " << sizeof(void*);
	Person stackPerson(10, "stackperson", true);
	cout << "\nsize of stackperson = " << sizeof(stackPerson);

	Person *heapPerson = new Person(10, "heapperson", true);
	cout << "\nsize of heapperson = " << sizeof(heapPerson);

	Person stackPeople [10];
	cout << "\nsize of stackpeople = " << sizeof(stackPeople) << ",length = " << sizeof(stackPeople)/sizeof(stackPeople[0]);

	Person* heapPeople = new Person[10];
	cout << "\nsize of heappeople = " << sizeof(heapPeople) << ", ";
	
	Person* stackPeoplePointer[10];
	cout << "\nstackPeoplePointer size = " << sizeof(stackPeoplePointer);


	Person** heapPeoplePointer = new Person*[10];
	cout << "\nheapPeoplePointer size = " << sizeof(heapPeoplePointer);

	delete heapPerson;
	delete heapPeople;
	delete heapPeoplePointer;

}