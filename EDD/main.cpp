#include <iostream>;
#include <string>;
#include <time.h>
#include "user.h";
#include "Asset.h";

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



string format_date(string s)
{
	char buf[11];
	int a, b, c;
	scanf_s(s.c_str(), "%d-%d-%d", &a, &b, &c);
	sprintf_s(buf, "%02d/%02d/%d", c, b, a);
	return buf;
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

	return 0;
}