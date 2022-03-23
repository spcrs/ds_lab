#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct Node 
{
    int data;
    struct Node *next;
}*head,*temp,*temp1,*prev; 
struct stack
{
    struct Node *curr;
    struct stack *next;
}*head1,*tempstack;
void main()
{
    int n,i=0,val;
    printf("Enter no of values\n");
    scanf("%d",&n);
    while(i<n)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        tempstack=(struct stack*)malloc(sizeof(struct stack));
        printf("Enter the value \n");
        scanf("%d",&val);
        temp->data=val;
        temp->next=NULL;
        if(i==0)
        {
            head=temp;
            prev=head;

            tempstack->curr=head;
            tempstack->next=NULL;
            head1=tempstack;
        }
        else    
        {
            prev->next=temp;
            prev=temp;
            
            tempstack->next=head1;
            tempstack->curr=temp;
            head1=tempstack;
        }
        i++;
    }
   
    printf("Given values are\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%i  ",temp->data);
        temp=temp->next;
    }
    prev=head1->curr;
    head=head1->curr;
    head1=head1->next;
    printf("\n");
    while(head1!=NULL)
    {
        tempstack=head1;
        prev->next=tempstack->curr;
        
        prev=prev->next;
        if(head1->next==NULL)
        {
                prev->next=NULL;
        }
        head1=head1->next;
    }
    printf("\nAfter arranging\n");
     while(head!=NULL)
    {
        printf("%i  ",head->data);
        head=head->next;
    }
}