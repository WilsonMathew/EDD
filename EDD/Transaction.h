#pragma once
#include <string>
#include "Asset.h"
#include "user.h"
#include "NodoMatriz.h"

using namespace std;

class Transaction
{
private:
	string transactionId;
	string transDate;
	string transRentTime;
	Asset transAsset;
public:
	//Transaction(NodoMatriz* usr);
	void setTransactionId(string tId);
	void setTransactionAsset(Asset tAsset);
	void setTransactionDate(string tDate);
	void setTransactionTime(string tTime);

	string getTransactionId();
	Asset getTransactionAsset();
	string getTransactionDate();
	string getTransactionTime();

};