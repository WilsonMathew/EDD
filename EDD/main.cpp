#include <iostream>
#include <string>
#include <time.h>
#include "user.h"
#include "Asset.h"
#include "DoublyList.h"
#include "Matriz.h"

using namespace std;

// Defining a arraylength macro
// example of using it: arraylen(takes name of array)
#define arrayLen(ar) (sizeof(ar)/sizeof(ar[0])) 

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
	user test;
	string userData[4];
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
}


int main()
{
	// Menu logged in user
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
	

	// Menu calls
	/// Admins's menu
	//menu(menuAdmin, arrayLen(menuAdmin));
	//loginMenu();
	//system("CLS");
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

	Matriz* miObjecto = new Matriz();
	miObjecto->insertElement("Mynor", 1, "max", "Guatemala");
	miObjecto->insertElement("susan", 2, "hp", "jutiapa");
	miObjecto->insertElement("susel", 3, "hp", "jalapa");
	miObjecto->insertElement("Roxana", 4, "walmart", "jalapa");
	miObjecto->insertElement("Andrea", 5, "walmart", "jalapa");
	miObjecto->insertElement("Sebas", 6, "walmart", "jalapa");
	miObjecto->insertElement("Andres", 7, "hp", "Guatemala");
	miObjecto->insertElement("Willy", 8, "max", "jalapa");


	//return 0;
}