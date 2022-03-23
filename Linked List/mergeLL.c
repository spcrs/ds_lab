#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct 
{
    int data;
    struct node *next;
}Node; 
Node *head=NULL,*tail=NULL,*head1=NULL,*tail1=NULL;
void display()
{

    if (head == NULL)
        printf("\nNothing to show");
    else
    {

        Node *node = head;
        do
        {
            printf(" %d ->", node->data);
            node = node->next;
        } while (node != NULL);
    }
    printf("\n");
}
void insert(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void display1()
{

    if (head == NULL)
        printf("\nNothing to show");
    else
    {

        Node *node = head1;
        do
        {
            printf(" %d ->", node->data);
            node = node->next;
        } while (node != NULL);
    }
    printf("\n");
}
void insert1(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (head1 == NULL)
    {
        head1 = temp;
        tail1 = head1;
    }
    else
    {
        tail1->next = temp;
        tail1 = temp;
    }
}

void main()
{
    int n, val;
    printf("Enter no of values for list 1 ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter a value to insert in Linked list  ");
        scanf("%d", &val);
        insert(val);
    }
    printf("\n\nThe values in first Linked list are \n");
    display();
    printf("Enter no of values for list 2 ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter a value to insert in Linked list  ");
        scanf("%d", &val);
        insert1(val);
    }
    printf("\n\nThe values in second Linked list are \n");
    display1();
    tail->next=head1;
    printf("\nMerged list is ");
    display();
}