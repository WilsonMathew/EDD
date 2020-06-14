#pragma once
#include <iostream>
#include <string>
#include "user.h"
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

	string nombre;
	int numero;

	NodoMatriz(string _nombre, int _dato)
	{
		next = nullptr;
		prev = nullptr;
		up = nullptr;
		down = nullptr;
		in = nullptr;
		out = nullptr;

		nombre = _nombre;
		numero = _dato;
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

