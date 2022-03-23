#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;

int get(){
    int num = 0;
    printf("\nEnter a number: ");
    scanf("%i", &num);
    return num;
}

Node* create_node(data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_at_beginning(){
    Node *new_node = create_node(get());
    
    if(!head) {
        head = new_node;
        head->next = new_node;
        tail = head;
    }else{
        Node *temp = head;
        new_node->next = temp;
        head = new_node;
        tail->next = new_node;
    }
}

void insert_at_end(){
    Node *new_node = create_node(get());

    if(!head) {
        head = new_node;
        head->next = new_node;
        tail = head;
    }else{
        new_node->next = head;
        tail->next = new_node;
        tail = new_node;
    }
}

Node* delete_at_beginning(){
    if(!head) return NULL;

    Node *temp = head;

    if(head->next == head){
        head = NULL;
        tail = NULL;
        return temp;
    }

    head = head->next;
    tail->next = head;
}

Node* delete_at_end(){
    if(!head) return NULL;

    Node *temp = tail;

    if(head->next == head){
        head = NULL;
        tail = NULL;
    }else{
        Node *node = head;

        while(node->next != tail)  node = node->next;
        
        tail = node;
        tail->next = head;
        temp->next = NULL;
    }

    printf("\n%i is removed.\n", temp->data);
    return temp;
}

void display(){

    if(!head) puts("\nNothing to show");
    else{
        puts("");
        Node *node = head;
        while(node && node->next != head){
            printf("\n%i",node->data);
            node = node->next;
        }
        if(node) printf("\n%i",node->data);        
        puts("");
    }

}


int main()
{
    while(1){
        int option;
        puts("\n------------------------------------\n0. Exit\n1. Insert Beginning\n2. Insert End\n3. Remove at Beginning\n4. Remove at End\n5. Display\n------------------------------------");
        scanf("%i", &option);
        if(!option) break;

        switch(option){
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_end();
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
                puts("\nInvalid Option");
                break;
        }

    }
    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>
// #include<math.h>
// typedef struct 
// {
//     int data;
//     struct node *next;
// }Node; // * new, *prev, *temp, *start, *end;
// Node *head=NULL,*tail=NULL,*prev,*temp,*new;

// void insertPos(int data, int pos)
// {
   
//     int i=1;
//     new=(Node*)malloc(sizeof(Node));
//     new->data=data;
//     new->next=NULL;
//     if (head==NULL)
//     {
//        head=new;
//        new->next=head;
//        tail=head;
//     }
//     else
//     {
//         temp=head;
//         if(pos==1)
//         {
//             new->next=head;
//             head=new;
//             tail->next=new;
//             return;
//         }
//         else
//         {
//            while ((temp!= head || i==1) && (i < pos || pos==-99))
//             {
//                 prev=temp;
//                 temp = temp->next;
//                 i++;
//             }
//             if ((temp==head && i == pos) || pos==-99)
//             {
//                 prev->next=new;
//                 new->next=head;
//                 tail=new;
//             }
//             else if(temp!=head)
//             {
//                 new->next = prev->next;
//                 prev->next = new;
//             }
//             else
//             {
//                 printf("\nsize of link list is %d",i);
//                 return;
//             }
//         }
//     }
//     printf("\nInserted Successfully");
// }
// void delete (int data)
// {
//     int i=0;
//     if (head==NULL)
//         printf("\nList is Empty");
//     else
//     {
//         temp=head;
//         //temp = start;
//         while ((temp!= head || i==0) && temp->data != data)
//         {
//             prev = temp;
//             temp = temp->next;
//             i++;
//         }
//         if (temp==head && i>0)
//         {
//             printf("\nData Not Found");
//             return;
//         }
//         else if (head==temp && i==0)
//         {
//             head = head->next;
//             tail->next=head;
//         }
//         else if (temp->data == data)
//         {
//             prev->next = temp->next;
//             free(temp);
//         }
//         printf("\n deleted successfully");
//     }
// }
// void search(int data)
// {
//     if (head==NULL)
//         printf("\nList is empty");
//     else
//     {
//         temp=head;
//         int i=1;
//         //temp = start;
//         while ((temp != head || i==1) && temp->data != data)
//         {
//             temp = temp->next;
//             i++;
//         }
//         if (temp->data != data)
//             printf("\n%d is not found", data);
//         else
//             printf("\n%d is found in %d position", temp->data, i);
//     }
// }
// void display()
// {
//     int i=0;
//     if (head==NULL)
//         printf("\nList is empty");
//     else
//     {
       
//         temp = head;
    
//         printf("\nThe values are");
//         while (temp != head || i==0)
//         {
//             printf("%d->", temp->data);
//             temp = temp->next;
//             i++;
//         }
//     }
// }
// void main()
// {
//     int option, c, element, position;
//     while(1)
//     {
//         printf("\nSingle Linked List\n1.Insert Begin\n2.Insert End\n3.Insert in Position\n4.Delete\n5.Search\n6.Display\n7.exit\nEnter your option:");
//         scanf("%d",&option);
//         switch(option)
//         {
//             case 1:
//                 printf("Enter Element to inser at beginning:");
//                 scanf("%d", &element);
//                 insertPos(element,1);
//                 break;
//             case 2:
//                 printf("Enter Element to insert at end:");
//                 scanf("%d", &element);
//                 insertPos(element,-99);
//                 break;
//             case 3:
//                 printf("Enter Elementto insert in particular index:");
//                 scanf("%d", &element);
//                 printf("Enter Position to insert:");
//                 scanf("%d", &position);
//                 insertPos(element, position);
//                 break;
//             case 4:
//                 printf("Enter the element to be deleted:");
//                 scanf("%d", &element);
//                 delete (element);
//                 break;
//             case 5:
//                 printf("Enter Element to search:");
//                 scanf("%d", &element);
//                 search(element);
//                 break;
//             case 6:
//                 display();
//                 break;
//             case 7:
//                 return;
//             default:
//                 printf("\nInvalid Case");
//                 break;
//         }
//     }
// }