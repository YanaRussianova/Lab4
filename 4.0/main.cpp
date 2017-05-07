#include <iostream> 
#include <Windows.h>
#include <string>
#include <conio.h>
//#include "Header.h"
#include <vector> 
#include <numeric>
#include <iterator>
#include <algorithm>
#include <functional>
#include <conio.h>
#pragma warning (disable:4996)
using namespace std;

vector <int> vect;

vector <int> vect_1;
 

int Fill( int &size) {
	for (int i = 1;i < size+1;i++) {
		vect.push_back(i);
	}
	return 0;
}

int Fill1(int &size) {
	for (int i = 1;i < size + 1;i++) {
		vect_1.push_back(rand() % 10 + 1);
	}
	return 0;
}

bool mypredicate(int i, int j) {
	return (i == j);
}

int Accumulate( vector<int> ::iterator &i) {
	int sum = 0;
	for (i;i != vect.end();i++) {
		sum+=*i;
	}
	return sum;
}

void Sort(vector<int> ::iterator &i) {
	for (int y = 0; y < vect_1.size() - 1; y++)
	{
		int min = y;
		for (int j = y + 1; j < vect_1.size(); j++)
			if (vect_1[j] < vect_1[min])
				min = j;
		int buf = vect_1[y];
		vect_1[y] = vect_1[min];
		vect_1[min] = buf;
	}
}

void Set__difference(vector<int> ::iterator &itt,vector<int> ::iterator &itt1,int &s) {
	int k=0;
	for (itt;itt != vect.end();itt++) {
		int r = *itt;
		for (itt1;itt1 != vect_1.end();itt1++){
			int r1 = *itt1;
			if (r != r1) k++;
			}
		if (k == s) {
			cout << "\n ����� " << r << " ��� �� 2 ������� \n ";
			
		}
		k= 0;
		itt1 = vect_1.begin();
	}
}

void Mismatch(vector<int> ::iterator &itt, vector<int> ::iterator &itt1) {
	
	while(itt != vect.end() && itt1 != vect_1.end()) {
		int r = *itt;
		int r1 = *itt1;
		if (r != r1) cout << "\n ����������� ��-�� " << r << " � "<<r1<<"\n";
		itt1++;
		itt++;
	}
}

void Find(int &a, vector<int> ::iterator &itt1) {
	int kol = 0;
	for (itt1;itt1 != vect_1.end();itt1++) {
		int k = *itt1;
		if (k == a) {			
			cout << "�������  " << a << " ������" << '\n';
			kol++;
		}		
	}
	if(kol==0)
		cout << "��-� " << a << " �� ������\n";
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� ���-�� �� ��� 1 ������� ";
	int v_size,d_size ;
	cin >> v_size;
	cout << "\n ������� ���-�� �� ��� 2 ������� ";
	cin >> d_size;

	vector<int>::iterator it; 
	Fill(v_size);
	it = vect.begin();
	
	vector<int>::iterator it1;
	Fill1(d_size);
	it1 = vect_1.begin();
	

	std::vector <int> diff;
	cout << "M����� 1 = ";
	for (it;it != vect.end();it++) {
		cout << *it << " ";
		 }
	cout << endl;
	it = vect.begin();
	cout << "����� ������� 1 = " << Accumulate(it) << endl; //����� �������
	cout << endl;

	cout << "\n M����� 2 �� ���������� = ";
for (it1 ;it1 != vect_1.end();it1++) {
	cout << *it1 << " ";
}
it1 = vect_1.begin();
cout << "\n M����� 2 ���� ���������� = ";
Sort(it1);// ���������� !!

for (it1;it1 != vect_1.end();it1++) {
	cout << *it1 << " ";
}
cout << endl;

it = vect.begin();
it1 = vect_1.begin();
Set__difference(it,it1,d_size);

it = vect.begin();
it1 = vect_1.begin();
Mismatch(it,it1);
it1 = vect_1.begin();
	 int u;
	 cout << "������� ��-� ";
	 cin >> u;
	 Find(u,it1);
}