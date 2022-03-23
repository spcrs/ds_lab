#include<stdio.h>
#include<stdlib.h>
int pointer=-1,max_size=10;
void display(int arr[]);
void push(int arr[],int val);
void pop();
void peek(int arr[]);

void main()
{

	int n,arr[10],val;
	while(1)
	{
		printf("\n\nEnter your choice\n");
		printf("1.Push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.peek\n");
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
				peek(arr);
				break;
			default:
				exit(0);
		}
	}
	return;			
	
}
void display(int arr[])
{
	printf("The elements inside the array are ");
	for(int i=0;i<=pointer;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void push(int arr[],int val)
{
	if(pointer==max_size-1)
	{
		printf("overflow error");
		return;
	}
	pointer++;
	arr[pointer]=val;
}
void pop()
{
	if(pointer==-1)
	{
		printf("underflow error");
		return;
	}
	pointer--;
}
void peek(int arr[])
{
	if(pointer==-1)
	{
		printf("underflow error");
		return;
	}
	printf("The element at the top is %d",arr[pointer]);
}