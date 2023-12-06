#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int stack[MAX];
int top = 0;

int menu(void) {
    int choice;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void push(void) {
    int data;
    if(top == MAX) {
        printf("Stack Overflow\n");
        return;
    }
    else {
        printf("Enter data: ");
        scanf("%d", &data);
        stack[top] = data;
        top++;
        printf("Data pushed into Stack\n");
    }
}

void pop(void) {
    if(top == 0) {
        printf("Stack Underflow\n");
        return;
    }
    else {
        --top;
        printf("Popped element: %d\n", stack[top]);
    }
}

void display(void) {
    if(top == 0) {
        printf("Stack empty\n");
    }
    else {
        printf("Elements in stack: ");
        for(int i = 0; i < top; i++) {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int choice;
    do {
        choice = menu();
        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
    while(1);
    return 0;
}