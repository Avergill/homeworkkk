#include "smartArray.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void smartArray::setSize(int rozmiar)
{
	size = rozmiar;
}
int smartArray::getSize()
{
	return size;
}

smartArray::smartArray(int * tablica, int rozmiar)
{

	tab = &tablica[rozmiar];
	smartArray::setSize(rozmiar);
	cout << "Przypisano wskaznik do tablicy.\n";
}
smartArray::smartArray(int rozmiar)						//Dziala.
{
	tab = new int[rozmiar];
	smartArray::setSize(rozmiar);
	for (int a = 0; a < rozmiar; a++)
	{
		tab[a] = rand();
	}
}
smartArray::~smartArray()				//nie dzia³a?
{
	delete[] tab;
	cout << "Zwolniono pamiec.\n";
}
bool smartArray::isSorted()
{
	for (int a = 1; a < getSize(); a++)
	{
		if (tab[a - 1] > tab[a])
		{
			return false;
		}
	}
	return true;
}
void smartArray::sort()
{
	for (int a = 0; a < getSize(); a++)
	{
		for (int b = 0; b < getSize(); b++)
		{
			if (tab[b] > tab[b + 1])
			{
				swap(tab[b], tab[b + 1]);
			}
		}
	}
	cout << "Posortowano tablice.\n";
}
int smartArray::max()				//Dzia³a
{
	int maximum = tab[0];
	for (int a = 0; a < getSize(); a++)
	{
		if (tab[a] > tab[a + 1] && tab[a] > maximum)
		{
			maximum = tab[a];
		}
	}
	return maximum;
}
int smartArray::min()					//Dzia³a
{
	int minimum = tab[0];
	for (int a = 0; a < getSize(); a++)
	{
		if (tab[a] < tab[a + 1] && tab[a] < minimum)
		{
			minimum = tab[a];
		}
	}
	return minimum;
}
void smartArray::shuffle()						//Dzia³a.
{
	int rozmiar = getSize();
	int randomIndex = (rand() % rozmiar);
	for (int a = 0; a < rozmiar; a++)
	{
		swap(tab[a], tab[randomIndex]);
		randomIndex = (rand() % rozmiar);
	}
	cout << "Pomieszano tablice.\n";
}
void smartArray::print()								//Dziala.
{
	for (int a = 0; a < getSize(); a++)
	{
		cout << tab[a] << "\t";
	}
}
void smartArray::menuArray()
{
	short wyborTablica;
	do
	{
		cout << "\nWybierz opcje:\n[0]Zakoncz program\n[1] Wyswietl tablice\n[2]Sprawdz, czy tablica jest posortowana\n[3]Posortuj tablice\n[4]Pomieszaj tablice\n[5]Sprawdz najwiekszy element tablicy\n[6]Sprawdz najmniejszy element tablicy" << endl;
		cin >> wyborTablica;
		switch (wyborTablica)
		{
		case 0:
			break;
		case 1:
			smartArray::print();
			break;
		case 2:
			if (smartArray::isSorted())
			{
				cout << "Tablica jest posortowana.";
			}
			else
			{
				cout << "Tablica nie jest posortowana.";
			}
			break;
		case 3:
			smartArray::sort();
			break;
		case 4:
			smartArray::shuffle();
			break;
		case 5:
			cout << "Maximum wynosi: " << smartArray::max() << endl;
			break;
		case 6:
			cout << "Minimum wynosi: " << smartArray::min() << endl;
			break;
		default:
			cout << "Wybierz prawidlowa opcje." << endl;
			break;
		}
	} while (wyborTablica != 0);
}
void smartArray::menu()
{
	short wybor = 0;
	int rozmiar;
	cout << "Wybierz opcje stworzenia tablicy:\n[1] Losowa tablica o podanym rozmiarze,\n[2] Tablica o podanym rozmiarze i elementach.\n[3] Zakoncz program." << endl;
	do
	{
		switch (wybor)
		{
		case 1:
			cout << "Podaj rozmiar tablicy: ";
			cin >> rozmiar;
			smartArray::smartArray(rozmiar);
			cout << "Utworzono losowa tablice." << endl;
			smartArray::menuArray();
			break;
		case 2:
			cout << "Podaj rozmiar tablicy: ";
			cin >> rozmiar;
			int *tablica;
			tablica = new int[rozmiar];
			cout << "Podaj kolejne wartosci indeksow tablicy:" << endl;
			for (int a = 0; a < rozmiar; a++)
			{
				cout << "\n[" << a << "] = ";
				cin >> tablica[a];
			}
			smartArray::smartArray(tablica, rozmiar);
			cout << "Utworzono tablice." << endl;
			smartArray::menuArray();
			break;
		case 3:
			break;
		default:
			cout << "Wybierz prawidlowa opcje." << endl;
			cin >> wybor;
			break;
		}
	} while (wybor = 3);
}
