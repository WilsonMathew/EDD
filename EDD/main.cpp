#include "user.h";
#include <iostream>;
#include <string>;

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

	test.setUser(userData);
	cout << "Object data";

	cout << "Company  " << test.getCompany();
	cout << "Pass   " << test.getPassword();
}

int main()
{
	// Menu logged in user
	string test[] = {"$$$USERNAME$$$",
		"Agregar activo", 
		"Eliminar activo",
		"Modificar activo",
		"Rentar activo",
		"Activos rentados",
		"Mis activos rentados",
		"Cerrar sesion"};
	loginMenu();
	system("CLS");
	int n = menu(test,arrayLen(test));


	return 0;
}