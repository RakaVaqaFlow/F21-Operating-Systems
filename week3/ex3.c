#include <stdio.h>
#include <malloc.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node{
    int* val;
    struct node* next;
} node;

void print_list(node *head){
    node* current = head;
    while(current->next!=NULL){
        current = current->next;
        printf("%d\n", *(current->val));
    }
}

void smart_print_list(node *head){
    node* current = head;
    while(current->next!=NULL){
        current = current->next;
        printf("value%d\n adress of value:%d\n adress:%d\n next adress:%d\n\n", *(current->val), current->val, current, current->next);
    }
}
void insert_node(node *newnode, node *prevnode){
    if(prevnode->next==NULL){
        prevnode->next = newnode;
    }else{
        newnode->next=prevnode->next;
        prevnode->next=newnode;
    }
}

void delete_node(node *head, node *delnode){
    node* currentNode = head;
    while(currentNode->next!=delnode){
        currentNode=currentNode->next;
    }
    currentNode->next=delnode->next;
}

node* get_node(node *head, int i){
    node* currentNode = head;
    while(i--){
        currentNode=currentNode->next;
    }
    return currentNode;
}

node* create_node(int newVal){
    node* newNode=(node*)malloc(sizeof(node));
    int* Val = malloc(sizeof(int));
    *Val = newVal;
    newNode->val=Val;
    newNode->next=NULL;
    return newNode;
}

int main(){
    int a=0;
    node* head = (node*)malloc(sizeof(node));
    head->next=NULL;
    node* node1 = create_node(1);
    node* node2 = create_node(2);
    node* node3 = create_node(3);
    insert_node(node1, head);
    insert_node(node2, head);
    insert_node(node3, head);
    printf("Initial structure\n");
    print_list(head);
    node* newNode = create_node(555);
    printf("Insert node after node2:\n");
    insert_node(newNode, get_node(head, 2));
    print_list(head);
    printf("Delete node 2:\n");
    delete_node(head, get_node(head, 2));
    print_list(head);
}