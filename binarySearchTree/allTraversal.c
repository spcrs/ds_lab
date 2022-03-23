#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int val;
    struct node *left;
    struct node *right;
}node;
node* insert(node *root,int val)
{
    if(root==NULL)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->val=val;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if(root->val<val)
    {
        root->right=insert(root->right,val);
    }
    else
        root->left=insert(root->left,val);
    return root;
}
int findMin(node* root)
{
    while(root->left!=NULL)
        root=root->left;
    printf("%d",root->val);
    return root->val;
}
node* delete(node *root,int val)
{
    if(root==NULL)
        return NULL;
    if(root->val<val)
    {
        root->right=delete(root->right,val);
    }
    else if(root->val>val)
    {
        root->left=delete(root->left,val);
    }
    else
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        else if(root->right==NULL)
        {
            return root->left;
        }
        int min=findMin(root->right);
        node* temp1=root->right;
        printf("%d",temp1->val);
        root->val=min;
        root->right=delete(root->right,min);
    }
    return root;
    
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

void printTree(node* root,int space)
{
    if(root==NULL)
        return;
    space=space+2;
    printTree(root->right,space);
    for(int i=0;i<=space;i++)
        printf("  ");
    printf("%d\n",root->val);
    printTree(root->left,space);
}
void main()
{
    node* root=NULL;
    root=insert(root,72);
    root=insert(root,54);
    root=insert(root,81);
    root=insert(root,45);
    root=insert(root,63);
    root=insert(root,67);
    printf("\nTree view in-order");
    inorder(root);
    printf("\nTree view pre-order  ");
    preorder(root);
    printf("\nTree view post-order  ");
    postorder(root);
    printf("\n");
    printTree(root,0);

    root=delete(root,72);

    printf("\nTree view in-order");
    inorder(root);
    printf("\nTree view pre-order  ");
    preorder(root);
    printf("\nTree view post-order  ");
    postorder(root);
    printf("\n");


    //printf("dhfh");
    printTree(root,0);
}
