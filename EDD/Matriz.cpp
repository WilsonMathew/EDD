#define _CRT_SECURE_NO_DEPRECATE
#include "Matriz.h"
#include "NodoMatriz.h"
#include "AVL.h"
#include <time.h>

using namespace std;

void Matriz::insertAsset(string name, string password, string company, string dept, string nameAsset, string descAsset)
{
	NodoMatriz* data = getUserData(name, password, company, dept);
	srand(time(NULL));
	data->asset->addLeaf(rand(),"a",nameAsset,descAsset);
}

void Matriz::insertElement(string user, string password, string company, string dept)
{
	NodoMatriz* NodoUsr;
	NodoMatriz* NodoCompany;
	NodoMatriz* NodoDept;

	NodoUsr = new NodoMatriz(user, password);

	NodoDept = findDept(dept, head);
	NodoCompany = findCompany(company, head);

	// Check if they already existe
	if (NodoDept == nullptr)
		NodoDept = createDept(dept);
	if (NodoCompany == nullptr)
		NodoCompany = createCompany(company);


	// insertar en nodo departamento
		// Inicio

	if (NodoDept->down == nullptr)
	{
		NodoDept->down = NodoUsr;
		NodoUsr->up = NodoDept;
	}
	else if (NodoCompany->down == nullptr)
	{
		NodoMatriz* aux = NodoDept->down;
		while (aux->down != nullptr)
		{
			aux = aux->down;
		}

		if (!verifyCompany(company, aux, NodoUsr))
		{
			aux->down = NodoUsr;
			NodoUsr->up = aux;
		}
	}
	else
	{
		NodoMatriz* aux = NodoDept;
		NodoMatriz* auxEmp;
		do
		{
			aux = aux->down;
			if (!verifyCompany(company, aux, NodoUsr))
			{
				auxEmp = aux->prev;
				while (auxEmp->prev != nullptr)
				{
					auxEmp = auxEmp->prev;
				}
				while (auxEmp->up != nullptr)
				{
					if (auxEmp->name == company)
					{
						NodoUsr->down = aux;
						NodoUsr->up = aux->up;

						aux->up->down = NodoUsr;
						aux->up = NodoUsr;
						break;
					}
					auxEmp = auxEmp->up;
				}
			}


		} while (aux->down != nullptr && NodoUsr->up == nullptr);

		if (NodoUsr->up == nullptr && NodoUsr->out == nullptr)
		{
			aux->down = NodoUsr;
			NodoUsr->up = aux;
		}
	}


	// if insertes user break out of the function
	if (NodoUsr->out != nullptr)
	{
		return;
	}



	// insertar en nodo empresa
		// Inicio

	if (NodoCompany->next == nullptr)
	{
		NodoCompany->next = NodoUsr;
		NodoUsr->prev = NodoCompany;
	}
	else if (NodoDept->next == nullptr)
	{
		NodoMatriz* aux = NodoCompany->next;
		while (aux->next != nullptr)
		{
			aux = aux->next;
		}

		if (!verifyDept(company, aux, NodoUsr))
		{
			aux->next = NodoUsr;
			NodoUsr->prev = aux;
		}
	}
	else
	{
		NodoMatriz* aux = NodoCompany;
		NodoMatriz* auxDept;
		do
		{
			aux = aux->next;
			if (!verifyDept(dept, aux, NodoUsr))
			{
				auxDept = aux->up;
				while (auxDept->up != nullptr)
				{
					auxDept = auxDept->up;
				}
				while (auxDept->prev != nullptr)
				{
					if (auxDept->name == dept)
					{
						NodoUsr->next = aux;
						NodoUsr->prev = aux->prev;

						aux->prev->next = NodoUsr;
						aux->prev = NodoUsr;
						break;
					}
					auxDept = auxDept->prev;
				}
			}

		} while (aux->next != nullptr && NodoUsr->prev == nullptr);

		if (NodoUsr->prev == nullptr && NodoUsr->out == nullptr)
		{
			aux->next = NodoUsr;
			NodoUsr->prev = aux;
		}
	}
}
//----------------------------
NodoMatriz* Matriz::createCompany(string empresa)
{
	NodoMatriz* emp;
	// Check implications of changing data to string type
	emp = new NodoMatriz(empresa, "");

	NodoMatriz* aux = head;
	while (aux->down != nullptr)
	{
		aux = aux->down;
	}

	aux->down = emp;
	emp->up = aux;

	return emp;
}
NodoMatriz* Matriz::createDept(string _dept)
{
	NodoMatriz* dept;
	dept = new NodoMatriz(_dept,"");

	NodoMatriz* aux = head;
	while (aux->next != nullptr)
	{
		aux = aux->next;
	}

	aux->next = dept;
	dept->prev = aux;

	return dept;
}

//--------------

NodoMatriz* Matriz::findCompany(string empresa, NodoMatriz* start)
{
	NodoMatriz* aux = start;
	while (aux != nullptr)
	{
		if (aux->name == empresa)
			return aux;
		aux = aux->down;
	}

	return nullptr;
}
NodoMatriz* Matriz::findDept(string dept, NodoMatriz* start)
{
	NodoMatriz* aux = start;
	while (aux != nullptr)
	{
		if (aux->name == dept)
			return aux;
		aux = aux->next;
	}

	return nullptr;
}
NodoMatriz* Matriz::getUserData(string name, string pasword, string company, string dept)
{
	// Verifies if company exists in dept.
	NodoMatriz* data = verifyCompInDept(company, dept);
	
	if (data != nullptr)
	{
		do
		{
			if (data->name == name && data->password == pasword)
			{
				return data;
			}
			else
			{
				return NULL;
			}
			//cout << "Nombre: " << data->name << endl;
			data = data->in;
		} while (data->in != nullptr);
		
	}
	return NULL;
}
NodoMatriz* Matriz::verifyCompInDept(string company, string dept)
{

	NodoMatriz* auxLeft = findCompany(company, head);
	NodoMatriz* auxUp;
	// Si existe la compania
	if (auxLeft != nullptr)
	{
		while (auxLeft->next != nullptr)
		{
			//cout << auxLeft->next->name << endl;
			auxLeft = auxLeft->next;
			auxUp = auxLeft;

			// ir al nodo dept
			while (auxUp->up != nullptr)
				auxUp = auxUp->up;
			
			// verificar si una empres tiene sucursal en x dept
			if (auxUp->name == dept)
				return auxLeft;

			//cout << auxUp->name << endl;
		}
	}

	return 0;
}


//---------------------------------------------------------

bool Matriz::verifyCompany(string company, NodoMatriz* start, NodoMatriz* usr)
{
	NodoMatriz* auxCom = start->prev;

	while (auxCom->prev != nullptr)
	{
		auxCom = auxCom->prev;
	}

	if (auxCom->name == company)
	{
		while (start->in != nullptr)
			start = start->in;

		start->in = usr;
		usr->out = start;
		return true;
	}
	return false;
}
bool Matriz::verifyDept(string department, NodoMatriz* start, NodoMatriz* usr)
{
	NodoMatriz* auxDept = start->up;

	while (auxDept->up != nullptr)
	{
		auxDept = auxDept->up;
	}

	if (auxDept->name == department)
	{
		while (start->in != nullptr)
		{
			start = start->in;
		}
		start->in = usr;
		usr->out = start;
		return true; 
	}

	return false;
}

void Matriz::graph()
{
	FILE* file;
	file = fopen("grafo.dot", "w+");

	fprintf(file, "digraph G { \n");
	getDot(file, head->down);
	fprintf(file, "}");

	fclose(file);

	system("dot -Tpng grafo.dot -o Matriz.png");
	system(".\\Matriz.png");


}

void Matriz::getDot(FILE* file, NodoMatriz* n)
{
	NodoMatriz* aux = n;
	fprintf(file, "rankdir=LR \n");

	do
	{
		// nodo
		string label = aux->name + "[shape=box,label=\"" + aux->name + "\"]; \n";
		const char* clabel = label.c_str();
		fprintf(file, clabel);
		// enlaces
		string link;
		if(aux->next != nullptr)
			link = aux->name + "->" + aux->next->name +"\n";
		if(aux->prev != nullptr)
			link = link + aux->name + "->" + aux->prev->name + "\n";
	
		const char* cLink = link.c_str();
		fprintf(file, cLink);
		
		aux = aux->next;
	} while (aux != nullptr);
}