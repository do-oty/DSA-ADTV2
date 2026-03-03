#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;

}Node;

typedef struct {
    Node *top;
}Stack;

Stack* init(){
    Stack *S = malloc(sizeof(Stack));
    S->top = NULL;

    return S;
}

void push(Stack *S, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = S->top;
    S->top = newNode;

}

bool isEmpty(Stack *S){
    return S->top == NULL ? true : false;
}

int pop(Stack *S){
    if(isEmpty(S)){
        printf("List is empty");
        return -1;
    } else{
        
        Node *temp = S->top;
        int data = S->top->data;
        S->top = S->top->next;
        
        free(temp);
        return data;

    }

}



int peek(Stack *S){
    return (!isEmpty(S)) ? S->top->data : -1;
}


void display (Stack *S){



    if(isEmpty(S)){
        printf("List is empty");
    } else{
        Stack *tempS = init();

        while(!isEmpty(S)){
            int data = pop(S);
            printf("%d ", data);
            push(tempS, data);
        }
    
        while(!isEmpty(tempS)){
            int data = pop(tempS);
            push(S, data);
        }

        free(tempS);
    }
   

}

   
int main(){
    Stack *S = init();

    push(S, 10);
    push(S, 30);
    push(S, 20);

    printf("Stack contents after push:\n");
    display(S);

    printf("\nTop element: %d\n", peek(S));

    printf("Popped: %d\n", pop(S));
    printf("Popped: %d\n", pop(S));

    printf("Stack contents after pop:\n");
    display(S);

    printf("Popped: %d\n", pop(S));
    printf("Popped from empty (should show error): %d\n", pop(S));

    free(S);

    return 0; 
}
