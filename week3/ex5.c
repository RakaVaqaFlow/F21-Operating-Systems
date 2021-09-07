/* реализация double linked list
    Vagif Khalilov v.khalilov@innopolis.university
    tg: @vaqaaa
    данную реализацию можно использовать для различных типов данных, поскольку элемент ячейки листа - указатель на память 
*/
#include <stdio.h>
#include <malloc.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    void* val;
    struct node* next;
    struct node* prev;
} node;

typedef struct double_linked_list{
    node* head;
    node* tail;
}dl_list;

dl_list* create_list(){
    dl_list* newList= (dl_list*)malloc(sizeof(dl_list));
    
    node* newHead = (node*)malloc(sizeof(node));
    newHead->prev=NULL;
    newHead->val=NULL;
    
    node* newTail = (node*)malloc(sizeof(node));
    newTail->prev=newHead;
    newTail->next=NULL;
    newTail->val=NULL;
    newHead->next=newTail;

    newList->head=newHead;
    newList->tail=newTail;
    return newList;
}

node* create_node(void* val){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->val=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

node* find_node(dl_list* list, int it ){
    node* current=list->head->next;
    while(it--){
        if(current->next!=NULL)current = current->next;
        else return NULL;
    }
    return current;
}

void push(dl_list* list, void* new_element){
    node* newNode = create_node(new_element);
    list->tail->prev->next = newNode;
    newNode->prev=list->tail->prev;
    list->tail->prev = newNode;
    newNode->next=list->tail;
}

void add_after(dl_list* list, void* new_element, int it){
    node* current = find_node(list, it);
    if(current==NULL) return;
    node* newNode = create_node(new_element);
    current->next->prev=newNode;
    newNode->next=current->next;
    current->next=newNode;
    newNode->prev=current;
}

void add_before(dl_list* list, void* new_element, int it){
    node* current = find_node(list, it);
    if(current==NULL) return;
    node* newNode = create_node(new_element);
    current->prev->next=newNode;
    newNode->prev=current->prev;
    current->prev=newNode;
    newNode->next=current;
}

void delete_node(dl_list* list, int it){
    node* current = find_node(list, it);
    if(current==NULL) return;
    current->next->prev=current->prev;
    current->prev->next=current->next;
    free(current);
}

//данная функция работает только для целочисленных листов 
void print_int_list(dl_list* list){
    node* current = list->head->next;
    while(current!=list->tail){
        printf("%d\n", *((int*)(current->val)));
        current = current->next;
    }
}

int main(){
    dl_list* list = create_list();
    int a[] = {654, 54, -1000, 7, 6, 0, -88}; // поскольку элемент ячейки листа представляет собой указатель 
                                              // то для работы с непосредственными значениями мы должны их где-то явно хранить

                                              // можно обойтись и без дополнительного выделения памяти путем изменения в структуре node 
                                              // типа элемента val с void* на необходимый нам, однако, в таком случае необходимо внести изменения и в другие функции
                                              // но при этом мы потерям возможность использовать данную реализацию для других типов
    for(int i=0; i<4; i++){
        push(list, &a[i]);
    }

    printf("Initial structure of integer double linked list\n");
    print_int_list(list);
    printf("Insert node after node 2:\n");
    add_after(list, &a[4], 2);
    print_int_list(list);
    printf("Insert node before node 2:\n");
    add_before(list, &a[5], 2);
    print_int_list(list);
    printf("Delete node 2:\n");
    delete_node(list, 2);
    print_int_list(list);
}
