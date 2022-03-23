#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*head,*temp,*temp1,*prev; 
void display()
{
    temp1=head;
    while(temp1!=NULL)
    {
        printf("%d  ",temp1->data);
        temp1=temp1->next;
    }
}
void main()
{
    int n,i=0,val;
    printf("Enter no of values\n");
    scanf("%d",&n);
    while(i<n)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value \n");
        scanf("%d",&val);
        temp->data=val;
        temp->next=NULL;
        if(i==0)
            head=temp;
        else    
        {
            temp->next=head;
            head=temp;
        }
        i++;
    }
    printf("\n\nGiven values are\n");
    display();
    temp1=head->next;
    prev=head;
    while(temp1!=NULL)
    {
        if(temp1->data<0)
        {
            prev->next=temp1->next;
            free(temp1);
            temp1=prev->next;
        }
        else
        {
            prev=temp1;
            temp1=temp1->next;
        }
    }
    if(head->data<0)
        head=head->next;
    printf("\nAFter deleting negative values\n");
    display();
}



