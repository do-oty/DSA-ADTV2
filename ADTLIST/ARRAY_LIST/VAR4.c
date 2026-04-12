
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

// VARIATION 4 DYNAMIC ARRAY ACCESSED BY POINTER

typedef struct{
    int *elem;
    int count;
    int max;
}List;

void resize(List *L){
    
    L->max = L->max * 2;

    int *temp = realloc(L->elem,  L->max * sizeof(int));

    L->elem = temp;
}

void initialize(List *L){
    L->elem = malloc (sizeof(int) * LENGTH);
    L->max = LENGTH;
    L->count = 0;

}

void insertPos(List *L, int data, int position){
    if(position > L->count ){
        printf("Invalid position");
       
    }
    if(L->count == L->max){
        printf("List is full doubling size of array.\n");
        resize(L);
    } 
// NO MORE SKIP
        for(int i = L->count ;  i > position; i--){
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[position] = data;
        L->count++;

    

  

}


void deletePos(List *L, int position){

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

void  insertSorted(List *L, int data){
    int position, i;

    if (L->count == L->max) {
        printf("List is full doubling size of array. \n");
        resize(L);
    } 
// NO MORE SKIP
        for (i = 0; i < L->count && L->elem[i] < data; i++);  
        position = i;

        for (i = L->count; i > position; i--) {
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[position] = data;
        L->count++;
    


}



int locate(List *L, int data){
    int i;
    for(i = 0; i < L->count && L->elem[i] != data; i++); 
    return (i == L->count) ? -1 : i;

}

int retrieve(List *L, int position ){
    
    return (position <= L->count) ? L->elem[position] : -1; 
}



void display(List *L){
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

void makeNULL(List *L){
    free(L->elem);
}
int main()
{
    List L;
    int idx;

    initialize(&L);
    insertPos(&L, 10, 0);
    insertPos(&L, 30, 1);
    insertPos(&L, 20, 1);
    display(&L);

    deletePos(&L, 1);
    display(&L);

    insertSorted(&L, 25);
    insertSorted(&L, 5);
    insertSorted(&L, 40);
    display(&L);

    idx = locate(&L, 25);
    printf("%d\n", idx);
    idx = locate(&L, 100);
    printf("%d\n", idx);
    idx = retrieve(&L, 0);
    printf("%d\n", idx);

    makeNULL(&L);

    return 0;
}
