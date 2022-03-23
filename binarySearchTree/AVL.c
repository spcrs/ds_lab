#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int val,height;
    struct node *left;
    struct node *right;
}node;



/* Print nodes at a current level */
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d-%d ", root->val,root->height);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height1(node* node)
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


void printLevelOrder(node* root)
{
    int h = height1(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 

int height(node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

int getBalance(node *root)
{
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

node* leftRotation(node* temp)
{
    
    node *n=temp->right;
    node *t=n->left;

    n->left=temp;
    temp->right=t;
    
    temp->height=1+max(height(temp->left),height(temp->right));
    n->height=1+max(height(n->left),height(n->right));
    return n;
}

node* rightRotation(node* temp)
{
    // printf("%d %d\n",temp->val,temp->height);
    node *n=temp->left;
    node *t=n->right;

    n->right=temp;
    temp->left=t;

    temp->height=1+max(height(temp->left),height(temp->right));
    n->height=1+max(height(n->left),height(n->right));
    // printf("%d %d\n",temp->val,temp->height);
    return n;
}

node* insert(node *root,int val)
{
    if(root==NULL)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->val=val;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=1;
        return temp;
    }
    if(root->val<val)
    {
        root->right=insert(root->right,val);
    }
    else if(root->val>val)
        root->left=insert(root->left,val);
    else
        return NULL;
    root->height=1+max(height(root->left),height(root->right));
    // printf("%d   %d  %d \n",root->val,height(root->left),height(root->right));
    int balance=getBalance(root);
    if(balance<-1 && root->right->val<val)
        return leftRotation(root);
    if(balance>1 && root->left->val>val)
        return rightRotation(root);
    if(balance<-1 && root->right->val>val)
    {
            root->right=rightRotation(root->right);
            return leftRotation(root);
    }
    if(balance>1 && root->left->val<val)
    {
        root->left=leftRotation(root->left);
        return rightRotation(root);
    }
    return root;
}


/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/


void main()
{
    node *root=NULL;
     printf("\nTree view in-order");
    root=insert(root,72);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,54);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,81);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,45);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,63);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,67);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,50);
    printf("\nTree view in-order");
    printLevelOrder(root);
    root=insert(root,90);
    printf("\nTree view in-order");
    printLevelOrder(root);
     root=insert(root,100);
    printf("\nTree view in-order");
    printLevelOrder(root);    
}
