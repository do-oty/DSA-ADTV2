
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// count method 
typedef struct {
    int items[MAX];
    int count;

} List;

typedef struct {
    List L;
    int front;
    int rear;
} Queue;

Queue* init(){
    Queue *Q = malloc(sizeof(Queue));
    Q->L.count = 0;
    Q->front = 1;
    Q->rear = 0;

    return Q;
}

bool isFull(Queue *Q){
     return Q->L.count == MAX ? true : false;
}

bool isEmpty(Queue *Q){
    return Q->L.count == 0 ? true : false;
}

void enq(Queue *Q , int data){

    if(isFull(Q)){
        printf("Queue is full");
    } else{
        Q->rear = (Q->rear + 1) % MAX;
        Q->L.items[Q->rear] = data;
        Q->L.count++;
    }

}

int deq(Queue *Q ){

    if(isEmpty(Q)){
        printf("Queue is Empty");
        return -1;
    } else{
        int data;

        if(Q->L.count == 1){
            data = Q->L.items[Q->front];
            Q->rear = 0;
            Q->front = 1;
        }else{
            data = Q->L.items[Q->front];
            Q->front = (Q->front + 1) % MAX;
        }

        Q->L.count--;
        return data;
    }

}


int front(Queue *Q){
    
    if(isEmpty(Q)){
        printf("Queue is empty");
        return -1;
    } else{
        return Q->L.items[Q->front];
    }

}

void display(Queue *Q){

    Queue *tempQ = init();

    if(isEmpty(Q)){
        printf("Queue is Empty");
    } else{
        while(!isEmpty(Q)){
           int data = deq(Q);
           printf("%d\n", data);
           enq(tempQ, data);
        }

        while(!isEmpty(tempQ)){
            int data = deq(tempQ);
            enq(Q, data);
         }
    }
    free(tempQ);

}



int main (){
    Queue *Q = init();

    enq(Q, 10);
    enq(Q, 30);
    enq(Q, 20);

    printf("Queue contents after enq:\n");
    display(Q);

    printf("Front element: %d\n", front(Q));

    printf("Dequeued: %d\n", deq(Q));
    printf("Dequeued: %d\n", deq(Q));

    printf("Queue contents after deq:\n");
    display(Q);

    printf("Dequeued: %d\n", deq(Q));
    printf("Dequeued from empty (should show error): %d\n", deq(Q));

    free(Q);

    return 0;
}