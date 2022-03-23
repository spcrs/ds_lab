#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack1[10][20],stack2[10][20];
int pointer1=-1,pointer2=-1;
int n;
void push(char arr[],int checker);
void display();
void pop();
void push2(char arr[]);
int main()
{
    char arr[20];
    printf("Enter the  no of names");
    scanf("%d",&n);
    if(n>10)
    {
        printf("you cannot push more than 10 name in stack");
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the name to push");
        scanf("%s",arr);
        push(arr,0);
    }
    display();
    return 0;
}
void  display()
{
    printf("\nAscending order ",pointer1);
    for(int i=0;i<=pointer1;i++)
    {
        printf("\n%s",stack1[i]);
    }
    printf("\n");
}
void push(char arr[],int checker)
{
    if(pointer1==-1 || checker)
    {
        //printf("%s",arr);
        pointer1++;
        strcpy(stack1[pointer1],arr);
        return;   
    }
    while(pointer1>=0 && strcmp(stack1[pointer1],arr)>0)
    {
        push2(stack1[pointer1]);
        pop();
    }
    push(arr,1);
    while(pointer2>=0)
    {
       push(stack2[pointer2],1);
       pointer2--;
    }
    return;
}
void pop()
{
    pointer1--;
}
void push2(char arr[])
{
    pointer2++;
    strcpy(stack2[pointer2],arr);
}






/*void push(char arr[])
{
    if(pointer1==0)
    {
        strcpy(stack1[pointer1],arr);
        pointer1++;
        return;
    }
    int temp_stack_pointer=pointer1-1;
    while(temp_stack_pointer>=0 && strcmp(stack1[temp_stack_pointer],arr)>0)
    {
        strcpy(stack1[temp_stack_pointer+1],stack1[temp_stack_pointer]);
        temp_stack_pointer--;
    }   
    strcpy(stack1[temp_stack_pointer+1],arr);
    pointer1++;
}


//max_size=10

*/