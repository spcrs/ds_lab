#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;
void insert_at_beginning(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (!head)
    {
        head = new_node;
        head->prev = new_node;
        head->next = new_node;
        tail = head;
    }
    else
    {
        //Node *temp = head;
        new_node->next = head;
        head->prev=new_node;
        new_node->prev = tail;
        head = new_node;
        tail->next = head;
    }
}

void insert_at_end(int data)
{
    if (!head)
        insert_at_beginning(data);
    else
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
        new_node->prev = tail;
        new_node->next = head;
        tail->next = new_node;
        tail = new_node;
        head->prev=tail;
    }
}
void delete_at_beginning()
{
    if (!head)
        return;
    Node *temp = head;
    if (head->next == head)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    printf("\n%i is removed\n", temp->data);
}
void delete_at_end()
{
    if (!head)
        return ;
    if (head->next == head)
        delete_at_beginning();
    else
    {
        Node *temp = tail->prev;
        temp->next = head;
        head->prev = temp;
        printf("\n%d is removed.\n", tail->data);
        tail = temp;
    }
}

void display()
{

    if (!head)
        printf("\nNothing to show");
    else
    {
        Node *node = head;
        do
        {
            printf("%i->", node->data);
            node = node->next;
        } while (node != head);
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        int option, number;
        printf("\n1. Insert Beginning\n2. Insert end \n3.Remove at Beginning\n4. Remove at End\n5. Display");
        scanf("%i", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter a number: ");
            scanf("%d", &number);
            insert_at_beginning(number);
            break;
        case 2:
            printf("\nEnter a number: ");
            scanf("%d", &number);
            insert_at_end(number);
            break;
        case 3:
            delete_at_beginning();
            break;
        case 4:
            delete_at_end();
            break;
        case 5:
            display();
            break;
        default:
            printf("\nInvalid Option");
            return;
        }
    }
    return 0;
}