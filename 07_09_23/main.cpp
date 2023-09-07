#include<iostream>
using namespace std;

class Student
{
	char* name;
	char* email;
	int age;
public:
	Student()
	{
		cout << "Constructor by def.\n";
		name = nullptr;
		email = nullptr;
		age = 0;
	}
	Student(const char* n, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		cout << "Constructor 2 params\n";
	}
	Student(const char* n, int a, const char* e)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
		cout << "Constructor 3 params\n";
	}
	void Input()
	{
		char buff[20];
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter email: ";
		cin >> buff;
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
	}
	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
	~Student()
	{
		delete[] name;
		delete[] email;
		cout << "Destructor\n";
	}
	void SetName(const char* n)
	{
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[]name;
		}
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetEmail(const char* e)
	{
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[]email;
		}
		strcpy_s(email, strlen(e) + 1, e);
	}
	void SetAge(int a)
	{
		age = a;
	}
	const char* GetName()
	{
		return name;
	}
	const char* GetEmail()
	{
		return email;
	}
	int GetAge()
	{
		return age;
	}

};

int main()
{
	Student obj1("Oleg", 20, "Email@gmail.com");
	obj1.Print();
	obj1.Input();
	obj1.Print();
}