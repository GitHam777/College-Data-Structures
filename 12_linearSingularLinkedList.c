#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct slinklist {
    int data;
    struct slinklist *next;
};

typedef struct slinklist node;
node *start = NULL;

int menu(void) {
    int ch;
    printf("1. Create a list\n");
    printf("2. Insert node at beginning\n");
    printf("3. Insert node at end\n");
    printf("4. Insert node at middle\n");
    printf("5. Delete node from beginning\n");
    printf("6. Delete node from end\n");
    printf("7. Delete node from middle\n");
    printf("8. Traverse list (left to right)\n");
    printf("9. Traverse list (right to left)\n");
    printf("10. Count nodes\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node *getnode() {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int countnode(node *ptr) {
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void createlist(int n) {
    int i;
    node *newnode, *temp;
    for (i = 0; i < n; i++) {
        newnode = getnode();
        if (start == NULL) {
            start = newnode;
        }
        else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void traverse(void) {
    node *temp;
    temp = start;
    if (start == NULL) {
        printf("\nEmpty List\n\n");
        return;
    }
    else {
        printf("\nContents of list (Left to Right): ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

void rev_traverse(node *start) {
    node *temp;
    temp = start;
    if (start == NULL) {
        printf("\nEmpty List\n\n");
        return;
    }
    else {
        printf("Contents of list (Right to Left): NULL ");
        rev_traverse(start->next);
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert_at_begin(void) {
    node *newnode;
    printf("\nEnter Data: ");
    newnode = getnode();
    if (start == NULL) {
        start = newnode;
    }
    else {
        newnode->next = start;
        start = newnode;
    }
    printf("\n\n");
}

void insert_at_end(void) {
    node *newnode, *temp;
    printf("\nEnter Data: ");
    newnode = getnode();
    if (start == NULL) {
        start = newnode;
    }
    else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\n");
}

void insert_at_mid(void) {
    node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = getnode();
    printf("Enter position: ");
    scanf("%d ", &pos);
    nodectr = countnode(start);
    if (pos > 1 && pos < nodectr) {
        temp = prev = start;
        while (ctr < pos) {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else {
        printf("Position %d is not a middle position", pos);
    }
}

void delete_at_beg(void) {
    node *temp;
    if (start == NULL) {
        printf("No nodes exist");
        return;
    }
    else {
        temp = start;
        start = temp->next;
        free(temp);
        printf("Node deleted");
    }
}

void delete_at_end(void) {
    node *temp, *prev;
    if (start == NULL) {
        printf("Empty List");
        return;
    }
    else {
        temp = start;
        prev = start;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("Node Deleted");
    }
}

void delete_at_mid(void) {
    int ctr = 1, pos, nodectr;
    node *temp, *prev;
    if (start == NULL) {
        printf("Empty List");
        return;
    }
    else {
        printf("Enter position of node you want to delete: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if (pos > nodectr) {
            printf("Node does not exist");
        }
        if (pos > 1 && pos < nodectr) {
            temp = prev = start;
            while (ctr < pos) {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            free(temp);
            printf("Node deleted");
        }
        else {
            printf("Invalid position");
            getch();
        }
    }
}

int main(void) {
    int ch, n;
    while (1) {
        ch = menu();
        switch (ch) {
        case 1:
            if (start == NULL) {
                printf("\nNumber of nodes you want to create: ");
                scanf("%d", &n);
                printf("Enter data: ");
                createlist(n);
                printf("List created\n\n");
            }
            else {
                printf("\nList is already created\n\n");
            }
            break;

        case 2:
            insert_at_begin();
            break;

        case 3:
            insert_at_end();
            break;

        case 4:
            insert_at_mid();
            break;

        case 5:
            delete_at_beg();
            break;

        case 6:
            delete_at_end();
            break;

        case 7:
            delete_at_mid();
            break;

        case 8:
            traverse();
            break;

        case 9:
            rev_traverse(start);
            break;

        case 10:
            printf("Number of nodes: %d", countnode(start));
            break;

        case 11:
            exit(0);
        }
    }
}