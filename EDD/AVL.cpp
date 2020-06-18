#include <iostream>
#include <cstdlib>
#include "AVL.h"

using namespace std;

AVL::AVL()
{
	root = NULL;
}
AVL::node* AVL::createLeaf(int key,string alphaKey,string nombre,string desc)
{
	node* n = new node;
	n->key = key;
	n->alphaKey = alphaKey;
	n->nombre = nombre;
	n->desc = desc;
	n->height = 1;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void AVL::addLeaf(int key, string alphaKey, string nombre, string desc)
{
	root = addLeafPrivate(root, key,alphaKey, nombre, desc);
}

// balanced failure
AVL::node* AVL::balanceTree(int key, node* root)
{
	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && key < root->left->key)
		return rightRotate(root);

	if (balance < -1 && key > root->right->key)
		return leftRotate(root);

	if (balance > 1 && key > root->left->key)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && key < root->right->key)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

AVL::node* AVL::addLeafPrivate(node* node, int key, string alphaKey, string nombre, string desc)
{
	// Addding without balance
	/*
	if (root == NULL)
	{
		root = createLeaf(key);
	}
	else if (key < ptr->key)
	{
		if (ptr->left != NULL)
		{
			addLeafPrivate(key, ptr->left);
		}
		else
		{
			ptr->left = createLeaf(key);
		}
	}
	else if (key > ptr->key)
	{
		if (ptr->right != NULL)
		{
			addLeafPrivate(key, ptr->right);
		}
		else
		{
			ptr->right = createLeaf(key);
		}
	}
	else
	{
		cout << "El valor ya existe en el arbol";
	}
	*/

	// adding with balance
	 // Agregando nodos como arbo de busqueda normal
	if (node == NULL)
		return(createLeaf(key,alphaKey, nombre, desc));

	if (key < node->key)
		node->left = addLeafPrivate(node->left, key,alphaKey, nombre, desc);
	else if (key > node->key)
		node->right = addLeafPrivate(node->right, key, alphaKey, nombre, desc);
	else // no se aceptan duplicados
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node); 

	// In case it's inbalance then perform one of this cases
	// Left Left Case  
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case  
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case  
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case  
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;

}

void AVL::printInOrder()
{
	printInOrderPrivate(root);
}

void AVL::printInOrderPrivate(node* ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
		{
			printInOrderPrivate(ptr->left);
		}
		cout << ptr->key << " ";

		if (ptr->right != NULL)
		{
			printInOrderPrivate(ptr->right);
		}
	}
	else
	{
		cout << "El arbol esta vacio\n";
	}
}

void AVL::printPreOrder()
{
	printPreOrderPrivate(root);
}

void AVL::printPreOrderPrivate(node* ptr)
{
	if (ptr != NULL)
	{
		cout << ptr->key << " " << ptr->nombre << ", ";
		printPreOrderPrivate(ptr->left);
		printPreOrderPrivate(ptr->right);
	}
}

AVL::node* AVL::returnNode(int key)
{
	return returnNodePrivate(key, root);
}

AVL::node* AVL::returnNodePrivate(int key, node* ptr)
{
	if (ptr != NULL)
	{
		if (ptr->key == key)
		{
			return ptr;
		}
		else
		{
			if (key < ptr->key)
			{
				return returnNodePrivate(key, ptr->left);
			}
			else
			{
				return returnNodePrivate(key, ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}

int AVL::returnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		// about returning this
		return -100;
	}
}

void AVL::printRootKey(int key)
{
	node* ptr = returnNode(key);
	if (ptr != NULL)
	{
		cout << "Parent node = " << ptr->key << endl;

		ptr->left == NULL ?
			cout << "Left child = NULL \n" :
			cout << "Left child = " << ptr->left->key << endl;

		ptr->right == NULL ?
			cout << "Right child = NULL \n" :
			cout << "Right child = " << ptr->right->key << endl;
	}
	else
	{
		cout << "Key " << "is not in the tree\n";
	}

}

int AVL::findSmallestPrivate(node* ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty";
		return -100;
	}
	else
	{
		if (ptr->left != NULL)
		{
			return findSmallestPrivate(ptr->left);
		}
		else
		{
			return ptr->key;
		}
	}
}

int AVL::findSmallest()
{
	return findSmallestPrivate(root);
}

void AVL::removeNode(int key)
{
	removeNodePrivate(key, root);
}

void AVL::removeNodePrivate(int key, node* parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			removeRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					removeMatch(parent, parent->left, true) :
					removeNodePrivate(key, parent->left);
			}
			// copia
			else if (key > parent->key&& parent->right != NULL)
			{
				parent->right->key == key ?
					removeMatch(parent, parent->right, false) :
					removeNodePrivate(key, parent->right);
			}
			else
			{
				cout << "No existe valor";
			}
		}
	}
	else
	{
		cout << "Arbol Vacio";
	}
}

void AVL::removeRootMatch()
{
	if (root != NULL)
	{
		node* deletePtr = root;
		int rootKey = root->key;
		int smallestRightSubTree;

		// eliminar raiz sin hijos
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete deletePtr;
		}
		// eliminar nodo con 1 hijo a la derecha
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			deletePtr->right = NULL;
			delete deletePtr;
			cout << "La raiz con valor: " << rootKey << "se elimino" <<
				"La nueva raiz es" << rootKey << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			deletePtr->left = NULL;
			delete deletePtr;
			cout << "La raiz con valor: " << rootKey << "se elimino" <<
				"La nueva raiz es" << rootKey << endl;
		}
		else
		{
			smallestRightSubTree = findSmallestPrivate(root->right);
			removeNodePrivate(smallestRightSubTree, root);
			root->key = smallestRightSubTree;
			cout << "Se elimino" << rootKey << " sustituye " << root->key << endl;
		}
	}
	else
	{
		cout << "lista vacia \n";
	}
}

void AVL::removeMatch(node* parent, node* match, bool left)
{
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;

		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ?
				parent->left = NULL : parent->right = NULL;
			delete delPtr;
			cout << "The node containing match key " << matchKey << " was removed\n";
		}
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ?
				parent->left = match->right :
				parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing match key " << matchKey << " was removed\n";
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ?
				parent->left = match->left :
				parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing match key " << matchKey << " was removed\n";
		}
		else
		{
			smallestInRightSubtree = findSmallestPrivate(match->right);
			removeNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else
	{
		cout << "removeMatch cant be executed, the tree is empty. \n";
	}
}


AVL::~AVL()
{
	removeSubTree(root);
}

void AVL::removeSubTree(node* ptr)
{
	if (ptr != NULL)
	{
		if (ptr->left != NULL)
		{
			removeSubTree(ptr->left);
		}
		if (ptr->right != NULL)
		{
			removeSubTree(ptr->right);
		}
		//cout << "deleting key: " << ptr->key << endl;
		delete ptr;
	}

}


// AVL Stuff
int AVL::max(int a, int b)
{
	return (a > b) ? a : b;
}

// all heights are 1.
int AVL::height(node* n)
{
	if (n == NULL)
		return 0;
	return n->height;
}

int AVL::getBalance(node* n)
{
	if (n == NULL)
		return 0;
	return height(n->left) - height(n->right);
}

AVL::node* AVL::rightRotate(node* y)
{
	node* x = y->left;
	node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	return x;
}

AVL::node* AVL::leftRotate(node* x)
{
	node* y = x->right;
	node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}


