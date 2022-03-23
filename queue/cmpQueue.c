#include <stdio.h>
#define MAX 5
int arr1[MAX], front1 = 0, rear1 = -1;
int arr2[MAX], front2 = 0, rear2 = -1;

void display()
{
    printf("\nThe elements inside the queue 1 are \n");
    for (int i = front1; i <= rear1; i++)
    {
        printf("%d\t", arr1[i]);
    }
    printf("\nThe elements inside the queue 2 are\n");
    for (int i = front2; i <= rear2; i++)
    {
        printf("%d\t", arr2[i]);
    }
}
void push1()
{
    if (rear1 + 1 == MAX)
    {
        printf("overflow error");
        return;
    }
    rear1++;
    int val;
    printf("Enter a value to push");
    scanf("%d", &val);
    arr1[rear1] = val;
}
void pop1()
{
    if (rear1 == -1 || front1 > rear1)
    {
        printf("underflow error");
        return;
    }
    if (front1 == rear1)
    {
        front1 = 0;
        rear1 = -1;
    }
    else
    {
        front1++;
    }
}
void push2()
{
    if (rear2 + 1 == MAX)
    {
        printf("overflow error");
        return;
    }
    rear2++;
    int val;
    printf("Enter a value to push");
    scanf("%d", &val);
    arr2[rear2] = val;
}
void pop2()
{
    if (rear2 == -1 || front2 > rear2)
    {
        printf("underflow error");
        return;
    }
    if (front2 == rear2)
    {
        front2 = 0;
        rear2 = -1;
    }
    else
    {
        front2++;
    }
}
void compare()
{
    if (rear1 - front1 != rear2 - front2)
    {
        printf("\nNot equal");
    }
    else
    {
        int f1 = front1, f2 = front2;
        while (f2 <= rear2)
        {
            if (arr1[f1] != arr2[f2])
            {
                printf("\nNot equal");
                return;
            }
            f1++;
            f2++;
        }
        printf("\nBoth are equal");
    }
}
int main()
{
    while (1)
    {
        puts("\n0. Exit\n1. Push in 'A' queue\n2. Pop in 'A' queue\n3. Push in 'B' queue\n4. Pop in 'B' queue\n5. Display\n6.compare two queues");
        printf("\nEnter an option: ");
        int option;
        scanf("%i", &option);
        switch (option)
        {
        case 1:
            push1();
            break;
        case 2:
            pop1();
            break;
        case 3:
            push2();
            break;
        case 4:
            pop2();

            break;
        case 5:
            display();
            break;
        case 6:
            compare();
        default:
            return;
        }
    }
    return 0;
}