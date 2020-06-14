#include "DoublyList.h"
#include "NodeDCList.h"
#include "Transaction.h"
#include <iostream>

void DoublyList::printList(NodeDCList* start)
{
	NodeDCList* temp = start;
	while (temp->next != start)
	{
		std::cout << temp->data.getTransactionId();
		temp = temp->next;
	}

	std::cout << temp->data.getTransactionId();
}

void DoublyList::insertEnd(NodeDCList** start, Transaction value)
{
	// If list is empty
	if (*start == NULL)
	{
		NodeDCList* newNode = new NodeDCList(value);
		newNode->data = value;
		newNode->next = newNode->prev = newNode;
		*start = newNode;
		return;
	}

	//If list is not empty
	NodeDCList* last = (*start)->prev;
	
	NodeDCList* newNode = new NodeDCList(value);
	newNode->data = value;
	newNode->next = *start;
	(*start)->prev = newNode;
	newNode->prev = last;
	last->next = newNode;
}


//void insertBegin(NodeDCList** start, Transaction value);
//void insertAfter(Transaction**, Transaction value1, Transaction value2);
