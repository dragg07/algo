#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself in a circular list
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    if (position == 1) {
        insertAtBeginning(data);
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL || temp->next == head) {
                printf("Invalid position. Position exceeds the length of the list.\n");
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void count() {
    int count = 0;
    struct Node* temp = head;
    if (head != NULL) {
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    printf("Number of nodes in the list: %d\n", count);
}

void deleteAtBeginning() {
        if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head, *prev = NULL;
    if (head->next == head) {
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

void deleteAtPosition(int position) {
    if (position == 1) {
        deleteAtBeginning();
    } else {
        struct Node* temp = head, *prev = NULL;
        for (int i = 1; i < position; i++) {
            if (temp == NULL || temp->next == head) {
                printf("Invalid position.\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
    }
}

int main() {
    int choice, data, position;
    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at position\n");
        printf("4. Display\n");
        printf("5. Count number of nodes\n");
        printf("6. Delete at the beginning\n");
        printf("7. Delete at the end\n");
        printf("8. Delete at position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                display();
                break;
            case 5:
                count();
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}
