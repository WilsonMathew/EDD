#include "Matriz.h"
#include "NodoMatriz.h"



void Matriz::insertElement(string user, int numero, string company, string dept)
{
	NodoMatriz* NodoUsr;
	NodoMatriz* NodoCompany;
	NodoMatriz* NodoDept;

	NodoUsr = new NodoMatriz(user, numero);

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
					if (auxEmp->nombre == company)
					{
						NodoUsr->down = aux;
						NodoUsr->up = aux->up;

						aux->up->down = NodoUsr;
						aux->up = NodoUsr;
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

	}
}
//----------------------------

NodoMatriz* Matriz::createCompany(string empresa)
{
	NodoMatriz* emp;
	emp = new NodoMatriz(empresa, -1);

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
	dept = new NodoMatriz(_dept, -1);

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
		if (aux->nombre == empresa)
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
		if (aux->nombre == dept)
			return aux;
		aux = aux->next;
	}

	return nullptr;
}


//---------------------------------------------------------
bool Matriz::verifyCompany(string company, NodoMatriz* start, NodoMatriz* usr)
{
	NodoMatriz* auxCom = start->prev;

	while (auxCom->prev != nullptr)
	{
		auxCom = auxCom->prev;
	}

	if (auxCom->nombre == company)
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

bool Matriz::verifyDept(string department, NodoMatriz* start, NodoMatriz* usr)
{
	NodoMatriz* auxDept = start->up;

	while (auxDept->up != nullptr)
	{
		auxDept = auxDept->up;
	}

	if (auxDept->nombre == department)
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