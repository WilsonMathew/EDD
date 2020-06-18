#include <iostream>
#include <string>
#include <time.h>
#include "user.h"
#include "Asset.h"
#include "DoublyList.h"
#include "Matriz.h"
#include "AVL.h"

using namespace std;

// Defining a arraylength macro
// example of using it: arraylen(takes name of array)
#define arrayLen(ar) (sizeof(ar)/sizeof(ar[0])) 

// Variable global
Matriz* user = new Matriz();

// metodo para ingresar un usuario a la matriz
void insertUser()
{

	string userData[4] = {"","","",""};

	cout << "********** " << "Wilson Laynez" << " **********\n";
	cout << "*          " << "    Registrar Usuario    " << "          *\n";
	cout << "-> Ingresar usuario: ";
	cin >> userData[0];
	cout << "-> Ingresar contraseña: ";
	cin >> userData[1];
	cout << "-> Ingresar departamento:";
	cin >> userData[2];
	cout << "-> Ingresar Empresa: ";
	cin >> userData[3];

	if (user->getUserData(userData[0], userData[1], userData[2], userData[3]) != "0")
		cout << "$$$ No se adminten duplicados! intente con un nombre diferente $$$\n\n";
	else
	{
		user->insertElement(userData[0], userData[1], userData[2], userData[3]);
		cout << "$$$ Usuario ingresado! $$$ \n\n";
	}
	
	// test users

	/*
	user->insertElement("Mynor", "1", "max", "Guatemala");
	user->insertElement("susan", "2", "hp", "jutiapa");
	user->insertElement("susel", "3", "hp", "jalapa");
	user->insertElement("Roxana", "4", "walmart", "Guatemala");
	user->insertElement("Andrea", "5", "walmart", "jalapa");
	user->insertElement("Sebas", "6", "walmart", "jalapa");
	user->insertElement("Andres", "7", "hp", "Guatemala");
	user->insertElement("Willy", "8", "max", "jalapa");
	*/
}

// Menus to select one option
int menu(string menuData[], int menuSize ) 
{
	int opcion;
	// element 0 of the array will define the current menu;
	cout << "*" << menuData[0]   << " *\n\n";

	// show menu text
	for (int i = 1; i < menuSize; i++)
	{
		cout << "-> " << i << ". " << menuData[i] << "\n";
	}
	
	cout << "---> Opcion: ";
	cin >> opcion;

	return opcion;
}

// Login Menu using user test
void loginMenu()
{

	string menuLoggedIn[] =
	{
		"$$$USERNAME$$$",
		"Agregar activo",
		"Eliminar activo",
		"Modificar activo",
		"Rentar activo",
		"Activos rentados",
		"Mis activos rentados",
		"Cerrar sesion"
	};

	string menuAdmin[] =
	{
		"Menu Administrador",
		"Registrar usuario",
		"Reporte matriz dispesa",
		"Reporte activos disponibles de un departamento",
		"Reporte activos disponibles de una empresa",
		"Reporte transacciones",
		"Reporte activos de un usuario",
		"Reporte activos rentados por un usuario ",
		"Ordenar transacciones"
	};

	string userData[4];

	// Welcome screen

	cout << "******** PROYECTO 1 ********** \n";
	cout << "********   EDD 1    ********** \n";
	cout << "******** 201602755  ********** \n";
	cin.ignore();

	system("CLS");
	// var to manage options
	int opt;
	do
	{
		cout << "********** " << "Wilson Laynez" << " **********\n";
		cout << "*          " << "    Login    " << "          *\n";
		cout << "-> Ingresar usuario: ";
		cin >> userData[0];
		cout << "-> Ingresar contraseña: ";
		cin >> userData[1];
		cout << "-> Ingresar departamento:";
		cin >> userData[2];
		cout << "-> Ingresar Empresa: ";
		cin >> userData[3];

		if (userData[0] == "admin" && userData[1] == "admin")
		{

			do
			{
				//system("CLS");
				opt = menu(menuAdmin, arrayLen(menuAdmin));
				switch (opt)
				{
					case 1:
						system("CLS");
						insertUser();
						cin.ignore();
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:
						break;
					default:
						cout << "Admin logged out! \n";
						cin.ignore();
						break;
				}
			} while (opt != 0);
		}
		else
		{
		
			if (user->getUserData(userData[0], userData[1], userData[2], userData[3]) != "0")
			{
				

				do
				{
					system("CLS");
					menuLoggedIn[0] = userData[0];
					opt = menu(menuLoggedIn, arrayLen(menuLoggedIn));

					switch (opt)
					{
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:
						break;
					default:
						cout << userData[0] << " logged out! Bye \n";
						cin.ignore();
						break;
					}
				} while (opt != 0);
			}
			else
			{
				cout << " No existe usuario \n";
			}
		}
	} while (true);
}



int main()
{

	///user->graph();
	// EDD Vars
	
	
	// Menu logged in user
	
	
	//loginMenu();

	//Menu calls
	/// Admins's menu

	//menu(menuAdmin, arrayLen(menuAdmin));
	//int n = menu(test,arrayLen(test));
	
	// Lista doblemente enlazada de transacciones
	/*
	Transaction one;
	Transaction two;

	one.setTransactionId("obj1");
	two.setTransactionId("Obj2");

	DoublyList test;
	NodeDCList* start = NULL;

	test.insertEnd(&start, one);
	test.insertEnd(&start, two);
	test.printList(start);
	*/
	
	
	//loginMenu();
	/*

	*/
	
	// Test for AVL tree, so far BST implemented. need to balance stuff
	
	//string treekeys[16] = { "50","76","21","4","32","64","15","52","14","100","83","2","3","70","87","80" };

	
	//int treekeys[16] = { 50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
	int treekeys[6] = { 10,20,30,40,50,25 };
	AVL myTree;

	for (int i = 0; i < 6; i++)
	{
		myTree.addLeaf(treekeys[i]);
	}

	myTree.printPreOrder();

	int input=0;
	cout << "\n eliminar o -1 para salir\n";
	while (input != -1)
	{
		cout << "delete Node: ";
		cin >> input;
		if (input != -1)
		{
			cout << endl;
			myTree.removeNode(input);
			myTree.printPreOrder();
		}
	}

	/*
	for (int i = 0; i < 6; i++)
	{
		myTree.printRootKey(treekeys[i]);
	}
	*/
	
	
	// testing strings
	/*
	string one = "hello5";
	string two = "hello10";


	if (one.compare(two) == 0)
	{
		cout << "they are equal";
	}
	else if (one.compare(two) < 0)
	{
		cout << one << " less than " << two << endl;
	}
	else if (one.compare(two) > 0)
	{
		cout << one << " greater than " << two << endl;
	}
	*/
	return 0;
}