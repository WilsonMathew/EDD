#pragma once
#include <iostream>
#include <string>
#include "AVL.h"


using namespace std;

class NodoMatriz
{
public:
	NodoMatriz* next;
	NodoMatriz* prev;
	NodoMatriz* up;
	NodoMatriz* down;
	NodoMatriz* in;
	NodoMatriz* out;
	string name;
	string password;
	AVL* asset;

	NodoMatriz(string _nombre, string _password)
	{
		next = nullptr;
		prev = nullptr;
		up = nullptr;
		down = nullptr;
		in = nullptr;
		out = nullptr;
		asset = new AVL();
		
		name = _nombre;
		password = _password;
	}

	NodoMatriz()
	{
		next = nullptr;
		prev = nullptr;
		up = nullptr;
		down = nullptr;
		in = nullptr;
		out = nullptr;
	}



};

