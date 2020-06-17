#include "Asset.h";
#include "user.h";
#include "Transaction.h"
#include <iostream>;

using namespace std;

void Transaction::setTransactionId(string _tId) 
{
	transactionId = _tId;

}
void Transaction::setTransactionAsset(Asset _tAsset)
{
	transAsset = _tAsset;
}
void Transaction::setTransactionDate(string _tDate)
{
	transDate = _tDate;
}
void Transaction::setTransactionTime(string _tTime)
{
	transRentTime = _tTime;
}

string Transaction::getTransactionId()
{
	return transactionId;
}
Asset Transaction::getTransactionAsset()
{
	return transAsset;
}
string Transaction::getTransactionDate()
{
	return transDate;
}
string Transaction::getTransactionTime()
{
	return transRentTime;
}