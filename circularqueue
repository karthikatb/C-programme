#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } 
    
    else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }

    int item = queue[front];

    if (front == rear) {
        front = rear = -1;
    } 
    
    else {
        front = (front + 1) % SIZE;
    }

    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value, dequeuedValue;

    while (1) {
        printf("\nChoose an operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        } 
        else if (choice == 2) {
            dequeuedValue = dequeue();
            if (dequeuedValue != -1) {
                printf("Dequeued: %d\n", dequeuedValue);
            }
        } 
        else if (choice == 3) {
            display();
        } 
        else if (choice == 4) {
            printf("Exiting Program\n");
            break;
        } 
        else {
            printf("Invalid choice, Enter valid choice.\n");
        }
    }

    return 0;
}
