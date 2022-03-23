#include <stdio.h>

#define MAX 4

int arr[MAX];
int rear = -1;
int start = -1;
void insert_front()
{
    
    if ((rear + 1) % MAX == start)
        printf("queue full");
    else
    {
        int number = 0;
        printf("\nEnter a number: ");
        scanf("%i", &number);
        if (start == -1)
        {
            start=0;
            rear=0;
        }
        if (start-1 == -1)
            start = MAX - 1;
        else
            start--;
        arr[start] = number;
    }
}

void insert_rear()
{
    if ((rear + 1) % MAX == start)
        printf("queue full");
    else
    {
        int number = 0;
        printf("\nEnter a number: ");
        scanf("%i", &number);
        if (rear == -1)
        {
            arr[++rear] = number;
            start=0;
        }
        else
        {
            rear=(rear+1)%MAX;
            arr[rear] = number;
        }
    }
}

void delete_front()
{
    if(start==-1)
        printf("\nqueue is empty");
    else
    {
        printf("\n%d is popped",arr[start]);
        if(start==rear)
        {
            start=-1;
            rear=-1;
        }
        else if(start+1==MAX)
            start=0;
        else
            start++;
    }
}

void delete_rear()
{
    if(start==-1)
        printf("\nqueue is empty");
    else
    {
        printf("\n%d is popped",arr[rear]);
        if(start==rear)
        {
            start=-1;
            rear=-1;
        }
        else if(rear==0)
        {
            rear=MAX-1;
        }
        else
            rear--;
    }
}

void display()
{
    if (rear == -1)
        puts("\nNothing to show\n");
    else
    {
        printf("\nThe values in queue are ");
        int s=start,r=rear;
        do
        {
            printf("%d  ",arr[s]);
            s=(s+1)%MAX;
        }while(s!=(r+1)%MAX);
    }
}

void input_queue()
{
    while (1)
    {
        int option;
        puts("\n1. Insert Rear\n2. Delete front\n3. Delete Rear\n4. Display\n.5 Exit\n\n");
        printf("Enter your option: ");
        scanf("%i", &option);
        switch (option)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            delete_rear();
            break;
        case 4:
            display();
            break;
        default:
            puts("\nWrong option\n");
            return;
        }
    }
}
void output_queue()
{
    while (1)
    {
        int option;
        puts("\n1. Insert Front\n2. Insert Rear\n3. Delete front\n4. Display\n5. Exit\n\n");
        printf("Enter your option: ");
        scanf("%i", &option);
        switch (option)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            display();
            break;
        default:
            puts("\nWrong option\n");
            return;
        }
    }
}
int main()
{
    while (1)
    {
        int option = 0, op = 0;
        printf("1.Input Deque\n2.Output Deque\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            input_queue();
            break;
        case 2:
            output_queue();
            break;
        default:
            return;
        }
    }
}
