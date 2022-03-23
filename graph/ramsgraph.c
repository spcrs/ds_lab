#include <stdio.h>
#include <stdlib.h>
 
struct node {
 
	char data;
	struct node*next;
};
typedef struct node node;
node*temp,*newnode;
 
struct array{
	char data;
	int height;
	struct node*head;
};
typedef struct array array;
array a [100];
int front1 =-1,rear1=-1,front2=-1,rear2=-1;
char queue[15],visited[15];
 
node insert(int size){
	int i,j,tedge;
	for(i=0;i<size;i++){
		printf("Enter the total edges of the %c",a[i].data);
		scanf("%d",&tedge);
		a[i].height = tedge;
		for(j=0;j<tedge;j++){
			newnode = (node*) malloc(sizeof(node));
			newnode->next=NULL;
			printf("Enter the vertex of %c",a[i].data);
			scanf("%s",&newnode->data);
			if(a[i].head==0){
				a[i].head=newnode;
			}
			else{
				temp = a[i].head;
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->next =newnode;
			}
		}
	}
}
 
 
void print(int size){
	int i;
	printf("\nVERTEX\t\t HEIGHT\t\t EDGE\n");
	for(i=0;i<size;i++){
		temp = a[i].head;
		printf("%c\t\t %d\t\t",a[i].data,a[i].height);
		while(temp!=NULL){
			printf("%c->\t\t",temp->data);
			temp=temp->next;	
		}
		printf("\n");
 
	}
}
 
int search(int size,char c){
	int i;
	for( i=0;i<=size;i++){
		if (a[i].data == c){
		//	printf("%d id the returing i",i);
			return i;
		}
 
	}	
 
}
 
 /*
void bfs(int size,int i){ int k,j,h;
	int data,flag1=0,flag2=0;
	while (rear1<size){
		if(front1==-1){
		visited[++front1]=a[i].data;
		rear1++;
		}
		else{
		visited[++rear1]=a[i].data;
		}
		temp=a[i].head;
		for(k=0;k<a[i].height;k++){
			data= temp->data;
			for( j=0;j<rear1+1;j++){
				if(data==visited[j]){
					flag1=1;	
				}
			}
			for(j=0;j<rear2+1;j++){
				if(data==queue[j]){
					flag2=1;	
				}
			}
			if(flag1==0 && flag2==0){
 
				if(front2==-1){
					queue[++front2]=data;
					rear2++;
				}
				else{
					queue[++rear2]=data;
				}
			}
 
			temp = temp->next;
 
		}
		if(front2<size){
			i=search(size);
		}	front2++;
 
 
	}
	printf("The visited node are :");
	for(h =0;h<size;h++){
		printf("%c\t",visited[h]);
	}
}
*/

void BFS(int size,int i)
{ int j;
// queue and visited are two array	
int data,flag1=0,flag2=0,flag=1;
queue[++rear1]=a[i].data;
	visited[++rear2]=queue[front1++];
 while( rear2<size){
 	   	
 	//queue[++rear1]=a[i].data;
 	temp=a[i].head;
 	while (temp!=NULL){
 		for(j=0;j<=rear1;j++)
 			{
			 if(queue[j]==temp->data)
			 flag=0;
		   }
		if (flag) queue[++rear1]=temp->data;
		flag=1;
	   printf("%d id the returing i\n",rear1);
		
		temp=temp->next;
	 }
	visited[++rear2]=queue[front1++];
	
	
   	i=search(size,queue[front1]);
   	//printf("%d-------%c----\n",i,queue[front1]);
 }
 for(j=0;j<=rear2;j++)
 printf("%c ---  ",visited[j]);
	
}
 
 
 
 
int main(){ int i;
//char a;
int totalvertices;
printf("Enter the total vertices : ");
scanf("%d",&totalvertices);
for( i=0; i<totalvertices;i++){
	printf("enter the vertex: ");
	scanf("%s",&a[i].data);
	a[i].height =0;
}
//a=a[0].data;
insert(totalvertices);
print(totalvertices);
BFS(totalvertices,0);
 
}