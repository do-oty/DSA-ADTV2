// front starts at index 4 . direction is counter clockwise


#include <stdio.h>
#include <stdlib.h>


#define MAX 5


typedef struct {

    char name[MAX];
    int age;

} Person;


typedef struct {
    Person h[MAX];
    int front;
    int rear;
}Queue;
Queue* init(){
    Queue *Q = malloc(sizeof(Queue));
    Q->front = 4;
    Q->rear = 5;

    return Q;

}
 

int isEmpty(Queue G){
    return G.front == 4 && G.rear == 5 ? 1 : 0;
}

int isFull(Queue G){
    //counterclockwise chceck
    return ((G.rear - 1 + MAX) % MAX) == G.front ? 1 : 0;
    //clockwise
    //return ((G.rear + 1) % MAX ) == G.front ? 1 : 0;
 }

void enq(Queue *G, Person H){
    
    if(isFull(*G)){
        printf("List is full");
    } else{
        G->rear = (G->rear - 1 + MAX ) % MAX;
        G->h[G->rear] = H;
    }
}


void deq(Queue *G){
    
    if(isEmpty(*G)){
        printf("List is empty");
    } else if (G->front == G->rear){
        G->front = 4;
        G->rear  = 5;
    } else{
        G->front = (G->front - 1 + MAX ) % MAX;
    }
}

Person front(Queue G){
    return G.h[G.front];
}


int main (){
    Queue *Q = init();

    Person p1 = {"Alice", 20};
    Person p2 = {"Bob", 25};
    Person p3 = {"Carol", 30};

    enq(Q, p1);
    enq(Q, p2);
    enq(Q, p3);

    Person f = front(*Q);
    printf("Front age: %d\n", f.age);

    deq(Q);
    f = front(*Q);
    printf("Front age after one deq: %d\n", f.age);

    deq(Q);
    deq(Q);
    deq(Q);

    free(Q);

    return 0;
}
