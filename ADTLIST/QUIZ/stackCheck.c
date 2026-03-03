// QUESTION 2;

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    char websiteName[MAX];
    int websiteYear;
    int timeAccessed;
    int SFW;

}Website;


typedef struct {
    Website w[MAX];
    int top;
}Stack;

Stack* init(){
    Stack *S = malloc(sizeof(Stack));
    S->top = -1;
    return S;
}

int isEmpty(Stack *S){
    return (S->top == -1) ? 1 : 0;
}

Website peek(Stack *S){
    if(isEmpty(S)){
        printf("Stack is empty!\n");
    }
    return S->w[S->top];
}

void push(Stack *S, Website site){
    if(S->top == MAX - 1){
        printf("Stack is full!\n");
    } else {
        S->w[++S->top] = site;
    }
}

Website pop(Stack *S){
   
    if(isEmpty(S)){
        printf("Stack is empty!\n");
    } else {
        return S->w[S->top--];
    }
}

void display(Stack *S){
    if(isEmpty(S)){
        printf("Stack is empty\n");
    } else{
        Stack *tempS = init();

        while(!isEmpty(S)){
            Website w = pop(S);
            printf("%s %d %d %d\n", w.websiteName, w.websiteYear, w.timeAccessed, w.SFW);
            push(tempS, w);
        }

        while(!isEmpty(tempS)){
            Website w = pop(tempS);
            push(S, w);
        }

        free(tempS);
    }
}

void delNSFW(Stack *S){

    Stack *tempS = init();


    if(S->top == -1){
        printf("List is empty!");
    } else{
        while(!isEmpty(S)){
            Website temp = peek(S);
            if(temp.SFW == 0){
                pop(S);
            } else {
                push(tempS,temp);
                pop(S);
            }
        }

        while(!isEmpty(tempS)){
            Website temp = peek(tempS);
            push(S,temp);
            pop(tempS);
        }
    }

      free(tempS);

}


int main (){

    Stack *S = init();
 
    Website w1 = {"site1", 2000, 5, 1};
    Website w2 = {"site2", 2005, 3, 0};
    Website w3 = {"site3", 2010, 10, 1};


    push(S, w1);
    push(S, w2);
    push(S, w3);

    printf("Stack before delNSFW:\n");
    display(S);

    delNSFW(S);

    printf("Stack after delNSFW:\n");
    display(S);

    return 0;
}