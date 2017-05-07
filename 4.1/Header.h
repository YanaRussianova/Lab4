
#include <vector>
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cassert>
#include <stdio.h>
#include <iomanip> // ��� setw
#include <regex> 
#include <cstdlib>
#include <fstream> 
#include <time.h>
//#include "Store.h"
#include "except.h"
#include "iterator.h"
#include <sstream>
#pragma warning (disable:4996)
using namespace std;

template  <typename T>
class List  {
	class Node {
		Node *next;
		Node *prev;
		T data;
		friend class List <T>;
	public:
		Node() : next(nullptr), prev(nullptr) {}
		~Node() {}
		Node(const T& d) :data(d), prev(NULL), next(NULL) {}
		/*T* getData() {
			return &data;
		}*/
	};
	Node *head;
	Node *tail;
	int length;
	List(const List&) { }
public:
//friend class Iterator;
	typedef Iterator<T> iter;
	iter begin() { return Iterator<T>(head); }
	iter end() { return Iterator<T>(tail); }
	List();
	~List();
	int getLength();//������ ������
	void add(const T&);//�������� ������
	T& at(int);//�������� ������ �������
	void change(const T&, int);//�������� ������
	void deleteN(int);//������� �����
	void delal();//������� ���� �����
	void display();//����������
};



