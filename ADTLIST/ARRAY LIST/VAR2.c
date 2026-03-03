#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// VARIATION 2 STATIC ARRAY ACCESSED BY PTR

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    if(position > L->count ){
        printf("Invalid position");
    }
    if(L->count == MAX){
        printf("List is full");
    }
    else{ 
        
        for(int i = L->count ;  i > position; i--){
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[position] = data;
        L->count++;

    }

    

}

void deletePos(EPtr L, int position) {

    if(position > L->count ){
        printf("Invalid position");
    }
    else{ 
        
        for(int i = position ;  i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }


        L->count--;

    }

   



}

void insertSorted(EPtr L, int data) {

    int position, i;

    if (L->count == MAX) {
        printf("List is full");
    } else {
        for (i = 0; i < L->count && L->elem[i] < data; i++);  
        position = i;

        for (i = L->count; i > position; i--) {
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[position] = data;
        L->count++;
    }


}

int locate(EPtr L, int data) {
    int i;
    for(i = 0; i < L->count && L->elem[i] != data; i++); 
    return (i == L->count) ? -1 : i;
}

int retrieve(EPtr L, int position ){
    
    return (position <= L->count) ? L->elem[position] : -1; 
}



void display(EPtr L) {
    int i;
    printf("[");
    for (i = 0; i < L->count; i++) {
        printf("%d", L->elem[i]);
        if (i < L->count - 1) {
            printf(", ");
        }
    }
    printf("]\n");

}

void makeNULL(EPtr L) {
//STATIC ARRAY  NO USE FOR FREE  JUST RESET   // 

    L->count = 0;
    for (int i = 0; i < MAX; i++) {
        L->elem[i] = 0;

    }
}

int main()
{
    Etype L;
    EPtr list = &L;
    int idx;

    initialize(list);
    insertPos(list, 10, 0);
    insertPos(list, 30, 1);
    insertPos(list, 20, 1);
    display(list);

    deletePos(list, 1);
    display(list);

    insertSorted(list, 25);
    insertSorted(list, 5);
    insertSorted(list, 40);
    display(list);

    idx = locate(list, 25);
    printf("%d\n", idx);
    idx = locate(list, 100);
    printf("%d\n", idx);
    idx = retrieve(list, 0);
    printf("%d\n", idx);

    makeNULL(list);

    display(list);

    return 0;
}


