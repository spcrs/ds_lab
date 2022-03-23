#include<stdio.h>
#include<stdlib.h>
int pointer=-1,max_size=10,start=0;
void display(int arr[])
{
	printf("The elements inside the array are ");
	for(int i=start;i<=pointer;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void push(int arr[],int val)
{
	if(pointer+1==max_size)
	{
		printf("overflow error");
		return;
	}
	pointer++;
	arr[pointer]=val;
}
void pop()
{
	if(pointer==-1 || start>pointer)
	{
		printf("underflow error");
		return;
	}
    if(start==pointer)
    {
        start=0;
        pointer=-1;
    }
    else{
        start++;
    }
}
void convertToStack(int arr[])
{
    if(pointer==-1)
    {
        printf("\nqueue is empty");
        return;
    }
    int stack[max_size],top=-1;
    for(int i=start;i<=pointer;i++)
    {
        stack[++top]=arr[i];
        //printf("djf");
    }
    printf("The elements inside stack are");
    for(int i=top;i>=0;i--)
        printf("%d  ",stack[i]);

}
void main()
{

	int n,arr[10],val;
	while(1)
	{
		printf("\n\nEnter your choice\n");
		printf("1.Push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.create stack and display\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	
				printf("Enter the value to push");
				scanf("%d",&val);
				push(arr,val);
				break;
			case 2:	
				pop();
				printf("The value is popped");
				break;
			case 3:
				display(arr);
				break;
			case 4:
				convertToStack(arr);
				break;
			default:
				exit(0);
		}
	}
	return;			
	
}
