#pragma once
#include "Transaction.h";

class NodeDCList
{
public:
	Transaction data;
	NodeDCList* next;
	NodeDCList* prev;

	NodeDCList(Transaction _data)
	{
		next = nullptr;
		prev = nullptr;
		data = _data;
	}
	
};

