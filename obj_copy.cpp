#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person { // Person Ŭ���� ����
	char* name;
	int id;
public:
	Person(int id, const char* name); // ������
	Person(const Person& p); // Copy Constructor
	~Person(); // �Ҹ���
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) { // ������
	this->id = id;
	int len = strlen(name); // name�� ���� ����
	this->name = new char[len + 1]; // name ���ڿ� ���� ����
	strcpy(this->name, name); // name�� ���ڿ� ����
}

Person::Person(const Person& p) {
	this->id = p.id;
	int len = strlen(p.name);
	this->name = new char[len + 1];
	strcpy(this->name, p.name);
}

Person::~Person() {// �Ҹ���
	if (name) // ���� name�� ���� �Ҵ�� �迭�� ������
		delete[] name; // ���� �Ҵ� �޸� �Ҹ�
}

void Person::changeName(const char* name) { // �̸� ����
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main() {
	Person father(1, "Kitae");			// (1) father ��ü ����
	Person daughter(father);			// (2) daughter ��ü ���� ����. ���������ȣ��
	cout << "daughter ��ü ���� ���� ----" << endl;
	father.show();						// (3) father ��ü ���
	daughter.show();					// (3) daughter ��ü ���

	daughter.changeName("Grace"); // (4) daughter�� �̸��� "Grace"�� ����
	cout << "daughter �̸��� Grace�� ������ �� ----" << endl;
	father.show();						// (5) father ��ü ���
	daughter.show();					// (5) daughter ��ü ���

	return 0;								// (6), (7) daughter, father ��ü �Ҹ�
}