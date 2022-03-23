// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
}*root=NULL;

int height1(struct Node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height1(node->left);
		int rheight = height1(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

void display(struct Node *r, int space)
{
	int i;

	if(r!=NULL)
	{
		space+=1;
		display(r->right, space);
		for (i = 1; i < space; i++)
			printf("\t");
		printf("%d\n", r->height);
		display(r->left, space);
	}
}

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
	struct Node *node = (struct Node *)
		malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node *insert(struct Node *node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return (newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						   height(node->right));

}

struct Node * fixtree(struct Node *node)
{
//newcode
	if (node == NULL)
		return NULL;

		node->left = fixtree(node->left);
		node->right = fixtree(node->right);




//now code end
int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && node->key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && node->key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && node->key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && node->key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;

}


void main ()
{
    root=insert(root,45);
    root=insert(root,35);
    root=insert(root,46);
    root=insert(root,48);
    root=insert(root,50);
    root=insert(root,55);
    root=insert(root,33);
    root=insert(root,29);
    display(root,2);

    fixtree(root);
    display(root,2);

}
