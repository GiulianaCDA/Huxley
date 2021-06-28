#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node;

struct Node{
    int value;
    int frequency;
    node *next;  
};

node *create_linked_list(){
    return NULL;
}

node *add(node *head, int value,){
    node *new = (node*) malloc(sizeof(node));
    new->value = value;
    new->next = head;
    return new;
}

void print_linked_list(node *head){
    node *current = head;
    while(current != NULL){
        printf("%c %d\n", current->value);
        current = current->next;
    }
}

node *read_list(int n1, node *list){
    for(int i = 0; i < n1; i++){
        int value;
        scanf("%d", &value);
        list = add(list, value);
    }
    return list;
}

int is_sub(node* list, node* sublist){
    while(sublist != NULL){
        if(!search(list, sublist->value)) return 0;
        sublist = sublist->next;
    }
    return 1;
}

int main(){

    node *list = create_linked_list();
    node *sublist = create_linked_list();
    int n1, n2;

    scanf("%d, &n1";);

    list = read_list(n1, list);
    sublist = read_list(n2, sublist);

    printf("%d\n", is_sub(list, sublist));

    return 0;
}
