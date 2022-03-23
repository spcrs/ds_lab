#include <stdio.h>
#define MAX 6

int arr[MAX];
int front1 = -1, rear1 = -1, 
    front2 = MAX, rear2 = MAX;

int get_num(){
    int num;
    printf("\nEnter a number: ");
    scanf("%i", &num);
    return num;
}

void push_f(){
    if(rear1+1 >= rear2 || (rear1 == -1 && rear2 == 0)) 
        puts("\nQueue Full");
    else{
        arr[++rear1] = get_num();
        front1 += front1 == -1 && rear2 != 0; 
    } 
}

void push_s(){
    if(rear1+1 >= rear2  || (rear2 == MAX && rear1 == MAX-1)) 
        puts("\nQueue Full");
    else{
        arr[--rear2] = get_num();
        front2 -= front2 == MAX && rear1 != MAX-1; 
    }
}

void pop_f(){
    if(front1 == -1 || rear2 == 0) puts("\nNothing to Pop");
    else if (rear1 < ++front1){
        front1 = -1;
        rear1 = -1;
    }
}

void pop_s(){
    if(front1 == MAX-1 || rear2 == MAX) puts("\nNothing to Pop");
    else if (rear2 > --front2){
        front2 = MAX;
        rear2 = MAX;
    }
}

void display(){
    int i = 0;

    puts("\nQueue A: ");
    if(front1 != -1) 
        for(i = front1; i <= rear1; i++) 
            printf("%i ", arr[i]);

    puts("\nQueue B: ");
    if(front2 != MAX)
        for(i = front2; i >= rear2; i--)
            printf("%i ", arr[i]);

    puts("");
}


int main(){
    while(1) {
        puts("\n0. Exit\n1. Push in 'A' queue\n2. Pop in 'A' queue\n3. Push in 'B' queue\n4. Pop in 'B' queue\n5. Display");
        printf("\nEnter an option: ");
        int option;
        scanf("%i", &option);
        switch (option)
        {
        case 1:
            push_f();
            break;
        case 2:
            pop_f();
            break;
        case 3:
            push_s();
            break;
        case 4:
            pop_s();
            break;
        case 5:
            display();
            break;
        default:
            break;
        }
    }
    return 0;
}