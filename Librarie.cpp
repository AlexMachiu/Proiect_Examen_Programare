#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include<fstream>
//#include "ClientCarte.h"
using namespace std;
class Carte
{
private:
	string titlul;
	string autor;
	int id; // id-uri date de mine pentru a nu avea probleme la overflow cu isbn deoarece sunt numere mari
public:

	Carte(string t, string a, int i) // constructor
	{
		titlul = t;
		autor = a;
		id = i;
	}

	void display(Carte c)  // "getter"
	{
		cout << "Titlul este: ";
		cout << c.titlul << endl;
		cout << "Autorul este: ";
		cout << c.autor << endl;
		cout << "ID-ul este: ";
		cout << c.id << endl;
	}

	// nu am facut setter deoarece daca vreau sa introduc o carte trebuie sa completez toate field-urile 
};
class Client
{
private:
	string nume;
	string prenume;
	list <int> imprumutate; // id-uri carti imprumutate 
							// am preferat sa lucrez cu liste pentru a evita vectorii dinamici
public:

	Client(); // (1) *jos*
	Client(string n, string p, list<int> i)
	{
		nume = n;
		prenume = p;
		for (auto const &j : i) // algoritm de parcurgere si de mutare a elementelor dintr-o lista in alta fara pointeri
		{
			imprumutate.push_back(j); // push_back adauga un element nou la finalul listei 
		}
	}
	void display(Client c)  // "getter"
	{
		cout << "Numele este: ";
		cout << c.nume << endl;
		cout << "Prenumele este: ";
		cout << c.prenume << endl;
		cout << "ID-urile cartilor imprumutate sunt: ";
		for (auto const &i : imprumutate)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	//Setter pentru nume si prenume
	void setter_numePrenume(string n, string p)
	{
		nume = n;
		prenume = p;
	}

	void addBook(int id)  //Functie pentru adaugarea unei carti la lista unui client
	{
		imprumutate.push_back(id);
	}
	bool checkBook(int id) // ii dau un id, trece prin lista clientului si vede daca se regaseste sau nu
	{
		for (auto const &i : imprumutate) {
			if (id == i)
				return true; //daca regesaste id-ul se opreste si returneaza true
		}
		return false;
	}
};
Client::Client()
{
}

int main()
{
	ifstream fin;
	fin.open("Carti.txt");
	list <Carte> disponibile;
	string titlu;
	string autor;
	int id;
	while (fin>> titlu >>autor >> id) 
	{
		Carte c(titlu, autor, id);
		disponibile.push_back(c);
	}


	for (auto  &i : disponibile)
	{
		i.display(i);
		
	}
	Client cl;
	cl.setter_numePrenume("nume", "prenume");
	cl.addBook(1);
	cl.addBook(2);

	cl.display(cl);
	cout << "Ce carte imprumutata cautati? \n";
	int idImprumutat;
	cin >> idImprumutat;
	if (cl.checkBook(idImprumutat)) 
	{
		cout << "Clientul are cartea imprumutata cu ID-ul "<<idImprumutat<<".";
	}
	else
		cout << "Nu are imprumutata cartea cu ID-ul " << idImprumutat << ".";
	fin.close();
	return 0;
}

