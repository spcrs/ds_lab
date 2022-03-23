#include<stdio.h>
#include<stdlib.h>
struct edges
{
    char c;
    struct edges* next;
};
struct vertex
{
    char c;
    struct edges* links;
    struct vertex* next;
};
struct LL 
{
    char c;
    struct LL *next;
};
struct vertex* insertVertex(struct vertex* vertexRoot,char val)
{
    struct vertex* temp1=vertexRoot;
    struct vertex* temp=(struct vertex*)malloc(sizeof(struct vertex));
    temp->c=val;
    temp->links=NULL;
    temp->next=NULL;
    if(vertexRoot==NULL)
    {
        vertexRoot=temp;
        return vertexRoot;
    }
    while(vertexRoot->next!=NULL)
        vertexRoot=vertexRoot->next;
    vertexRoot->next=temp;
    return temp1;
}
void printAllVertex(struct vertex* vertexRoot)
{
    while(vertexRoot!=NULL)
    {
        printf("%c  ",vertexRoot->c);
        struct edges* temp=vertexRoot->links;
        while(temp!=NULL)
        {
            printf("%c-->",temp->c);
            temp=temp->next;
        }
        printf("\n");
        vertexRoot=vertexRoot->next;
    }
}
void insertEdge(struct vertex* temp,char c)
{
    struct edges* curr=temp->links;
    struct edges* temp1=(struct edges*)malloc(sizeof(struct edges));
    temp1->c=c;
    temp1->next=NULL;
    if(curr==NULL)
    {
        temp->links=temp1;
        return;
    }
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp1;
}
struct vertex* corresponingVertex(struct vertex* vertexRoot,char val)
{
    while(vertexRoot!=NULL)
    {
        if(vertexRoot->c==val)
            return vertexRoot;
        vertexRoot=vertexRoot->next;
    }
    printf("vertex not found  ");
    return NULL;
}
int canWeTraverse(struct vertex* vertexRoot,struct LL *vi ,char start,char end)
{
    struct edges* temp=corresponingVertex(vertexRoot,start)->links;
    while(temp!=NULL)
    {
        int flag=0;
        printf("\ncurr %c \n",start);
        struct LL* viTemp=vi;
        while(viTemp!=NULL)
        {
            if(viTemp->c==temp->c)
            {
                printf("\n%c",viTemp->c);
                flag=1;
                break;
            }
            viTemp=viTemp->next;
        }
        if(flag)
        {
            temp=temp->next;
            continue;
        }
        struct LL* temp1=(struct LL*)malloc(sizeof(struct LL));
        temp1->c=temp->c;
        temp1->next=NULL;
        viTemp=vi;
        while(viTemp->next!=NULL)
            viTemp=viTemp->next;
        vi->next=temp1;
        if(temp->c==end || canWeTraverse(vertexRoot,vi,temp->c,end))
        {
            printf("%c->",temp->c);
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void insertLinkedList(struct LL *list,char c)
{
    while(list->next!=NULL)
        list=list->next;
    list->next=(struct LL*)malloc(sizeof(struct LL));
    list=list->next;
    list->c=c;
    list->next=NULL;
    return;
}
int isVisited(char c,struct LL* vi,struct LL* wait)
{
    struct LL* temp=vi->next;
    while(temp!=NULL)
    {
        if(temp->c==c)
        {
            return 1;
        }
        temp=temp->next;
    }   
    temp=wait;
    while(temp!=NULL)
    {
        if(temp->c==c)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void BFS(struct vertex* vertexRoot,char root)
{
    struct LL* vi=(struct LL*)malloc(sizeof(struct LL));
    vi->c='N';
    vi->next=NULL;
    struct LL* wait=(struct LL*)malloc(sizeof(struct LL));
    wait->c=root;
    wait->next=NULL;
    while(wait!=NULL)
    {
        char poped=wait->c;
        struct edges* temp=corresponingVertex(vertexRoot,poped)->links;
        while(temp!=NULL)
        {
            if(isVisited(temp->c,vi,wait)==0)
            {
                insertLinkedList(wait,temp->c);
            }
            temp=temp->next;
        }
        insertLinkedList(vi,poped);
        wait=wait->next;
    }
    printf("\n");
    vi=vi->next;
    while(vi!=NULL)
    {
        printf("%c--> ",vi->c);
        vi=vi->next;
    }
}
char pop_for_DFS(struct LL* wait)
{
    while(wait->next!=NULL)
        wait=wait->next;
    return wait->c;
}
void DFS(struct vertex* vertexRoot,char root)
{
    struct LL* vi=(struct LL*)malloc(sizeof(struct LL));
    vi->c='N';
    vi->next=NULL;
    struct LL* wait=(struct LL*)malloc(sizeof(struct LL));
    wait->c=root;
    wait->next=NULL;
    while(wait!=NULL)
    {
        char poped=pop_for_DFS(wait);
        struct edges* temp=corresponingVertex(vertexRoot,poped)->links;
        while(temp!=NULL)
        {
            if(isVisited(temp->c,vi,wait)==0)
            {
                insertLinkedList(wait,temp->c);
            }
            temp=temp->next;
        }
        insertLinkedList(vi,poped);
        struct LL* traverse=wait->next;
        struct LL* prev=wait;
        if(wait->c==poped)
            wait=wait->next;
        else
        {
            while(traverse!=NULL)
            {
                if(traverse->c==poped)
                {
                    prev->next=traverse->next;
                    break;
                }
                prev=traverse;
                traverse=traverse->next;
            }
        }
    }
    printf("\n");
    vi=vi->next;
    while(vi!=NULL)
    {
        printf("%c--> ",vi->c);
        vi=vi->next;
    }
}

void main()
{
    int n,count=0,ch;
    char val,val1;
    struct vertex* vertexRoot=NULL;
    while(1)
    {
        printf("\nEnter your choice\n1.insert new vertex\n2.insert new edge\n3.BFS\n4.display\n5.eixt");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter a vertex character");
            scanf(" %c",&val);
            vertexRoot=insertVertex(vertexRoot,val);
            break;
        case 2:
            printf("Enter vertex and edge");
            scanf(" %c",&val);
            scanf(" %c",&val1);
            struct vertex* temp=corresponingVertex(vertexRoot,val);
            insertEdge(temp,val1);
            break;
        case 3:
            printf("Enter your suggested root ");
            scanf(" %c",&val);
            BFS(vertexRoot,val);
            break;
        case 4:
            printAllVertex(vertexRoot);
            break;
        case 5:
            printf("Enter your suggested root ");
            scanf(" %c",&val);
            DFS(vertexRoot,val);
            break;
        default:
            break;
        }
    }
}
// void main()
// {
//     int n,count=0;
//     char val,val1;
//     printf("Enter no of vertex");
//     scanf("%d",&n);
//     struct vertex* vertexRoot=NULL;
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter a vertex character");
//         scanf(" %c",&val);
//         vertexRoot=insertVertex(vertexRoot,val);
//         // printf("%d",vertexRoot);
//         printAllVertex(vertexRoot);
//     }    
//     struct vertex* temp=vertexRoot;
//     while(temp!=NULL)
//     {
//         printf("Enter no of edges for vertex %c",temp->c);
//         scanf("%d",&count);
//         for(int i=0;i<count;i++)
//         {
//             printf("Enter a edge ");
//             scanf(" %c",&val);
//             insertEdge(temp,val);
//         }
//         temp=temp->next;
//     }
//     printAllVertex(vertexRoot);
//     printf("Enter your suggested root ");
//     scanf(" %c",&val);
//     BFS(vertexRoot,val);
// }


 // while(1)
    // {
    // char start,end;
    // printf("\nEnter a start and end vertex to search for path ");
    // scanf(" %c",&start);
    // scanf(" %c",&end);
    // struct visited* vi=(struct visited*)malloc(sizeof(struct visited));
    // vi->c=start;
    // vi->next=NULL;
    // if(canWeTraverse(vertexRoot,vi,start,end))
    //     printf("yes we can traverse");
    // else
    //     printf("we can not  traverse");
    // }