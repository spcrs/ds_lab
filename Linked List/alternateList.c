#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int data;
    struct node *next;
} Node;
Node *head = NULL, *tail = NULL, *head1 = NULL, *tail1 = NULL;
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
void alternate()
{
    Node *temp_head = head;
    while (temp_head != NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = temp_head->data;
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
        if (temp_head->next == NULL)
        {
            return;
        }
        temp_head = temp_head->next;
        temp_head = temp_head->next;
    }
}
void main()
{
    int n, val;
    printf("Enter no of values for list 1 ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the value to insert in Linked list  ");
        scanf("%d", &val);
        insert(val);
    }
    printf("\n\nThe values in Linked list are \n");
    display();

    alternate();
    printf("\nThe Alternate linked list is ");
    display1();
}