#include "user.h";
#include <iostream>;
using namespace std;

void user::setUser(string _createUser[])
{
	username = _createUser[0];
	password = _createUser[1];
	dept = _createUser[2];
	company = _createUser[3];
}
void user::setName(string _username)
{
	username = _username;
};

void user::setPassword(string _password)
{
	password = _password;
};

void user::setDept(string _department)
{
	dept = _department;
};

void user::setCompany(string _company)
{
	company = _company;
};


string user::getName()
{
	return username;
}

string user::getPassword()
{
	return password;
}

string user::getDept()
{
	return dept;
}

string user::getCompany()
{
	return company;
}
