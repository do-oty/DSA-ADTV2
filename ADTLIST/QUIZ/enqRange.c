// QUESTION 1 
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    char songName[MAX];
    int songYear;
    int duration;

}Song;


typedef struct node{
    Song S;
    struct node *next; 
}Node;


typedef struct {

    Node *front;
    Node *rear;

}Queue, Songlist;



Songlist* init(){
    Songlist *Q = malloc(sizeof(Songlist));
    Q->front = NULL;
    Q->rear = NULL;

    return Q;
}

void enqRange(Songlist *Q, Song S){
//  my implemntation in quiz.. (makes newnode every call regardless of year (BAD))
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->S = S;

    // empty
    if(Q->front == NULL && Q->rear == NULL 
        && S.songYear >= 1950 &&  S.songYear <= 1980){
        Q->front = newNode;
        Q->rear = newNode;
    } else{
    // not empty
        if(S.songYear >= 1950 &&  S.songYear <= 1980){
            Q->rear->next = newNode;
            Q->rear = newNode;
        }
    }

}

void deq(Songlist *Q){
// empty
   if(Q->front == NULL && Q->rear == NULL ){
    printf("Empty List");
    } else{
// not empty
    Node *temp = Q->front;    
    Q->front = Q->front->next;
    // this checks if only one node in the lsit;
    if(Q->front == NULL){
        Q->rear = NULL;
    }
    free(temp);
    }
}



int main (){
    Songlist *Q = init();

    Song s1 = {"Song A", 1940, 180};
    Song s2 = {"Song B", 1960, 200};
    Song s3 = {"Song C", 1975, 220};
    Song s4 = {"Song D", 1990, 210};

    enqRange(Q, s1);
    enqRange(Q, s2);
    enqRange(Q, s3);
    enqRange(Q, s4);

    while (Q->front != NULL) {
        Song current = Q->front->S;
        printf("%s %d %d\n", current.songName, current.songYear, current.duration);
        deq(Q);
    }

    return 0;
}