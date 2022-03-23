#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
}Node;

Node *head = NULL, 
     *tail = NULL;
int length = 0;

int getANumber(){
    int num;
    scanf("%d", &num);
    return num;
}

void getOption(int *option) {
    puts("\n------------------------------------");
    puts(" 0. Exit");
    puts(" 1. Push");
    puts(" 2. Pop");
    puts(" 3. Get");
    puts(" 4. Set");
    puts(" 5. Find");
    puts(" 6. Unshift");
    puts(" 7. Shift");
    puts(" 8. Insert");
    puts(" 9. Remove");
    puts("10. Reverse");
    puts("11. Display");
    puts("------------------------------------");
    printf("\nEnter an option: ");
    scanf("%d", option);
}

void push(int val){
    Node *node = malloc(sizeof(Node*));
    node->data = val;
    node->next = NULL;
    
    if(!length) {
        head = node;
    }else{
        tail->next = (struct Node*)node;
        tail = (Node*)tail->next;
    }
    tail = (Node*)node;
    ++length;
}

void pop(){
    if(!length) {
        puts("\nNothing to Pop");
    }else {
        Node *node = head;
        Node *prev = node;

        while(node->next){
            prev = node;
            node = (Node *)node->next;
        }

        prev->next = NULL;
        tail = prev;
        --length;

        if(!length){
            head = tail = NULL;
        }
    }
}

void display(){
    if(!length) puts("\nNothing to show");
    else {
        Node *node = head;
        int i = 1;
        puts("");
        while(node->next) {
            printf("%i. %i\n", i, node->data);
            node = (Node*)node->next;
            i++;
        }
        printf("%i. %i\n", i, node->data);

    }
}

Node* get(int index){
    Node *node = NULL;
    if(index <= 0 || index > length){
        puts("\nInvalid index");
    }else{
        int i = 1;
        node = head;

        while(index > i){
            node = (Node*)node->next;
            ++i;
        }

    }

    return node;
}

void set(){
    printf("\nEnter the index : ");
    int index = getANumber();
    
    Node *node = get(index);
    
    printf("\nEnter the number : ");
    int number = getANumber();

    if(node){
        node->data = number;
    }
}

int find(int number){
    int i = 0, result = 0;
    if(head->data == number){
        return 1;
    }

    Node *node = head;
    while(node){
        if(node->data == number) {
            result = i;
            break;
        }
        node = (Node *)node->next;
        ++i;
    }
    return result;
}

void unshift(int num){
    Node *node = malloc(sizeof(Node));
    node->data = num;
    node->next = (Node*)head;

    head = node;
    if(!length) tail = node;
    ++length;
}

void shift(){
    if(!length) {
        puts("\nNothing to remove");
    }else{
        head = head->next;
        --length;
    }
}

int insert(){

    printf("\nEnter the index: ");
    int index = getANumber();
    
    if(index <= 0 || index > length + 1){
        printf("\nInvalid Index\n");
        return 0;
    }

    printf("\nEnter the number to be inserted : ");
    int number = getANumber();
    
    if(index == 1) {
        unshift(number);
        return 1;
    }

    if(index == length + 1){
        push(number);
        return 1;
    }

    Node *prev_node = get(index - 1);
    Node *next_node = prev_node->next;
    Node *new_node = malloc(sizeof(Node));
    new_node->data = number;
    new_node->next = next_node;
    prev_node->next = new_node;

    ++length;
    return 1;
}

Node* delete(){
    if(!length) {
        puts("\nNothing to remove.");
        return NULL;
    }

    printf("\nEnter the index to be removed : ");
    int index = getANumber();

    if(index <= 0 || index > length) {
        puts("\nInvalid index");
        return NULL;
    }

    Node *temp = get(index);
    if(index == 1){
        shift();
    }else if(index == length) {
        pop();
    }else{
        Node *prev_node = get(index - 1);
        prev_node->next = temp->next;
    }

    temp->next = NULL;

    return temp;
}

void reverse(){
    if(!length || length == 1) {
        puts("\nInsert atleast two numbers in the list to reverse");
    }else{
        Node *current = head;
        head = tail;
        tail = head;

        Node *prev_node = NULL;
        Node *next_node = NULL;

        for(int i = 0; i < length; ++i) {
            next_node = current->next;
            current->next = prev_node;
            prev_node = current;
            current = next_node;
        }       
    }
}



int main()
{
    while(1){
        int option;
        getOption(&option);

        if(!option) break;

        switch(option){
            case 1:
                printf("\nEnter a number : ");
                int num = getANumber();
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(!length) 
                    puts("\nInsert an element in the list to do operation");
                else{
                    printf("\nEnter the index : ");
                    int index = getANumber();
                    Node* node = get(index);
                    printf("\nIndex %d data is %d.\n", index, node->data);
                }
                break;
            case 4:
                if(!length) 
                    puts("\nInsert an element in the list to do operation");
                else{
                    display();
                    set();
                    display();
                }
                break;
            case 5:
                if(!length) 
                    puts("\nInsert an element in the list to do some operations");
                else{
                    printf("\nEnter a number to find : ");
                    int number = getANumber();
                    int index = find(number);
                    if(!index) {
                        puts("Number not found");
                    }else{
                        printf("\nNumber is present in the list in the index %i\n", index);
                    }
                }
                break;
            case 6:
                printf("\nEnter a number : ");
                int number = getANumber();
                unshift(number);
                break;
            case 7:
                shift();
                break;
            case 8:
                insert();
                break;
            case 9:
                delete();
                break;
            case 10:
                reverse();
                break;
            case 11:
                display();
                break;
            default:
                puts("\nInvalid Option");
                break;
        }
    }
    return 0;
}
