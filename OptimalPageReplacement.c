#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
} ;
typedef struct Node Node; 
Node* stack = NULL;
Node* pop = NULL;

int top = -1;
int tpop = -1;
int frame = 3;

// Function to search for a given data in the stack linked list
bool search(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to search for a given data in the pop linked list
bool pollSearch(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to clear the pop linked list
void clear() {
    pop = NULL;
    tpop = -1;
}

// Function to find the data to be replaced
int findData() {
    Node* currentStack = stack;
    while (currentStack != NULL) {
        int count = 0;
        Node* currentPop = pop;
        while (currentPop != NULL) {
            if (currentStack->data == currentPop->data) {
                count++;
            }
            currentPop = currentPop->next;
        }
        if (count == 0) {
            return currentStack->data;
        }
        count = 0;
        currentStack = currentStack->next;
    }
    return pop->data;
}

// Function to solve the LRU algorithm for a given index in the array
int solve(int arr[], int index) {
    clear();
    for (int i = index + 1; i < 20; i++) {
        if (tpop == frame - 1) {
            break;
        }
        if (search(stack, arr[i])) {
            if (!pollSearch(pop, arr[i])) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = arr[i];
                newNode->next = pop;
                pop = newNode;
                tpop++;
            }
        }
    }
    int d = findData();
    return d;
}

int main() {
    int a[20] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int hits = 0, faults = 0;

    for (int i = 0; i < 20; i++) {
        if (top < frame - 1) {
            if (!search(stack, a[i])) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = a[i];
                newNode->next = stack;
                stack = newNode;
                top++;
                faults++;
            } else {
                hits++;
            }
        } else {
            if (!search(stack, a[i])) {
                int data = solve(a, i);
                Node* current = stack;
                while (current != NULL) {
                    if (current->data == data) {
                        current->data = a[i];
                        break;
                    }
                    current = current->next;
                }
                faults++;
            } else {
                hits++;
            }
        }
    }
    printf("Hits: %d, Faults: %d\n", hits, faults);
    return 0;
}
