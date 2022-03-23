#include<stdio.h>
int l[100],n=-1;
int parent(int i)
{
    return (i-1)/2;
}
int left_child(int i)
{
    return (i*2)+1;
}
int right_child(int i)
{
    return (i*2)+2;
}
int search(int val)
{
    for(int i=0;i<=n;i++)
        if(l[i]==val)
            return i;
    return -1;
}
void insert(int val)
{
    l[++n]=val;
    int curr=n;
    while(curr>0 && l[parent(curr)]>l[curr])
    {
        int temp=l[parent(curr)];
        l[parent(curr)]=l[curr];
        l[curr]=temp;

        curr=parent(curr);
    }
}
void delete(int val)
{
    int endVal=l[n];
    int present=search(val);
    if(present==-1)
    {
        printf("Value not found");
        return;
    }
    if(present==n)
    {
        n--;
        return;
    }
    n--;
    l[present]=endVal;
    while(right_child(present)<=n && (l[left_child(present)]<endVal || l[right_child(present)]<endVal))
    {
        if(l[left_child(present)]<l[right_child(present)])
        {
            int temp=l[left_child(present)];
            l[left_child(present)]=l[present];
            l[present]=temp;

            present=left_child(present);
        }
        else
        {
            int temp=l[right_child(present)];
            l[right_child(present)]=l[present];
            l[present]=temp;

            present=right_child(present);
        }
    }
    if(left_child(present)<=n && l[left_child(present)]<endVal)
    {
        int temp=l[left_child(present)];
        l[left_child(present)]=l[present];
        l[present]=temp;
    }
}
void display(int ind,int space)
{
    if(ind>n)
        return;
    space+=2;
    display(right_child(ind),space);
    for(int i=0;i<=space;i++)
        printf("   ");
    printf("%d\n",l[ind]);
    display(left_child(ind),space);
}
void main()
{
    int opt,val;
    while(1)
    {
    printf("Enter your choice \n1.insertion \n2.deletion\n3.search\4.display\n5.exit");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
            printf("Enter a value to insert  ");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            printf("Enter a value to delete  ");
            scanf("%d",&val);
            delete(val);
            break;
        case 3:
            printf("Enter a value to search  ");
            scanf("%d",&val);
            search(val);
            break;
        case 4:
            display(0,0);
            break;

    }
    }
}