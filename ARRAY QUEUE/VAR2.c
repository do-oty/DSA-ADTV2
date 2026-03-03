
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// sac space method / no count 

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* init(){
    Queue *Q = malloc(sizeof(Queue));
    Q->front = 1;
    Q->rear = 0;

    return Q;
}

bool isFull(Queue *Q){
     return Q->front == (Q->rear + 2 ) % MAX ? true : false;
}

bool isEmpty(Queue *Q){
    return Q->front == (Q->rear + 1 ) % MAX ? true : false;
}

void enq(Queue *Q , int data){

    if(isFull(Q)){
        printf("Queue is full");
    } else{
        Q->rear = (Q->rear + 1) % MAX;
        Q->items[Q->rear] = data;
    }

}

int deq(Queue *Q ){

    if(isEmpty(Q)){
        printf("Queue is Empty");
        return -1;
    } else{
        int data;
         data = Q->items[Q->front];
         Q->front = (Q->front + 1) % MAX;
         return data;
    }
    
}




int front(Queue *Q){
    
    if(isEmpty(Q)){
        printf("Queue is empty");
        return -1;
    } else{
        return Q->items[Q->front];
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