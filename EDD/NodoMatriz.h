#pragma once
#include <iostream>
#include <string>


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

	NodoMatriz(string _nombre, string _password)
	{
		next = nullptr;
		prev = nullptr;
		up = nullptr;
		down = nullptr;
		in = nullptr;
		out = nullptr;

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

