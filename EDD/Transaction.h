#pragma once
#include <string>;
#include "Asset.h"
#include "user.h"

using namespace std;

class Transaction
{
private:
	string transactionId;
	Asset transAsset;
	user transUser;
	string transDate;
	string transRentTime;
public:
	void setTransactionId(string tId);
	void setTransactionAsset(Asset tAsset);
	void setTransactionUser(user tUser);
	void setTransactionDate(string tDate);
	void setTransactionTime(string tTime);

	string getTransactionId();
	Asset getTransactionAsset();
	user getTransactionUser();
	string getTransactionDate();
	string getTransactionTime();

};