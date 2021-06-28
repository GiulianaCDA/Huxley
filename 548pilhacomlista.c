#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000
typedef struct Stack stack;
typedef struct Node node;

struct Stack{ 
    int size;
    node* values[MAX_STACK_SIZE];       
};

struct Node{
    int value;
    node *next;  
};

stack *create_stack(){
    stack* new_stack = (stack *) malloc(sizeof(stack)); 
    new_stack->size = 0;
    return new_stack;
}

node* pop(stack* pilha){
    if(pilha->size == 0) return NULL;
    pilha->size--; 
    return pilha->values[pilha->size]; 
} 

int push(stack* pilha, node* value){
    if(pilha->size == MAX_STACK_SIZE) return -1;
    pilha->values[pilha->size] = value; 
    pilha->size++;
    return 1;
}

node *create_linked_list(){
    return NULL;
}

node *add(node *head, int value){
    node *new = (node*) malloc(sizeof(node));
    new->value = value;
    new->next = head;
    return new;
}

void print_linked_list(node *head){
    node *current = head;
    node *new_list = create_linked_list();
    
    while(current != NULL){ 
        new_list = add(new_list, current->value);
        current = current->next;
    }

    while(new_list != NULL){
        (new_list->next == NULL) ? printf("%d\n", new_list->value) : 
        printf("%d ", new_list->value); 

        new_list = new_list->next;
    }
}

node* string_to_list(char string[]){
    node* new_list = create_linked_list(); 
    char* token;
    token = strtok(string, " ");

    while(token != NULL){
        new_list = add(new_list, atoi(token));
        token = strtok(NULL, " "); 
    }
    
    return new_list;
}

int main(){
    char string[10000];
    stack *pilha = create_stack();  

    while(scanf("\n%[^\n]", string) != EOF){
        if(string[1] == 'U'){
            char line[10000];
            scanf("\n%[^\n]", line); 
            node* value = string_to_list(line);
            push(pilha, value); 
        }
        else{
            node* value = pop(pilha);
            (value == NULL) ? printf("EMPTY STACK\n") : print_linked_list(value);
        }  
    }
}