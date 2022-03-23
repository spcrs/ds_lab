#include<stdio.h>
#include<math.h>

int power(int times)
{
    int ans=1;
    for(int i=0;i<times;i++)
        ans=ans*10;
    return ans;
}

int index(int val,int r)
{
    int sum=0,temp=0,power_value=power(r);
    while(val>0)
    {
        temp=val%power_value;
        sum=sum+temp;
        //printf("%d  ",temp);
        val=val/power_value;
    }
    printf("%d  ",sum);
    return sum%power(r);
}
void main()
{
    int size=100,r=2,ind;
    int arr[size];
    for(int i=0;i<size;i++)
        arr[i]=-1;
    
    int len=0;
    // //int val=386342,sum=0,temp=0;
    // int power_value=power(r);
    // while(val>0)
    // {
    //     temp=val%power_value;
    //     sum=sum+temp;
    //     printf("%d  ",temp);
    //     val=val/power_value;
    // }
    // printf("%d  ",sum);

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
            ind=index(val,r);
            if(arr[ind]!=-1)
                printf("\n collission occurs");
            else
                arr[ind]=val;
            break;
        case 2:
            printf("Enter a value to delete");
            scanf("%d",&val);
            ind=index(val,r);
            arr[ind]=-1;
            break;
        case 3:
            printf("Enter a value to search");
            scanf("%d",&val);
            ind=index(val,r);
            if(arr[ind]==val)
                printf("\nvalue found");
            else
                printf("\nvalue not found");
            break;
        case 4:
            for(int i=0;i<size;i++)
                if(arr[i]!=-1)
                printf("%d - %d ",arr[i],i);
            break;
        default:
            return;
        }
    }
}
