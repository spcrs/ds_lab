#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
}*head,*temp, *temp1, *new1, *prev,*tail; 
void insertpos(int val, int pos)
{
    int i = 1;
    new1 = (struct Node *)malloc(sizeof(struct Node));
    new1->data = val;
    new1->left = NULL;
    new1->right = NULL;
    if (head == NULL)
    {
        head = new1;
        head->right=head;
        head->left=head;
        tail=head;
    }
    else
    {
        if (pos == 1)
        {
            new1->right = head;
            head->left = new1;
            head = new1;
            new1->left=tail;
            tail->right=new1;
        }
        else
        {
            temp = head;
            while((temp != head || i==1) && (i < pos || pos == -99))
            {
                temp = temp->right;
                i++;
            }
            if ((temp == NULL && i == pos) || pos == -99)
            {
                new1->left = temp->left;
                new1->right=temp;
                temp->left->right = new1;
                temp->left=new1;
               
            }
            else if (temp != head )
            {
                new1->right = temp->right;
                new1->left = temp;
                temp1 = temp->right;
                temp1->left = new1;
                temp->right = new1;
            }
            else
            {
                printf("\nsize of link list is %d", i);
                return;
            }
        }
    }
    printf("\nInserted Successfully");
}
void delete (int data)
{
    int i=0;
    if (head == NULL)
        printf("\nList is Empty");
    else
    {
        temp = head;
        while ((temp != head || i==0) && temp->data != data)
        {
            prev = temp;
            temp = temp->right;
            i++;
        }
        if (temp->data != data)
        {
            printf("\nData Not Found");
            return;
        }
        else if (head == temp && i==0)
        {
            head = head->right;
            head->left = tail;
            tail->right=head;
        }
        else
        {
            prev->right = temp->right;
            temp1 = temp->right;
            temp1->left = prev;
            //free(temp);
        }
    }
    printf("\ndeleted successfully");
}
void search(int data)
{
    int choice, i = 1;
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        temp = head;
        while ((temp != head || i==1) && temp->data != data)
        {
            temp = temp->right;
            i++;
        }
        if (temp->data != data)
            printf("\n%d is not found", data);
        else
            printf("\n%d is found in %d position", temp->data, i);
    }
}
void display()
{
    int i=0;
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        temp = head;
        printf("\n ");
        while (temp != head || i==0)
        {
            printf("%d\t", temp->data);
            temp = temp->right;
            i++;
        }
    }
}
void main()
{
    int option, c, element, position;
    printf("\nDoubly Linked List Implementation");
    while (1)
    {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert in Position\n4.Delete\n5.Search\n6.Display\n7.exit \nEnter your option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Element:");
            scanf("%d", &element);
            insertpos(element, 1);
            break;
        case 2:
            printf("Enter Element:");
            scanf("%d", &element);
            insertpos(element, -99);
            break;
        case 3:
            printf("Enter Element:");
            scanf("%d", &element);
            printf("Enter Position:");
            scanf("%d", &position);
            insertpos(element, position);
            break;
        case 4:
            printf("Enter Element:");
            scanf("%d", &element);
            delete (element);
            break;
        case 5:
            printf("Enter Element:");
            scanf("%d", &element);
            search(element);
            break;
        case 6:
            display();
            break;
        default:
            printf("\nInvalid Case");
            return;
            break;
        }
    }
}