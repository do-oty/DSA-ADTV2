#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell , HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;


void init(VHeap *V){
    V->avail = 0;

    for(int i = 0; i < MAX - 1; i++){
        V->H[i].next = i+1;
    }

    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap *V){

    if(V->avail != -1){
        int idx = V->avail;
        V->avail = V->H[V->avail].next;
        return idx;
    } else {
        return -1;
    }
}


void deallocSpace(VHeap *V, int idx) {
    V->H[idx].next = V->avail;
    V->avail = idx;
}

void insertFirst(int *L , VHeap *V, int data){
    int idx = allocSpace(V);
    if(idx == -1){
        printf("List is full");
    } else{
        V->H[idx].elem = data;
        // makes "newNOde" point to curr head
        V->H[idx].next = *L;
        //update head;
        *L = idx;
    }

}


void insertLast(int *L , VHeap *V, int data){
    int idx = allocSpace(V);
    if(idx == -1){
        printf("List is full");
    } else{
        V->H[idx].elem = data;
        V->H[idx].next = -1;


        if(*L== -1){
            // if empty
            *L= idx;

        } else{
            int trav = *L;

            for(; V->H[trav].next != -1 ; trav = V->H[trav].next);
            V->H[trav].next = idx;
        }
    

    }

}


void insertPos(int *L , VHeap *V, int data, int pos){
    int idx = allocSpace(V);
    if(idx == -1){
        printf("List is full");
    } else{
        V->H[idx].elem = data;
        if(*L== -1){
            // if empty
            *L= idx;
        } else{
            int trav = *L;

            if(pos == 1){
                deallocSpace(V, idx);
                insertFirst(L,V,data);
            } else{
            // stop before pos traverse using adt
            for(int count= 1; V->H[trav].next != -1 && count < pos - 1; trav = V->H[trav].next,  count++);
            V->H[idx].next = V->H[trav].next;
            V->H[trav].next = idx;  
            }

        }
    

    }

}


void insertSorted(int *L, VHeap *V, int data){
    int idx = allocSpace(V);
    if(idx == -1){
        printf("List is full");
    } else{

        V->H[idx].elem = data;

        if(*L == -1){
            *L = idx;
            V->H[idx].next = -1;
            
        } else{
            int prev = -1;
            int trav = *L;
            for(; trav != -1 && V->H[trav].elem < data; prev = trav, trav = V->H[trav].next);
    
            if(prev == -1){
                deallocSpace(V, idx);
                insertFirst(L, V, data);
            } else{
              
                V->H[idx].next = trav;
                V->H[prev].next = idx;
            }
        }

    }
  
}







int main(){

    VHeap V;

    init(&V);
    
    List L = -1;





    return 0;
}