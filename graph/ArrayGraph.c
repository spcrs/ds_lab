#include<stdio.h>
int arr[26][26],size=5;
int times=0;
int mapValue(char c)
{
    return c-'a';
}
void printAllVertex()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%5d ",arr[i][j]);
        }
        printf("\n");
    }
}
int canWeTraverse(int vi[],int i,int j,int counter)
{
    printf("\n%d  -  %d",i,j);
    if(i==j)
        return 1;
    for(int k=0;k<size;k++)
    {
        if(arr[i][k]!=11111)
        {
            if(vi[k]==1)
                continue;
            vi[k]=1;
            if(canWeTraverse(vi,k,j,counter)==1)
            {
                times+=1;
                printf("\nvisited\n");
                for(int k=0;k<=4;k++)
                    printf("%d ",vi[k]);
                printf("\n");
                //return 1;
            }
            vi[k]=-1;
        }
    }
    return 0;
}
int not_visited(int waiting[],int k,int end_waiting)
{
    for(int i=0;i<end_waiting;i++)
    {
        if(waiting[i]==k)
            return 0;
    }
    return 1;
}
void BFS()
{
    int vi[10],waiting[10],curr=0;
    int start_waiting=0,end_waiting=0;
    waiting[end_waiting++]=curr;
    while(start_waiting<end_waiting)
    {
        int val=waiting[start_waiting];
        for(int k=0;k<size;k++)
        {
            if(arr[val][k]==1)
                if(not_visited(waiting,k,end_waiting))
                    waiting[end_waiting++]=k;
        }
        start_waiting++;
    }

    printf("\n BFS is \n");
    for(int i=0;i<end_waiting;i++)
        printf("%d -> ",waiting[i]);
}
void insertEdge(int i,int j,int weight)
{
    arr[i][j]=arr[j][i]=weight;
    printf("dhfj");

    return;
}
void main()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            arr[i][j]=11111;
        }
    }
    char val,val1;
    int n,weight,vi[26];
    for(int i=0;i<26;i++)
        vi[i]=-1;
    while(1)
    {
        printf("\nEnter your choice\n1.insert new vertex\n2.insert new edge\n3.BFS\n4.display\n5.DFS\n6.can we traverse");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("\nEnter no of vertex");
            scanf(" %d",&size);
            // insertVertex(val);
            break;
        case 2:
            printf("\nEnter vertex and edge ");
            scanf(" %c",&val);
            scanf(" %c",&val1);
            // printf("\nEnter weight ");
            // scanf("%d",&weight);
            insertEdge(mapValue(val),mapValue(val1),1);
            break;
        case 3:
            printf("Enter your suggested root ");
            scanf(" %c",&val);
            BFS();
            break;
        case 4:
            printAllVertex();
            break;
        case 5:
            printf("Enter your suggested root ");
            scanf(" %c",&val);
            // DFS(vertexRoot,val);
            break;
        case 6:
            times=0;
            for(int i=0;i<26;i++)
                vi[i]=-1;
            printf("\nEnter vertex and edge ");
            scanf(" %c",&val);
            scanf(" %c",&val1);
            if(canWeTraverse(vi,mapValue(val),mapValue(val1),1))
                printf("YES we can");
            else    
                printf("NOPE");
            printf("\n times = %d",times);
        default:
            break;
        }
    }
}