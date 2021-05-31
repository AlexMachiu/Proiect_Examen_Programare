#pragma once
#include<iostream>
#include<stdio.h>
#include <string>
#include <list>
#include <iterator>
class Carte
{
private:
	string titlul;
	string autor;
	int id; // id-uri date de mine pentru a nu avea probleme la overflow cu isbn deoarece sunt numere mari
public:

	Carte(string t, string a, int i); // constructor


		void display(Carte c);  // "getter"

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
	Client(string n, string p, list<int> i);

		void display(Client c);  // "getter"


	//Setter pentru nume si prenume
	void setter_numePrenume(string n, string p);

	//Functie pentru adaugarea unei carti la lista unui client
	void addBook(int id);
};
Client::Client()
{
}