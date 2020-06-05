#pragma once
#include <string>;

using namespace std;

class user
{
private:
	string username;
	string password;
	string dept;
	string company;
public:
	void setUser(string createUser[]);
	void setName(string u);
	void setPassword(string p);
	void setDept(string d);
	void setCompany(string c);
	
	string getName();
	string getPassword();
	string getDept();
	string getCompany();
};