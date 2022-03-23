#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int data;
    int priority;
    struct node *next;
} Node; // * new, *prev, *temp, *start, *end;
Node *head = NULL, *tail = NULL;
void push()
{
    Node *temp = (Node*)malloc(sizeof(Node));
    printf("Enter the value to push ");
    scanf("%d", &temp->data);
    printf("\nEnter the priority value ");
    scanf("%d",&temp->priority);
    temp->next = NULL;
    Node *curr=head,*prev=head;
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else if(head->priority>temp->priority)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        curr=curr->next;
        while(curr!=NULL && temp->priority>=curr->priority)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=temp;
        temp->next=curr;
    }
}
void pop()
{
    if (head == NULL)
        printf("queue is empty");
    else
    {
        printf("%d is popped", head->data);
        head = head->next;
    }
}
void display()
{
    if (head == NULL)
        printf("\nqueue is empty");
    else
    {
        Node *temp = head;

        printf("\nThe values are");
        while (temp != NULL)
        {
            printf("%d - %d ->", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}
void peek()
{
    if (head == NULL)
    {
        printf("\nqueue is empty");
    }
    else
        printf("the element at top is %d", head->data);
}
void main()
{
    while (1)
    {
        int option, val = 0;
        printf("\nEnter your choice\n1.push\n2.pop\n3.display\n4.peek\n5.exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            return;
        }
    }
}