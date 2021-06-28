#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 500
typedef struct Stack stack;
typedef struct Node node;

struct Node{
    int value;
    node *next;
};

struct Stack{ 
    node *top;       
};

stack *create_stack(){
    stack* new_stack = (stack *) malloc(sizeof(stack)); 
    new_stack->top = NULL;
    return new_stack;
}

int pop(stack* pilha){ // remove
    if(pilha->top == NULL) return -1;
    node* aux = pilha->top;
    pilha->top = pilha->top->next;
    aux->next = NULL;
    return aux->value;
} 

void push(stack* pilha, int value){ //add um elemento 
    node* new_top = (node*) malloc(sizeof(node));
    new_top->value = value;
    new_top->next = pilha->top;
    pilha->top = new_top;
}
        
int peek(stack* pilha){ // retorna um elemento sem tirar ele da lista
    if(pilha->top == NULL) return -1;
    return pilha->top->value; 
}

int count(stack* pilha){
    int i = 0;
    while(pop(pilha) != -1){
        i++;
    }
    return i;
}

int main(){
    stack *back = create_stack();  
    stack *forward = create_stack();
    char action[50];

    while(scanf("\n%s", action) != EOF){
        if(!strcmp(action, "ENTER")){
            push(back, 1);
            pop(forward);
        }
        else if(!strcmp(action, "BACK")){
            push(forward, 1);
            pop(back);
        }
        else{
            push(back, 1);
            pop(forward);
        }
    }
    pop(back);

    printf("BACK: %d\n", count(back));
    printf("FORWARD: %d", count(forward));
}