#pragma once
#include "NodeDCList.h"
#include "Transaction.h"
class DoublyList
{
public:
	NodeDCList* head;
	DoublyList()
	{
		head = nullptr;
	}
	void insertEnd(NodeDCList* start, Transaction value);
	void insertBegin(NodeDCList* start, Transaction value);
	void insertAfter(Transaction* , Transaction value1, Transaction value2);
	void printList(NodeDCList* start);
	~DoublyList()
	{

	}
};

