#include <math.h>
#include <stdio.h>
int pow(int n,int r)
{
    int ans=1;
    for(int i=0;i<r;i++)
        ans*=n;
    return ans;
}
int index(int val,int r)
{
            long square = val * val;
            long square1 = square;
            int len = 0;
            while (square1 > 0)
            {
                square1 = square1/10;
                len++;
            }
            int ans = 0;
            for (int i = 0; i < len / 2 - r / 2; i++)
                square = square/10;
            // for (int i = 0; i < r; i++)
            // {
            //     ans = ans + square % 10 * pow((double)10, (double)i);
            //     square /= 10;
            // }
            ans=square%pow(10,r);
            //ans=square%(int)(pow((double)10,(double)r));
            printf("%d\n", ans);
        return ans;
}
void main()
{
    int size = 10, r = 1,ans=0,len;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = -1;
    while (1)
    {
        int val, option;
        printf("Enter your choide\n1.insert\n2.delete\n3.3.search\n4.diplay\n5.exit");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            printf("Enter a value to insert");
            scanf("%d", &val);
            //int val=12; //27
            ans=index(val,r);
            if (arr[ans] != -1)
                printf("\n collission occurs");
            else
                arr[ans] = val;
            break;
        }
        case 2:
        {
            printf("Enter a value to delete");
            scanf("%d", &val);
            long square = val*val ; //val * val;
            long square1 = square;
            len = 0;
            while (square1 > 0)
            {
                square1 /= 10;
                len++;
            }
            ans = 0;
            for (int i = 0; i < len / 2 - r / 2; i++)
                square /= 10;
            for (int i = 0; i < r; i++)
            {
                ans = ans + square % 10 * pow((double)10, (double)i);
                square /= 10;
            }
            printf("%d\n", ans);

            arr[ans] = -1;
            break;
        }
        case 3:
        { 
            printf("Enter a value to search");
            scanf("%d", &val);
            long square = val*val; //val * val;
            long square1 = square;
            len = 0;
            while (square1 > 0)
            {
                square1 /= 10;
                len++;
            }
            ans = 0;
            for (int i = 0; i < len / 2 - r / 2; i++)
                square /= 10;
            for (int i = 0; i < r; i++)
            {
                ans = ans + square % 10 * pow((double)10, (double)i);
                square /= 10;
            }
            printf("%d\n", ans);
            if (arr[ans] == val)
                printf("\nvalue found");
            else
                printf("\nvalue not found");
            break;
        }
        case 4:
            for (int i = 0; i < size; i++)
                printf("\n %3d %3d",i, arr[i]);
            break;
        default:
            return;
        }
    }
}



