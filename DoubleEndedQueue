#include<stdio.h>
#define SIZE 100

int deque[SIZE];
int front = -1;
int rear = -1;

int isFull() {
	return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
	return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow at front! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } 
    else if (front > 0) {
        front--;
    } 
    else {
        for (int i = rear; i >= front; i--) {
            deque[i + 1] = deque[i];
        }
        rear++;
    }

    deque[front] = value;
    printf("Inserted at front: %d\n", value);
}


void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow at front! Cannot delete\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } 
    
    else {
        front++;
    }
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow at rear! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } 
    
    else if (rear < SIZE - 1) {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted at rear: %d\n", value);
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow at rear! Cannot delete\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } 
    
    else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an operation\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(value);
        } 
        else if (choice == 2) {
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(value);
        } 
        else if (choice == 3) {
            deleteFront();
        } 
        else if (choice == 4) {
            deleteRear();
        } 
        else if (choice == 5) {
            display();
        } 
        else if (choice == 6) {
            printf("Exiting Program \n");
            break;
        } 
        else {
            printf("Invalid choice, Enter valid choice!\n");
        }
    }

    return 0;
}
