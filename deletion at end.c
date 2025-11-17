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

void insert(int val, struct Node** head, struct Node** tail) {
    struct Node* newnode = CreatNode(val);
    if (*head == NULL) {
        *head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

void deleteend(struct LinkedList* ll) {
    if (ll->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (ll->head == ll->tail) {
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
        return;
    }
    struct Node* temp = ll->head;
    while (temp->next != ll->tail) {
        temp = temp->next;
    }
    free(ll->tail);
    ll->tail = temp;
    ll->tail->next = NULL;
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
        insert(val, &ll.head, &ll.tail);
    }
    display(ll.head);
    deleteend(&ll);
    display(ll.head);
    return 0;
}
