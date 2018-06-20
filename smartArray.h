#ifndef smart_h
#define smart_h
#include <iostream>
#include <cstdlib>

//To jest bardzo stara praca domowa.

class smartArray
{
private:

	int size;
	int *tab;

public:
	smartArray(int *tab, int size);
	smartArray(int size);
	~smartArray();
	void sort();
	int max();
	int min();
	void shuffle();
	void print();
	bool isSorted();
	void menu();
	void menuArray();
	void setSize(int rozmiar);
	int getSize();


};





#endif

