#include <stdio.h>
#include <stdlib.h>
int pointer = -1, max_size = 5, start = 0;
void display(int arr[])
{
	if (pointer == -1)
	{
		printf("No elements");
		return;
	}
	printf("The elements inside the array are ");
	int i = start;
	do
	{
		printf("%d\t", arr[i]);
		i = (i + 1) % max_size;
	} while ((pointer + 1) % max_size != i);
}
void push(int arr[], int val)
{
	if (pointer != -1 && ((pointer + 1) % max_size) == start)
	{
		printf("overflow error");
		return;
	}
	pointer = (pointer + 1) % max_size;
	arr[pointer] = val;
}
void pop()
{
	if (pointer == -1)
	{
		printf("underflow error");
		return;
	}
	if (start == pointer)
	{
		start = 0;
		pointer = -1;
	}
	else
	{
		start = (start + 1) % max_size;
	}
}
void peek(int arr[])
{
	printf("The element at the top is %d", arr[pointer]);
}
void main()
{

	int n, arr[5], val;
	while (1)
	{
		printf("\n\nEnter your choice\n");
		printf("1.Push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.peek\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("Enter the value to push");
			scanf("%d", &val);
			push(arr, val);
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
