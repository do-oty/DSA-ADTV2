#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    CODING PRACTICE 1

    Topics covered in this single file:
    - ADT List using array implementation
    - ADT List using singly linked list implementation
    - Stack using array implementation
    - Queue using array implementation

    HOW TO USE:
    - Read the TODO comments in each section.
    - Implement the missing functions.
    - Compile and run this file.
    - The built‑in simple tests in main() will show expected vs actual results.

    You do NOT need any other files to run this.
*/

/* ============================================================
   PART 1: ARRAY-BASED LIST OF INTS
   ============================================================ */

#define AL_MAX 20

typedef struct {
    int data[AL_MAX];
    int count;       /* current number of elements */
} ArrayList;

void al_init(ArrayList *L) {
    L->count = 0;
}

/* TODO 1
 * Implement al_insertEnd:
 *  - Insert value x at the END of the list if there is space.
 *  - Return true if successful, false if list is already full.
 */
bool al_insertEnd(ArrayList *L, int x) {
    /* YOUR CODE HERE */

    if(L->count < AL_MAX){
       L->data[L->count] = x;
        L->count++;
        return true;
    } else{
        return false;
    }

}

/* TODO 2
 * Implement al_removeAt:
 *  - Remove the element at position pos (0‑based index).
 *  - Shift later elements left to fill the gap.
 *  - Return true if pos is valid and removal happens, else false.
 */
bool al_removeAt(ArrayList *L, int pos) {
    /* YOUR CODE HERE */

    if(L->count < AL_MAX && L->count > 0){
        for(int i = pos; i < L->count ; i++ ){
            L->data[i] = L->data[i+1];
        }
        L->count--;
        return true;
    } else{
        return false;
    }
}

void al_print(ArrayList *L) {
    int i;
    printf("[");
    for (i = 0; i < L->count; i++) {
        printf("%d", L->data[i]);
        if (i + 1 < L->count) {
            printf(" ");
        }
    }
    printf("]\n");
}

/* ============================================================
   PART 2: SINGLY LINKED LIST OF INTS
   ============================================================ */

typedef struct node {
    int data;
    struct node *link;
} Node, *List;

void ll_init(List *L) {
    *L = NULL;
}

/* TODO 3
 * Implement ll_insertFront:
 *  - Allocate a new node storing x.
 *  - Insert it at the FRONT of the list.
 *  - Update *L accordingly.
 */
void ll_insertFront(List *L, int x) {
    /* YOUR CODE HERE */
    
    Node *newNode = malloc(sizeof(Node));
    newNode->link = NULL;
    newNode->data= x;

    newNode->link = *L;
    *L= newNode;
}

/* TODO 4
 * Implement ll_deleteFirst:
 *  - If list is not empty:
 *      * remove the first node,
 *      * store its value into *removed,
 *      * free the node,
 *      * return true.
 *    Otherwise, return false and do not touch *removed.
 */
bool ll_deleteFirst(List *L, int *removed) {
    /* YOUR CODE HERE */
    
    if(*L == NULL){
        return false;
    } else{
        Node *temp = *L;
        *removed = temp->data; 
        *L = (*L)->link;
        free(temp);
        return true;
    }


   
}

void ll_print(List L) {
    printf("[");
    while (L != NULL) {
        printf("%d", L->data);
        if (L->link != NULL) {
            printf(" ");
        }
        L = L->link;
    }
    printf("]\n");
}

/* ============================================================
   PART 3: ARRAY-BASED STACK OF CHARS
   ============================================================ */

#define ST_MAX 10

typedef struct {
    char data[ST_MAX];
    int top;      /* index of top element, -1 when empty */
} CharStack;

void st_init(CharStack *S) {
    S->top = -1;
}

bool st_isEmpty(CharStack *S) {
    return S->top == -1;
}

bool st_isFull(CharStack *S) {
    return S->top == ST_MAX - 1;
}

/* TODO 5
 * Implement st_push:
 *  - If stack is not full, push ch and return true.
 *  - If full, do nothing and return false.
 */
bool st_push(CharStack *S, char ch) {
    /* YOUR CODE HERE */

    if(!st_isFull(S)){
      S->data[++S->top]= ch;
      return true;
    } else{
        return false;
    }
  
}

/* TODO 6
 * Implement st_pop:
 *  - If stack is not empty, pop the top char into *pch and return true.
 *  - If empty, return false and do not touch *pch.
 */
bool st_pop(CharStack *S, char *pch) {
    /* YOUR CODE HERE */
    if(!st_isEmpty(S)){
        (*pch) = S->data[S->top];
        --S->top;
        return true;
      } else{
          return false;
      }
    
}

void st_print(CharStack *S) {
    int i;
    printf("Stack top -> ");
    for (i = S->top; i >= 0; i--) {
        printf("%c ", S->data[i]);
    }
    printf("\n");
}

/* ============================================================
   PART 4: ARRAY-BASED QUEUE OF INTS (CIRCULAR)
   ============================================================ */

#define Q_MAX 8

typedef struct {
    int data[Q_MAX];
    int front;   /* index of front element */
    int rear;    /* index of last element */
    int count;   /* number of elements in queue */
} IntQueue;

void q_init(IntQueue *Q) {
    Q->front = 0;
    Q->rear = -1;
    Q->count = 0;
}

bool q_isEmpty(IntQueue *Q) {
    return Q->count == 0;
}

bool q_isFull(IntQueue *Q) {
    return Q->count == Q_MAX;
}

/* TODO 7
 * Implement q_enq:
 *  - If queue not full, insert x at the rear (circularly) and return true.
 *  - If full, return false and do nothing.
 */
bool q_enq(IntQueue *Q, int x) {
    /* YOUR CODE HERE */
    if(!q_isFull(Q)){
        Q->rear= (Q->rear + 1) % Q_MAX;
        Q->data[Q->rear] = x;
        
        Q->count++;
        return true;

    } else{
        return false;
    }
  
}

/* TODO 8
 * Implement q_deq:
 *  - If queue not empty, remove front element into *px and return true.
 *  - If empty, return false and do not touch *px.
 */
bool q_deq(IntQueue *Q, int *px) {
    /* YOUR CODE HERE */
    if(!q_isEmpty(Q)){
        (*px) = Q->data[Q->front];
        Q->front = (Q->front + 1) % Q_MAX;
        Q->count--;
        return true;

    } else{
        return false;
    }
}

void q_print(IntQueue *Q) {
    int i, idx;
    printf("Queue front -> ");
    idx = Q->front;
    for (i = 0; i < Q->count; i++) {
        printf("%d ", Q->data[idx]);
        idx = (idx + 1) % Q_MAX;
    }
    printf("<- rear\n");
}

/* ============================================================
   SIMPLE TESTS IN main()
   ============================================================ */

static void test_array_list(void) {
    printf("\n=== TEST ARRAY LIST ===\n");
    ArrayList L;
    al_init(&L);

    al_insertEnd(&L, 10);
    al_insertEnd(&L, 20);
    al_insertEnd(&L, 30);
    al_insertEnd(&L, 40);

    printf("Expected: [10 20 30 40]\nActual:   ");
    al_print(&L);

    al_removeAt(&L, 1);   /* remove 20 */
    printf("Expected: [10 30 40]\nActual:   ");
    al_print(&L);
}

static void test_linked_list(void) {
    printf("\n=== TEST LINKED LIST ===\n");
    List L;
    int removed;

    ll_init(&L);
    ll_insertFront(&L, 3);
    ll_insertFront(&L, 2);
    ll_insertFront(&L, 1);

    printf("Expected: [1 2 3]\nActual:   ");
    ll_print(L);

    if (ll_deleteFirst(&L, &removed)) {
        printf("Deleted first: %d (expected 1)\n", removed);
    } else {
        printf("Delete first failed (should not).\n");
    }
    printf("Expected: [2 3]\nActual:   ");
    ll_print(L);
}

static void test_stack(void) {
    printf("\n=== TEST STACK ===\n");
    CharStack S;
    char ch;

    st_init(&S);
    st_push(&S, 'A');
    st_push(&S, 'B');
    st_push(&S, 'C');

    printf("Expected top-> C B A\nActual:        ");
    st_print(&S);

    if (st_pop(&S, &ch)) {
        printf("Popped: %c (expected C)\n", ch);
    } else {
        printf("Pop failed (should not).\n");
    }
    printf("Expected top-> B A\nActual:        ");
    st_print(&S);
}

static void test_queue(void) {
    printf("\n=== TEST QUEUE ===\n");
    IntQueue Q;
    int x;

    q_init(&Q);
    q_enq(&Q, 5);
    q_enq(&Q, 6);
    q_enq(&Q, 7);
    q_enq(&Q, 8);

    printf("Expected: 5 6 7 8\nActual:   ");
    q_print(&Q);

    q_deq(&Q, &x);
    q_deq(&Q, &x);
    q_enq(&Q, 9);
    q_enq(&Q, 10);

    printf("Expected (circular): 7 8 9 10\nActual:               ");
    q_print(&Q);
}

int main(void) {
    printf("=== CODING PRACTICE 1 DRIVER ===\n");
    printf("Implement the TODO functions, then compile and run.\n");

    test_array_list();
    test_linked_list();
    test_stack();
    test_queue();

    return 0;
}

