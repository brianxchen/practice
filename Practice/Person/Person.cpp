#include "Person.h"
Person::Person() {
	cout << "\nConstructing person";
}
Person::Person(int age, string name, bool isMale) {
	this->age = age;
	this->name = name;
	this->isMale = isMale;
}

Person::~Person() {
	//cout << "\nDestruct person";
}

void Person::Print() {
	cout << ToString();
}

string Person::ToString() const {
	return "Age = " + to_string(this->age) + ", name = " + this->name + ", isMale = " + to_string(this->isMale);
}

void Person::IncreaseAge()
{
	this->age++;
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
	delete[] heapPeople;
	delete[] heapPeoplePointer;
	

	/*cout << "Enter your age: ";
	int age;
	cin >> age;

	cout << "your age is " << age << "\n";

	cout << "Enter your name: ";
	string name;
	cin >> name;
	cout << "your name is " << name << "\n";

	printf("Enter your age: ");
	scanf_s("%d", &age);
	printf("\nYour age is %d", age);

	char hobby[20];
	printf("\nEnter your hobby: ");
	scanf_s("%s", hobby, 20);
	printf("\nYour hobby is %s", hobby);


	char *newhobby = new char[20];
	printf("\nEnter your hobby: ");
	scanf_s("%s", newhobby, 20);
	printf("\nYour hobby is %s", newhobby);
	*/
}

void f() {
	cout << "\nEnter f ";
	for(int i = 0; i < 5; i++){
		Person b;
		cout << "\n" << i;
	}
	Person a;
	cout << "\nExit f";
}

void g() {
	cout << "\nEnter g ";
	Person* a = new Person();
	delete a;
	cout << "\nExit g";
}

void TestDestructors() {
	f();
	g();
}


bool CompareAge(Person a, Person b) {
	return a.age > b.age;
}

void SortAge(vector<Person> listPeople) {
	vector<Person>::iterator it = listPeople.begin();

	sort(listPeople.begin(), listPeople.end(), CompareAge);

	for (auto x : listPeople)
		cout << x.ToString() << " ";
}

bool CompareName(Person a, Person b) {
	return a.name > b.name;
}


void SortName(vector<Person> listPeople) {
	vector<Person>::iterator it = listPeople.begin();

	sort(listPeople.begin(), listPeople.end(), CompareName);

	for (auto x : listPeople)
		cout << x.ToString() << " ";
}

void TestSorter() {
	vector<Person> listOfPeople = { Person(1, "a", false), Person(3, "d", false), Person(2, "b", false) };
	SortName(listOfPeople);
}

