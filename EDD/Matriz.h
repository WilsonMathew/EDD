#pragma once
#include "NodoMatriz.h"
#include <iostream>

using namespace std;

class Matriz
{
public:
	NodoMatriz* head;

	Matriz()
	{
		head = new NodoMatriz();
	}

	void insertElement(string user, int numero, string company, string dept);
	NodoMatriz* createCompany(string company);
	NodoMatriz* createDept(string dept);

	NodoMatriz* findCompany(string empresa, NodoMatriz* start);
	NodoMatriz* findDept(string dept, NodoMatriz* start);

	bool verifyCompany(string company, NodoMatriz* start, NodoMatriz* usr);
	bool verifyDept(string dept, NodoMatriz* start, NodoMatriz* usr);
};

