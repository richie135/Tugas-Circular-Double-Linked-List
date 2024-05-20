#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("Address: %p, Data: %d\n", (void*)temp, temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void sortList(Node** head) {
    if (*head == NULL) return;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != *head) {
            if (ptr1->data > ptr1->next->data) {
                // Swap nodes, not just data
                Node* temp = ptr1->next;
                ptr1->next = temp->next;
                temp->next->prev = ptr1;
                temp->prev = ptr1->prev;
                ptr1->prev->next = temp;
                ptr1->prev = temp;
                temp->next = ptr1;

                if (*head == ptr1) {
                    *head = temp;
                }

                swapped = 1;
            } else {
                ptr1 = ptr1->next;
            }
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    int N, data;
    Node* head = NULL;

    // Input jumlah data
    scanf("%d", &N);

    // Input data dan masukkan ke dalam list
    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    // Tampilkan list sebelum pengurutan
    printf("List sebelum pengurutan:\n");
    printList(head);

    // Urutkan list
    sortList(&head);

    // Tampilkan list setelah pengurutan
    printf("List setelah pengurutan:\n");
    printList(head);

    return 0;
}
