#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000
typedef struct Stack stack;

struct Stack{ 
    int size;
    char values[MAX_STACK_SIZE];       
};

stack *create_stack(){
    stack* new_stack = (stack *) malloc(sizeof(stack)); 
    new_stack->size = 0;
    return new_stack;
}
int pop(stack* pilha){
    if(pilha->size == 0) return -1;
    pilha->size--; 
    return pilha->values[pilha->size];  
} 
int push(stack* pilha, int value){
    if(pilha->size == MAX_STACK_SIZE) return -1;
    pilha->values[pilha->size] = value; 
    pilha->size++;
    return 1;
}
int peek(stack* pilha){
    if(pilha->size == 0) return -1;
    return pilha->values[pilha->size - 1]; 
}

int is_balanced(char string[]){
    stack* colchetes = create_stack();
    stack* parentesis = create_stack();

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == '('){
            push(parentesis, '(');
        }
        else if(string[i] == ')'){
            if(pop(parentesis) == -1) return 0;
        }
        else if(string[i] == '['){
            push(colchetes, '[');
        }
        else if(string[i] == ']'){
            if(pop(colchetes) == -1) return 0;
        }
    }
    if(colchetes->size == 0 && parentesis->size == 0) return 1; 
    return 0;
}
int main(){
    int n;
    scanf("%d\n", &n);

    for(int i=0; i<n; i++){
        char string[500];
        fgets(string, 500, stdin);
        int isBalanced = is_balanced(string);
        (isBalanced == 1) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}