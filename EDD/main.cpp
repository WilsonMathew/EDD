#include "user.h";
#include <iostream>;
#include <string>;

using namespace std;


// Defining a arraylength macro
// example of using it: arraylen(takes name of array)
#define arrayLen(ar) (sizeof(ar)/sizeof(ar[0])) 

// Menus to select one option
void menu(string menuData[], int menuSize ) 
{
	// element 0 of the array will define the current menu;
	cout << "*          " << menuData[0]   << "				*\n";

	for (int i = 1; i < menuSize; i++)
	{
		cout << "-> " << menuData[i] << ": \n";
	}
	

	// fill the user info
}


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
	string test[] = {"Login","Ingresar usuario","Ingresar contraseña", "Ingresar Departamento","Ingresar Empresa"};
	//menu(test, arrayLen(test));
	loginMenu();
	return 0;
}