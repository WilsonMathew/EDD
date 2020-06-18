#pragma once
#include "NodoMatriz.h"
#include <iostream>
#include "AVL.h"

using namespace std;

class Matriz
{
public:
	NodoMatriz* head;
	Matriz()
	{
		head = new NodoMatriz("admin","admin");
	}

	// Assets in matrix
	void insertAsset(string name, string password, string company, string dept, string nameAsset, string descAsset);
	//AVL* getAssets();

	void insertElement(string user, string password, string company, string dept);
	NodoMatriz* createCompany(string company);
	NodoMatriz* createDept(string dept);

	NodoMatriz* findCompany(string empresa, NodoMatriz* start);
	NodoMatriz* findDept(string dept, NodoMatriz* start);

	bool verifyCompany(string company, NodoMatriz* start, NodoMatriz* usr);
	bool verifyDept(string dept, NodoMatriz* start, NodoMatriz* usr);

	NodoMatriz* verifyCompInDept(string company, string dept);

	NodoMatriz* getUserData(string name, string pasword, string company, string dept);

	// Graphing stuff
	void graph();
	void getDot(FILE* file, NodoMatriz* n );
};