#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
}*head,*temp, *temp1, *new1, *prev; 
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
    }
    else
    {
        if (pos == 1)
        {
            new1->right = head;
            head->left = new1;
            head = new1;
        }
        else
        {
            temp = head;
            prev = head;
            while (temp != NULL && (i < pos - 1 || pos == -99))
            {
                prev = temp;
                temp = temp->right;
                i++;
            }
            if ((temp == NULL && i == pos) || pos == -99)
            {
                prev->right = new1;
                new1->left = prev;
            }
            else if (temp != NULL)
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
    if (head == NULL)
        printf("\nList is Empty");
    else
    {
        temp = head;
        prev = head;
        while (temp != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->right;
        }
        if (temp == NULL)
        {
            printf("\nData Not Found");
            return;
        }
        else if (head == temp)
        {
            head = head->right;
            head->left = NULL;
        }
        else if (temp->right == NULL)
        {
            prev->right = NULL;
            //free(temp);
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
        while (temp != NULL && temp->data != data)
        {
            temp = temp->right;
            i++;
        }
        if (temp == NULL)
            printf("\n%d is not found", data);
        else
            printf("\n%d is found in %d position", temp->data, i);
    }
}
void display()
{
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        temp = head;
        printf("\n ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->right;
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