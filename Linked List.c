#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct LinkedList{
   struct Node* head;
    struct Node* tail;
};
struct Node* CreateNode(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n-> data = val;
    n-> next = NULL;
    return n;
}
void insert(int val,struct Node** head, struct Node** tail){
    struct Node* newnode = CreateNode( val);
    if(*head == NULL){
        *head = newnode; //dereferencing
        *tail = newnode; //dereferencing
    }
    else{
        (*tail)->next = newnode;
        *tail = newnode;
    }
}
    void insertAtHead(struct Node** head, int val){
       struct Node* newnode = CreateNode(val);//step 1 
       newnode->next = *head;//step 2 
       *head = newnode; // step 3 
    }
    void insertAtTail(struct Node** head,int val){
        struct Node* newnode = CreateNode(val);// step1  
        struct Node* temp = *head;//step2 finding tail node
        while(temp-> next != NULL){
            temp = temp -> next;
        }
        temp->next = newnode;
    }
    void insertAtPosition(struct Node** head, int pos, int val){
        struct Node* newnode = CreateNode(val);//step1
        //step2
        int count = 0;
        struct Node* temp = *head;
        while(count!= pos-1){
            temp = temp-> next;
            count++;
        }
        //step3
        newnode->next = temp->next;
        temp -> next = newnode;//step4
    }
void display(struct Node* head){
    if(head == NULL){
        printf("List is empty");
    }
    else{
        struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp-> next;
    }
    }
}
int main()
{
    struct LinkedList ll; //defining a variable(Initialing a variable)
    ll.head = NULL;
    ll.tail = NULL;
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i ++){
        int val;
        scanf("%d",&val);
        insert(val,&ll.head,&ll.tail);
    }
    int val ;
    scanf("%d",&val);
    insertAtHead(&ll.head,val);
    display(ll.head);
    return 0;
}