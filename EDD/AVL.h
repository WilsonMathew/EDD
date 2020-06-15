#pragma once
#include <iostream>
#include <string>

class AVL
{
private:
	struct node
	{
		int key;
		//string alphaKey;
		//string nombre;
		//string desc;
		node* left;
		node* right;
	};

	node* root;
	void addLeafPrivate(int key, node* ptr);
	void printInOrderPrivate(node* ptr);
	node* returnNodePrivate(int key, node* ptr);

	void removeNodePrivate(int key, node* parent);
	void removeRootMatch();
	int findSmallestPrivate(node* ptr);
	void removeMatch(node* parent, node* match, bool left);
	node* returnNode(int key);
	node* createLeaf(int key);
	//remove all
	void removeSubTree(node* ptr);
public:
	AVL();
	~AVL();
	void addLeaf(int key);
	void printInOrder();
	int returnRootKey();
	void printRootKey(int key);
	int findSmallest();

	// following tuts
	void removeNode(int key);
};

