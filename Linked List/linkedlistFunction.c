#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
}Node;


void display(Node *node);


void main()
{  
        Node *head=(Node*)malloc(sizeof( Node*));
        while(1){
                int option,val=0;
                printOpetions();
                scanf("%d",&option);
                switch(option)
                {
                        case 1:
                                printf("Enter the element to insert at beginning");
                                scanf("%d",&val);
                                //printf("Enter the element to bef");
                                //insertAtBeginning();
                                break;
                        case 2:
                                printf("Enter the element to insert at end");
                                scanf("%d",&val);
                                //insertAtEnd();
                                break;
                        case 3:
                                prinf("Enter the positiion to push");
                                printf("Enter the element to insert at middle");
                                scanf("%d",&val);
                                //insertAfterValue();
                                break;
                        case 4:
                                printf("\nEnter the element to pop");
                                scanf("%d",&val);
                                //pop(val);
                                break;
                        case 5:
                                break;
                        default:
                                return;
                }
        }
        return;
}
void printOptions()
{
    printf("Enter your choice\n");
    printf("\n1.insert \n2.Delete \n3.display \n4.pop a element \n5.findlength \n6.");
} 
void insert(Node *head,int val,int before)
{
        
}
void display(Node *head)
{
        int  count = 1;
        Node *p=(Node*) malloc(sizeof(Node*));
        p = head;
        while (p != NULL)
        {
                printf ("%d\t",p->data);
        }
        count++;
        p = p->next;      
}
