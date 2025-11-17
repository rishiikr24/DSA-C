#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

struct Node* CreatNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void insertAtHead(int val, struct LinkedList* ll) {
    struct Node* newnode = CreatNode(val);
    if (ll->head == NULL) {
        ll->head = newnode;
        ll->tail = newnode;
    } else {
        newnode->next = ll->head;
        ll->head = newnode;
    }
}

void deleteAtHead(struct LinkedList* ll) {
    if (ll->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = ll->head;
    if (ll->head == ll->tail) {  
        ll->head = NULL;
        ll->tail = NULL;
    } else {
        ll->head = ll->head->next;
    }
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct LinkedList ll;
    ll.head = NULL;
    ll.tail = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertAtHead(val, &ll);
    }
    display(ll.head);
    deleteAtHead(&ll);
    display(ll.head);
    return 0;
}