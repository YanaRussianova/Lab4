
#include <vector>
#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cassert>
#include <stdio.h>
#include <iomanip> // для setw
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
	int getLength();//длинна списка
	void add(const T&);//добавить объект
	T& at(int);//получить данные объекта
	void change(const T&, int);//изменить объект
	void deleteN(int);//удалить склад
	void delal();//удалить весь склад
	void display();//отобразить
};



