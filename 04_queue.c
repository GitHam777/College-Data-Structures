#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int queue[MAX];
int front = 0, rear = 0;

int menu(void) {
    int choice;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void push(void) {
    if(rear == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    else {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        queue[rear] = data;
        rear++;
        printf("Data pushed into queue\n");
    }
}

void pop(void) {
    if(front == rear) {
        printf("Queue Underflow\n");
        return;
    }
    else {
        printf("Popped element is: %d\n", queue[front]);
        front++;
    }
}

void display(void) {
    if(front == rear) {
        printf("Queue Empty\n");
    }
    else {
        printf("Elements in queue: ");
        for(int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
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