#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void printReverseOrder(struct Node* head1)
{
    if(head1==NULL)
    {        
        return;
    }
    printReverseOrder(head1->next);
    printf("<-%d",head1->data);
}
void main()
{   
    int n;
    printf("Enter no of values");
    scanf("%d",&n);
    struct Node *head=malloc(sizeof(struct Node*));

    //struct Node *head1=head;
    struct Node *head1=head;
   
    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        if(i==0)
        {   
            head1->data=val;
            head1->next=NULL;
            //prev=head;
        }
        else
        {
            struct Node *temp=malloc(sizeof(struct Node*));
            head1->next=temp;
            head1=head1->next;
            head1->data=val;
            //printf("%d",head1->data);
            head1->next=NULL;
        }
    }
    head1=head;
    while(head1!=NULL)
    {
        printf("%d->",head1->data);
        head1=head1->next;
    }
    printf("\n");

    
    
    
    
    struct Node *prev=head;

    head1=head->next;
    while(head1!=NULL)
    {
        struct Node *temp=head1->next;
        head1->next=prev;
        prev=head1;
        head1=temp;
        struct Node *temp1=prev;
    }
    head->next=NULL;
    head=prev;
    head1=head;
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    // printf("d7yfu");
    printf("\n");
    printReverseOrder(head1);
    // printf("d7yfu");
    
}



//head=head1;
//prev->next=temp;
/*while(temp1!=NULL && head1!=NULL)
        {
        printf("%d->",temp1->data);
        temp1=temp1->next;
        }*/

//printf("prev val %d head1 val %d",prev->data,head1->data);
//printf("\n"); 
        //printf("\n");