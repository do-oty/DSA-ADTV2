
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

// VARIATION 3 DYNAMIC ARRAY ACCESSED BY VALUE

typedef struct{

    int *elem;
    int count;
    int max;
}List;

List resize(List L){
    
    L.max = L.max * 2;

    int *temp = realloc(L.elem,  L.max * sizeof(int));

    L.elem = temp;

    return L;
}

List initialize(List L){
    L.elem = malloc (sizeof(int) * LENGTH);
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count ){
        printf("Invalid position");
        return L;
    }
    if(L.count == L.max){
        printf("List is full doubling size of array.\n");
        L = resize(L);
    } 
// NO MORE SKIP
        for(int i = L.count ;  i > position; i--){
            L.elem[i] = L.elem[i - 1];
        }

        L.elem[position] = data;
        L.count++;

    

    return L;

}


List deletePos(List L, int position){

    if(position > L.count ){
        printf("Invalid position");
    }
    else{ 
        
        for(int i = position ;  i < L.count - 1; i++){
            L.elem[i] = L.elem[i + 1];
        }


        L.count--;

    }

    return L;

}

List insertSorted(List L, int data){
    int position, i;

    if (L.count == L.max) {
        printf("List is full doubling size of array. \n");
        L = resize(L);
    } 
// NO MORE SKIP
        for (i = 0; i < L.count && L.elem[i] < data; i++);  
        position = i;

        for (i = L.count; i > position; i--) {
            L.elem[i] = L.elem[i - 1];
        }

        L.elem[position] = data;
        L.count++;
    

    return L;
}



int locate(List L, int data){
    int i;
    for(i = 0; i < L.count && L.elem[i] != data; i++); 
    return (i == L.count) ? -1 : i;

}

int retrieve(List L, int position ){
    
    return (position <= L.count) ? L.elem[position] : -1; 
}



void display(List L){
    int i;
    printf("[");
    for (i = 0; i < L.count; i++) {
        printf("%d", L.elem[i]);
        if (i < L.count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    List L;
    int idx;

    L = initialize(L);
    L = insertPos(L, 10, 0);
    L = insertPos(L, 30, 1);
    L = insertPos(L, 20, 1);
    display(L);

    L = deletePos(L, 1);
    display(L);

    L = insertSorted(L, 25);
    L = insertSorted(L, 5);
    L = insertSorted(L, 40);
    display(L);

    idx = locate(L, 25);
    printf("%d\n", idx);
    idx = locate(L, 100);
    printf("%d\n", idx);
    idx = retrieve(L, 0);
    printf("%d\n", idx);

    return 0;
}
