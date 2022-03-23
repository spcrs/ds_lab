#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int data;
    int priority;
    struct node *next;
    struct node *prev;
} Node; // * new, *prev, *temp, *start, *end;
Node *head = NULL, *tail = NULL;
void display()
{
    if (head==NULL)

        printf("\nNow queue is empty");
    else
    {
        Node *temp = head;
    
        printf("\nNow The values are ");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}
void insertBeginning()
{
    Node *temp=(Node *)malloc(sizeof(Node));
    printf("Enter the value to insert ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    display();
}
void insertEnd()
{
    if(head==NULL)
    {
        insertBeginning();
        return;
    }
    Node *temp=(Node *)malloc(sizeof(Node));
    printf("Enter the value to insert ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    display();
}
void DeleteBeginning()
{
    if(head==NULL)
        printf("\nqueue is empty");
    else
    {
        head=head->next;
        if(head==NULL)
        {
            tail=NULL;
            head=NULL;
        }
        else
            head->prev=NULL;
    }
    display();
}
void DeleteEnd()
{
    if(head==NULL)
        printf("\nqueue is empty");
    else{
        tail=tail->prev;
        if(tail==NULL)
        {
            tail=NULL;
            head=NULL;
        }
        else
            tail->next=NULL;
    }
    display();
}
void main()
{
    while (1)
    {
        int option, val = 0;
        printf("\nEnter your choice\n1.insert beginning  2.insert End\n3.Delete beginning  4.Delete End\n5.exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertBeginning();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            DeleteBeginning();
            break;
        case 4:
            DeleteEnd();
            break;
        default:
            return;
        }
    }
}