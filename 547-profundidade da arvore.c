#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_tree node_tree;
typedef struct Node node;
typedef struct Queue queue;

struct Node_tree{
    int value;
    node_tree* left;
    node_tree* right;
};

struct Node{
    int value;
    node *next;  
};

struct Queue{ //fila
    int size;
    node* head;
    node* tail;
};

node_tree* create_binary_tree(int value, node_tree* left, node_tree* right){
    node_tree* new_node_tree = (node_tree*) malloc(sizeof(node_tree)); 
    new_node_tree->value = value;
    new_node_tree->left = left;
    new_node_tree->right = right;

    return new_node_tree;  
}

queue *create_queue(){
    queue* new_queue =  (queue*) malloc(sizeof(queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->size = 0;
    return new_queue; 
}

void enqueue(queue* queue, int value){
    node* new_node = (node*) malloc(sizeof(node));

    new_node->value = value;
    new_node->next = NULL;

    if(queue->size == 0){
        queue->head = new_node; 
        queue->tail = new_node;
    }
    else{
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;
}

int dequeue(queue* queue){

    if(queue->size == 0) return -1;
    int aux;

    aux = queue->head->value;
    queue->head = queue->head->next;
    queue->size--;

    return aux;
}

void build_tree(node_tree* bt, queue* fila)
{
    if(bt->value == -1) return;

    if (fila->size > 0) 
    {
        bt->left = create_binary_tree(dequeue(fila), NULL, NULL);
        build_tree(bt->left, fila);
    }
    if (fila->size > 0)
    {
        bt->right = create_binary_tree(dequeue(fila), NULL, NULL);
        build_tree(bt->right, fila);
    }
}

void depth(node_tree* root, int x, int d){
    if(root->value == -1) return;
    if(root->value == x){
        printf("%d\n", d); 
    }
    else{
        depth(root->right, x, d+1);
        depth(root->left, x, d+1);
    }
}
int main(){ 
    char btree[10000];
    fgets(btree, 10000, stdin);     
    int n = 0, found = 0, x, exist = 0;   
    scanf("%d", &x);               
    queue* fila = create_queue();    

    // Weird reading algorithm
    for (int i = 0; btree[i] != '\0'; i++){
        if(btree[i] >= '0' && btree[i] <= '9'){
            n = n * 10 + (btree[i]-'0');
            found = 1;
        }
        else{
            if (btree[i] == ')' && btree[i-1] == '('){
                enqueue(fila, -1);
            }
            else if (found){
                if(n == x) exist = 1;
                enqueue(fila, n);
                n = 0;
                found = 0;
            } 
        }
    }
    if(!exist) printf("NAO ESTA NA ARVORE\n-1\n");
    else{
        node_tree* root = create_binary_tree(dequeue(fila), NULL, NULL);
        build_tree(root, fila);
        printf("ESTA NA ARVORE\n");
        depth(root, x, 0);  
    }

}