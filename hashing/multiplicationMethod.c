#include<stdio.h>
void main()
{
    int size=10;
    int arr[size];
    for(int i=0;i<size;i++)
        arr[i]=-1;
    
    float A=0.618033;
    printf("%d ",(int)(1000*((12345*A)-(int)(12345*A))));
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

            if(arr[(int)(size*((val*A)-(int)(val*A)))]!=-1)
                printf("\n collission occurs");
            else
                arr[(int)(size*((val*A)-(int)(val*A)))]=val;
            break;
        case 2:
            printf("Enter a value to delete");
            scanf("%d",&val);
            arr[(int)(size*((val*A)-(int)(val*A)))]=-1;
            break;
        case 3:
            printf("Enter a value to search");
            scanf("%d",&val);
            if(arr[(int)(size*((val*A)-(int)(val*A)))]==val)
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