
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;

}Node;

typedef struct {
    Node *head;
    int count;
}List;


List* init(){
    List *L = malloc(sizeof(List));
    L->head = NULL;
    L->count = 0;
    return L;
}

void empty(List *L){
    
    for(Node *trav = L->head; trav != NULL ; ){
        Node *temp = trav;
        trav = trav->next;
        free(temp);
    }
    L->head = NULL;
    L->count = 0;
}


void insertFirst(List *L, int data){
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    
    if(L->count == 0){
        L->head = newNode;
    } else{
        Node *temp = L->head;
        L->head = newNode;
        L->head->next = temp;
    }
    L->count++;

}


void insertLast(List *L, int data){
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    
    if(L->count == 0){
        L->head = newNode;
    } else{
        Node *trav = L->head;
        for(; trav->next != NULL ; trav= trav->next);
        trav->next= newNode;
    }
    L->count++;

}


void insertPos(List *L, int data, int pos){
    

    if(pos <= L->count){
        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
    
        
        int count = 0;
      
    
        if( pos == 0){
            insertFirst(L, data);
        } else if(pos == L->count){
            insertLast(L, data);
        } else{
            Node *trav = L->head;
            for(; trav != NULL  &&  count < pos - 1; trav= trav->next , count++);
            newNode->next = trav->next;
            trav->next= newNode;
            L->count++;
        }

    

    }
   
}

void deleteLast(List *L){
    if(L->count == 0){
        printf("List is empty");
    } else{
        if (L->count == 1) {
            free(L->head);
            L->head = NULL;
        } else {
            Node *trav = L->head;
            for(; trav->next->next != NULL ; trav= trav->next);
            free(trav->next);
            trav->next = NULL;
        }
        L->count--;
    }
}

void deleteFirst(List *L){
    if(L->count == 0){
        printf("List is empty");
    } else{
        Node *temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
    L->count--;
}

int retrieve(List *L, int pos){
    if(pos > L->count){
        printf("Invalid position");
        return -1;
    } else{
        Node *trav = L->head;
        for(int i = 0; i < pos; i++){
            trav = trav->next;
        }
        return trav->data;
    }
}

int locate(List *L, int data){
    Node *trav = L->head;
    for(int i = 0; trav != NULL; trav= trav->next, i++){
        if(trav->data == data){
            return i;
        }
    }
    return -1;
}


void display(List *L){
    Node *trav = L->head;
    for(; trav != NULL ; trav= trav->next){
        printf("%d ", trav->data);
    }
    printf("\n");
}   




int main(){
    List *L = init();
    int idx, value;

    insertFirst(L, 10);
    insertLast(L, 30);
    insertPos(L, 20, 1);
    display(L);

    deleteFirst(L);
    display(L);

    insertLast(L, 40);
    insertFirst(L, 5);
    display(L);

    value = retrieve(L, 1);
    printf("%d\n", value);

    idx = locate(L, 40);
    printf("%d\n", idx);
    idx = locate(L, 100);
    printf("%d\n", idx);

    return 0;
}


