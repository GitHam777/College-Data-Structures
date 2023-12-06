#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int queue[MAX];
int front = 0, rear = 0;
int count = 0;

int menu(void) {
    int choice;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void push(void) {
    if(count >= MAX) {
        printf("Queue Overflow\n");
        return;
    }
    else {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        queue[rear] = data;
        rear = (rear + 1) % MAX;
        count++;
        printf("Data pushed into queue\n");
    }
}

void pop(void) {
    if(count == 0) {
        printf("Queue Underflow\n");
        return;
    }
    else {
        printf("Popped element is: %d\n", queue[front]);
        front = (front + 1) % MAX;
        count--;
    }
}

void display(void) {
    int i, j;
    if(count == 0) {
        printf("Queue Empty\n");
    }
    else {
        printf("Elements in queue: ");
        j = count;
        for(int i = front; j != 0; j--) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
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