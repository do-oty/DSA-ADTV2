
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

//VAR 1 stack starts at -1 so when incrementing it goes 0 until n / MAX

typedef struct{
    int elem[MAX];
    int top;
}Stack;

Stack* init(){
    Stack *S = malloc(sizeof(Stack));
    S->top = -1;
    return S;
}

bool isFull(Stack* S){
    return S->top == MAX - 1 ? true : false;
}

bool isEmpty(Stack* S){
    return S->top == -1 ? true : false;
}



void push(Stack *S , int val){

    if(!isFull(S)){
        S->elem[++S->top] = val;
    }
}

int pop(Stack *S){

    if(!isEmpty(S)){
        int toReturn = S->elem[S->top];
        --S->top;
        return toReturn;
    }
    else{
        printf("Stack is empty");
        return -1;
    }
}


int peek(Stack *S){
  
    if(!isEmpty(S)){
       return S->elem[S->top];
    } else{
        printf("Stack is empty");
        return -1;
    }

}


void display(Stack *S){

    Stack *tempS = init();

    if(isEmpty(S)){
        printf("Stack is empty");
    } else{
        while(!isEmpty(S)){
            int data = pop(S);
            printf("%d\n",data);
            push(tempS, data);
        }

        while(!isEmpty(tempS)){
            int data = pop(tempS);
            push(S, data);
        }

    }
    free(tempS);

}



int main(){
    Stack *S = init();

    push(S, 10);
    push(S, 30);
    push(S, 20);

    printf("Stack contents after push:\n");
    display(S);

    printf("Top element: %d\n", peek(S));

    printf("Popped: %d\n", pop(S));
    printf("Popped: %d\n", pop(S));

    printf("Stack contents after pop:\n");
    display(S);

    printf("Popped: %d\n", pop(S));
    printf("Popped from empty (should show error): %d\n", pop(S));

    free(S);

    return 0;
}