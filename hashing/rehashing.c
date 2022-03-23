#include<math.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
    int size=5;
    int *arr=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
        arr[i]=-1;
    while(1)
    {
        int val,option;
        printf("Enter your choide\n1.insert\n2.delete\n3.3.search\n4.diplay\n5.exit");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("Enter a value to insert");
            scanf("%d",&val);
        
            if(arr[val%size]!=-1)
            {
                while(arr[val%size]!=-1)
                {
                    int *ptr=(int*)malloc(size*sizeof(int));
                    for(int i=0;i<size;i++)
                        ptr[i]=arr[i];
                    size=size*2;
                    arr=(int*)malloc(size*sizeof(int));
                    for(int i=0;i<size;i++)
                        arr[i]=-1;
                    for(int i=0;i<size/2;i++)
                        if(ptr[i]!=-1)
                            arr[ptr[i]%size]=ptr[i];
                }
                arr[val%size]=val;                
                printf("\n collission occurs");
            }
            else
                arr[val%size]=val;
            break;
        case 2:
            printf("Enter a value to delete");
            scanf("%d",&val);
            arr[val%size]=-1;
            break;
        case 3:
            printf("Enter a value to search");
            scanf("%d",&val);
            if(arr[val%size]==val)
                printf("\nvalue found");
            else
                printf("\nvalue not found");
            break;
        case 4:
            for(int i=0;i<size;i++)
                printf("%d, ",arr[i]);
            break;
        default:
            return;
        }
    }
}