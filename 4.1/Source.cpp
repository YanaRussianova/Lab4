#include "Header.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include<cassert>
#include <iomanip> // для setw
#pragma warning (disable:4996)
FILE *f;
using namespace std;

char *stroka() {  ////ввод строки со **
	char *s = new char[20];
	char c;
	int i = 0, k = 0;
	i = 0;
	fflush(stdin);
	while ((c = getch()) != 13 && i<19) {
		if (c == 8 && i > 0) {
			printf("\b \b");
			i--;
		}
		else {
			cout << "*";
			s[i] = c;
			i++;
		}
	}
	s[i] = '\0';
	return s;
}

char *stroka1() {
	string buff;
	getline(cin, buff);
	if (buff.length() == 0) { getline(cin, buff); }
	char * a = new char[buff.length()];
	strcpy(a, buff.c_str());
	buff.clear();
	return a;
}

int chislo() {
	string s;
	int n = 0, k = 0;
	regex str("([0-9])+");
	try {
		getline(cin, s);
		if (s.length() == 0) { getline(cin, s); }
		if (s.empty()) cerr << "Ничего не ввели" << endl;  //---------------------------------------------------------
		if (!regex_match(s, str)) throw exception_1("введите целое число ");
		n = atoi(s.c_str());
		s.clear();
		return n;
	}
	catch (exception_1) {
		//cout << e << endl;
		s.clear();
		return -1;
	}
}

double dobl() {
	string s;
	int  k = 0;
	double n = 0;
	regex str("([0-9\.])+");
	try {
		getline(cin, s);
		if (s.length() == 0) { getline(cin, s); }
		if (!regex_match(s, str)) throw exception_1("неверно,пример 3.4");
		n = atoi(s.c_str());
		s.clear();
		return n;
	}
	catch (exception_1) {
		//cout << a << endl;
		s.clear();
		return 0;
	}
}

template<class T>
List<T>::List() {
	head = NULL;
	tail = NULL;
	length = 0;
}
template<class T>
List<T>::~List() {
	while (head != NULL) {
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
}
template<class T>
int List<T>::getLength() {
	return length;
}

template <class T>
void List<T>::add(const T& data)
{
	Node *n = new Node(data);		// создаем отдельный узел
									// Если список пуст, то
	n->next = NULL;
	if (head == NULL) {
		// связываем последний узел с новым;
		head = n;
		n->prev = NULL;

	}
	else {
		Node *dop = tail;
		dop->next = n;
		n->prev = dop;
	}
	tail = n;
	length++;
}

template <class T>
T& List<T>::at(int index) {
	Node *current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->data;
	

}
typedef List<int> L;
L l;

template<class T>
void List<T>::display() {
	List<int>::iter it = l.begin();
	List<int>::iter e = l.end();
	for (;it != e;++it) {
		//cout <<"№ "<< i + 1 << endl;
		cout << *it << endl << endl;
	}
}
template<class T>
void List<T>::deleteN(int a) {
	Node *cur = head, *pred;
	int len = l.getLength();
	if (a > len) { cout << "Неверный ввод "; system("pause"); }
	else {
		for (int i = 0; i < a - 1; i++) {
			cur = cur->next;

		}
		if (a == len) {    //если эл-т последний
			pred = cur->prev;
			pred->next = NULL;
		}
		else if (a == 1) {      //если эл-т первый
			pred = cur->next;
			pred->prev = NULL;
			head = head->next;
		}
		else {
			pred = cur->prev;
			pred->next = cur->next;
			cur->next->prev = pred;
		}
		delete cur, pred;/////

		length--;
	}
}


template<class T>
void List<T>::change(const T& data, int a) {/////////////////////////////
	Node *n = new Node(data);
	Node *cur = head, *pred;
	
	int b = l.getLength();
	for (int i = 0; i < a; i++) {
		cur = cur->next;
	}
	if (a == 0) {
		head = n;
		head->prev = NULL;
		head->next = cur->next;
		cur->next->prev = head;
	}
	else if (a == b - 1) {
		cur->prev->next = n;
		n->next = NULL;
		n->prev = cur->prev;
	}
	else if (a == 1) {
		head->next = n;
		n->prev = head;
		n->next = cur->next;
		cur->next->prev = n;
	}
	else {
		pred = cur->prev;
		pred->next = n;
		n->prev = pred;
		n->next = cur->next;
		cur->next->prev = n;
	}
	delete cur, pred;
}



template<class T>
void List<T>::delal() {
	Node *cur = head;
	int a = l.getLength();
	for (int i = 0; i < a - 1; i++) {
		cur = head;
		head = head->next;
		delete cur;
		length--;
	}
	head = NULL;
	length = 0;
}

