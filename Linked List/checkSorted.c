#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct Node *next;
}Node;

Node *head = NULL, *tail = NULL;

void insert(){
    int data = 0;
    printf("\nEnter your data: ");
    scanf("%i", &data);
    
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(!head) {
        head = new_node;
        tail = head;   
    }
    else {
        tail->next = new_node;
        tail = new_node;
    } 
}

int is_sort(){
    if(!head) return -1;

    Node *node = head->next;
    int temp = head->data;
    while(node){
        if(!(temp <= node->data)) return -1;
        node = node->next;
    }

    return 1;
}

void display(){
    if(!head) puts("\nNothing to display\n");
    else{
        Node *node = head;
        while(node) {
            printf("\n%i", node->data);
            node = node->next;
        }
        puts("");
    }
}

int main() {
    while(1){
        int option = 0,result;
        puts("\n1. Insert\n2. Is_Sorted?\n3. Display\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%i", &option);
        if(option == 4) break;    
        switch (option){
            case 1:
                insert();
                break;
            case 2:
                result = is_sort();
                result == -1 ? puts("\nIt's not sorted\n") : puts("\nYep, it's sorted\n");
                break;
            case 3:
                display();
                break;
            default:
                break;
        }
    }
    return 0;
}