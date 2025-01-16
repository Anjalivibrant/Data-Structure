//ex:7
//1.
//code: Queue implementaion using arrays
#include <stdio.h>
#include<stdlib.h>
#define MAX 50

void insert();
void delete();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;

int main() {
    int choice;
    while (1) {
        printf("1. Insert element to queue \n");
        printf("2. Delete element from queue \n");
        printf("3. Display all elements of queue \n");
        printf("4. Quit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}

void insert() {
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else {
        if (front == -1)
            front = 0;
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow \n");
        return;
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display() {
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}



//2.
//code:
// Circular Queue implementation in C

#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// check if the queue is full
int isFull() {
  if ((front == (rear + 1) % SIZE) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  // fails because front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  // fails to enqueue because front == rear + 1
  enQueue(8);

  return 0;
}


//3.
//code:menu - driven queue code
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;  // Initialize front if it's the first element
        rear++;
        queue[rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset the queue after last element is dequeued
        }
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

//4.
//code:Double ended queue
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the deque

int deque[MAX];
int front = -1;
int rear = -1;

// Function to check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front of the deque
void insertFront(int key) {
    if (isFull()) {
        printf("Overflow: Unable to insert element at the front. Deque is full.\n");
        return;
    }

    if (front == -1) {  // If deque is initially empty
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;  // wrap around
    } else {
        front = front - 1;
    }

    deque[front] = key;
    printf("Inserted %d at the front.\n", key);
}

// Function to insert an element at the rear of the deque
void insertRear(int key) {
    if (isFull()) {
        printf("Overflow: Unable to insert element at the rear. Deque is full.\n");
        return;
    }

    if (rear == -1) {  // If deque is initially empty
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;  // wrap around
    } else {
        rear = rear + 1;
    }

    deque[rear] = key;
    printf("Inserted %d at the rear.\n", key);
}

// Function to delete an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Underflow: Unable to delete element from the front. Deque is empty.\n");
        return;
    }

    int removed = deque[front];

    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;  // wrap around
    } else {
        front = front + 1;
    }

    printf("Deleted %d from the front.\n", removed);
}

// Function to delete an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow: Unable to delete element from the rear. Deque is empty.\n");
        return;
    }

    int removed = deque[rear];

    if (front == rear) {  // Deque has only one element
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;  // wrap around
    } else {
        rear = rear - 1;
    }

    printf("Deleted %d from the rear.\n", removed);
}

// Function to display the deque
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements are: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to test the operations
int main() {
    insertRear(5);
    displayDeque();

    insertFront(15);
    displayDeque();
    
    insertRear(25);
    displayDeque();

    deleteFront();
    displayDeque();

    deleteRear();
    displayDeque();


    return 0;
}
