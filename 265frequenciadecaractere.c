#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node;

struct Node{
    char value;
    int frequency;
    node *next;  
};

node *create_linked_list(){
    return NULL;
}

node *add(node *head, char value, int frequency){
    node *new = (node*) malloc(sizeof(node));
    new->value = value;
    new->frequency = frequency;
    new->next = head;
    return new;
}

void print_linked_list(node *head){
    node *current = head;
    while(current != NULL){
        printf("%c %d\n", current->value, current->frequency);
        current = current->next;
    }
}
int count_chars(char i, char string[]){
    int count = 0;
    for(int j=0; j<strlen(string); j++){
        if(string[j] == i) count++;
    }
    return count;
}
int main(){

    node *list = create_linked_list();
    char string[255];
    fgets(string, 255, stdin);
    for(int i=0; i < 256; i++){
        int frequency = count_chars(i, string);
        if (frequency > 0){
            list = add(list, i, frequency);
        }
    }
    print_linked_list(list);
    return 0;
}
