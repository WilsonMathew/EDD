#pragma once
#include <iostream>
#include <string>

using namespace std;

class AVL
{
private:
	struct node
	{
		int key;
		int height;
		string alphaKey;
		string nombre;
		string desc;
		node* left;
		node* right;
	};

	node* root;
	node* addLeafPrivate(node* node, int key, string alphaKey, string nombre, string desc);
	void printInOrderPrivate(node* ptr);
	void printPreOrderPrivate(node* ptr);
	node* returnNodePrivate(int key, node* ptr);

	void removeNodePrivate(int key, node* parent);
	void removeRootMatch();
	int findSmallestPrivate(node* ptr);
	void removeMatch(node* parent, node* match, bool left);
	node* returnNode(int key);
	node* createLeaf(int key, string alphaKey, string nombre, string desc);
	//remove all
	void removeSubTree(node* ptr);
public:
	//AVL(int key, string alphaKey, string nombre, string desc);
	AVL();
	~AVL();
	void addLeaf(int key, string alphaKey, string nombre, string desc);
	int returnRootKey();
	void printRootKey(int key);
	int findSmallest();

	void printInOrder();
	void printPreOrder();

	// following tuts
	void removeNode(int key);

	// AVL stuff
	int max(int a, int b);
	int height(node* n);

	node* rightRotate(node* y);
	node* leftRotate(node* x);
	int getBalance(node* n);

	node* balanceTree(int key, node* root);
};

