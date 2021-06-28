#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct Queue queue;

struct Node{
    int value;
    int priority;
    node *next;  
};

struct Queue{ //fila
    node* head;
};

queue *create_queue(){
    queue* new_queue =  (queue*) malloc(sizeof(queue));
    new_queue->head = NULL;
    return new_queue; 
}

void enqueue(queue* pq, int value, int p){
    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->value = value;
    new_node->priority = p;

    if(pq->head == NULL || p > pq->head->priority){
        new_node->next = pq->head;
        pq->head = new_node;
    }
    else{
        node* current = pq->head;
        while(current->next != NULL && current->next->priority > p){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        
    }
}

node* dequeue(queue* queue){
    if(queue->head == NULL) return NULL;
    node* aux = queue->head;

    queue->head = queue->head->next;
    aux->next = NULL;

    return aux;
}

int count(queue* fila, int size){
    int count_students = 0;
    for(int i = 0; i < size; i++){
        if(dequeue(fila)->value == i) count_students++;
    }

    return count_students;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i < n; i++){
        int size;
        queue* fila = create_queue();

        scanf("%d", &size);
        for(int j = 0; j < size; j++){
            int priority;
            scanf("%d", &priority);
            enqueue(fila, j, priority);
        }

        printf("%d\n", count(fila, size));
    }

}

