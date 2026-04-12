#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;

}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;


Queue* init(){
    Queue *Q = malloc(sizeof(Queue));
    Q->front  = NULL;
    Q->rear  = NULL;
    return Q;
}

bool isEmpty(Queue *Q){
    return Q->rear == NULL && Q->front == NULL ? true : false;
}

void enq(Queue *Q , int data) {

    Node *newNode = malloc(sizeof(Node));
    newNode->next= NULL;
    newNode->data = data;

    if(isEmpty(Q)){
        Q->front = newNode;
        Q->rear = newNode;
    } else{
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

}

int deq(Queue *Q){

    if(isEmpty(Q)){
       printf("List is empty");
        return -1;
    } else{
        int data = Q->front->data; 
        Node *temp = Q->front;
        Q->front = Q->front->next;

        //check if only one node
        if(Q->front == NULL){
            Q->rear = NULL;
        }    
   
       free(temp);
       return data;

    }


}

int front(Queue *Q){
    return (isEmpty(Q)) ? -1 : Q->front->data; 
}

void display(Queue *Q){

    if(isEmpty(Q)){
        printf("List is empty");
    } else{
        Queue *tempQ = init();

        while(!isEmpty(Q)){
            int data = deq(Q);
            printf("%d\n", data);
            enq(tempQ, data);
        }

        while(!isEmpty(tempQ)){
            int data = deq(tempQ);
            enq(Q, data);
        }

        free(tempQ);
    }
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