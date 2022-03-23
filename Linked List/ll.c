#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct 
{
    int data;
    struct node *next;
}Node; // * new, *prev, *temp, *start, *end;
Node *head=NULL;

void insertPos(int data, int pos)
{
   
    int i=1;
    Node *new=(Node*)malloc(sizeof(Node*));
    new->data=data;
    new->next=NULL;
    if (head==NULL)
    {
       head=new;
    }
    else
    {
         Node *temp=head;
        if(pos==1)
        {
            new->next=head;
            head=new;
            return;
        }
        else
        {
            Node *prev;
            while (temp!= NULL && (i < pos-1 || pos==-99))
            {
                prev=temp;
                temp = temp->next;
                i++;
            }
            if ((temp==NULL && i == pos) || pos==-99)
            {
                prev->next=new;
            }
            else if(temp!=NULL)
            {
                new->next = temp->next;
                temp->next = new;
            }
            else
            {
                printf("\nsize of link list is %d",i-1);
                return;
            }
        }
    }
    printf("\nInserted Successfully");
}
void delete (int data)
{
   
    if (head==NULL)
        printf("\nList is Empty");
    else
    {
        if(head->data==data)
        {
            head=head->next;
            return;
        }
        Node *temp=head->next;
        //temp = start;
        Node *prev=head;
        while (temp!= NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp== NULL)
        {
            printf("\nData Not Found");
            return;
        }
        else 
        {
            prev->next = temp->next;
            free(temp);
        }
        printf("\n deleted successfully");
    }
}
void search(int data)
{
    if (head==NULL)
        printf("\nList is empty");
    else
    {
        Node *temp=head;
        int i=1;
        //temp = start;
        while (temp != NULL && temp->data != data)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL )
            printf("\n%d is not found", data);
        else
            printf("\n%d is found in %d position", temp->data, i);
    }
}
void display()
{
    if (head==NULL)
        printf("\nList is empty");
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
void main()
{
    int option, c, element, position;
    while(1)
    {
        printf("\nSingle Linked List\n1.Insert Begin\n2.Insert End\n3.Insert in Position\n4.Delete\n5.Search\n6.Display\n7.exit\nEnter your option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter Element to inser at beginning:");
                scanf("%d", &element);
                insertPos(element,1);
                //insertbeginning(element);
                /*
                void inser..(int eleme)
                {
                    node* temp=(node*)malloc(sizeof(node));
                    temp->val=elem;
                    temp->next=NULL;
                    if(head==NULL)
                        head=temp;
                    else
                    {
                        temp->next=head;
                        head=temp;
                    }

                }*/
                break;
            case 2:
                printf("Enter Element to insert at end:");
                scanf("%d", &element);
                insertPos(element,-99);
                /*insert at end
                vodi inser
                {
                    node* temp=(node*)malloc(sizeof(node));
                    temp->val=elem;
                    temp->next=NULL;
                    if(head==NULL)
                        head=temp;
                    else
                    {
                        node* head1=head;
                        while(head1->next!=null)
                        //for(;head1->next!=null;)
                            head1=head1->next;
                        head1->next=temp;
                    

                }*/
                break;
            case 3:
                printf("Enter Elementto insert in particular index:");
                scanf("%d", &element);
                printf("Enter Position to insert:");
                scanf("%d", &position);
                insertPos(element, position);

                /*
                void isnertpos(int pos,int elem)
                {
                    if(pos==1)
                    {
                        inserthead();
                        return;
                    }
                    node* temp=(node*)malloc(sizeof(node));
                    temp->val=elem;
                    temp->next=NULL;
                    int i=1;
                    node* head1=head;
                    while(i<pos)
                    {
                        if(head1==NULL)
                        {
                            printf("There is no such index");
                            return;
                        }
                        head1=head1->next;
                        i++;
                    }
                
                    temp->next=head1->next;
                    head1->next=temp;
                    

                    
                }*/
                break;
            case 4:
                printf("Enter the element to be deleted:");
                scanf("%d", &element);
                delete (element);
                break;
            case 5:
                printf("Enter Element to search:");
                scanf("%d", &element);
                search(element);
                break;
            case 6:
                display();
                break;
            case 7:
                return;
            default:
                printf("\nInvalid Case");
                break;
        }
    }
}