

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct 
{
    int data;
    struct node *next;
}Node; // * new, *prev, *temp, *start, *end;
Node *head=NULL,*tail=NULL;
void push(int val)
{
    Node *temp=(Node*)malloc(sizeof(Node*));
    temp->data=val;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=head;
    }
    else{
        tail->next=temp;
        tail=tail->next;
    }
}
void pop()
{
    if(head==NULL)
        printf("queue is empty");
    else
    {
        printf("%d is popped",head->data);
        head=head->next;
    }
}
void display()
{
    if (head==NULL)
        printf("\nqueue is empty");
    else
    {
        Node *temp = head;
    
        printf("\nThe values are");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}
void peek()
{
    if(head==NULL)
    {
        printf("\nqueue is empty");
    }
    else
        printf("the element at top is %d",head->data);
}
void main()
{
    while(1)
    {
        int option, val = 0;
        printf("\nEnter your choice\n1.push\n2.pop\n3.display\n4.peek\n5.peek\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value to push");
            scanf("%d", &val);
            push(val);
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