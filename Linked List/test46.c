#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *temp = NULL, *tail = NULL;

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
        } while (node != head);
    }
    printf("\n");
}
void insert(int val)
{
    temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        head->next = head;
        tail = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        temp->next = head;
    }
}
int non_zero_count()
{
    Node *node = head;
    int count=0;
    do
    {
        if(node->data!=0)
            count++;
        node = node->next;
    } while (node != head);
    printf("\nNumber of non-zero values are %d",count);
}
void main()
{
    int n, val;
    printf("Enter no of values ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the value to insert in Linked list  ");
        scanf("%d", &val);
        insert(val);
    }
    printf("\n\nThe values in Linked list are \n");
    display();
    non_zero_count();
    printf("\n");
} 