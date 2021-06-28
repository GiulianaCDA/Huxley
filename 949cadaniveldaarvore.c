#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node;
typedef struct Min_max min_max;

struct Node{
    int value;
    int indice;
    node* left;
    node* right;
};

struct Min_max{
    int min;
    int max;
};

node* create_binary_tree(int value, node* left, node* right, int i){
    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;
    new_node->indice = i;
    return new_node;  
}

void altura(node* tree, int *count, int temp_count){
    if(tree == NULL){
        if(temp_count > *count) *count = temp_count;
        return;
    }
    altura(tree->left, count, temp_count + 1);
    altura(tree->right, count, temp_count + 1);
}

void percorre(node* tree, int i, int h, min_max levels[]){
    if(tree == NULL) return;
    if(i == h) return;
    if(tree->value > levels[i].max) levels[i].max = tree->value;
    if(tree->value < levels[i].min) levels[i].min = tree->value;
    percorre(tree->right, i+1, h, levels); 
    percorre(tree->left, i+1, h, levels);
}
int main(){
    int n;

    scanf("%d", &n);
    node* tree[n];

    for(int i=0; i < n; i++){
        tree[i] = create_binary_tree(-1, NULL, NULL, i);
    }

    for(int i=0; i < n; i++){
        int value, left, right;
        scanf("%d %d %d", &value, &left, &right); 

        if(left != -1) tree[i]->left = tree[left];
        if(right != -1) tree[i]->right = tree[right];
        tree[i]->value = value;
    }

    int h = 0;
    altura(tree[0], &h, 0);

    min_max levels[h];
    for(int i = 0; i < h; i++){  
        levels[i].min = 2147483646;
        levels[i].max = -2147483647;
    }
    
    percorre(tree[0], 0, h, levels);

    for(int i=0; i < h; i++){
        printf("Nivel %d: Maior = %d, Menor = %d", i+1, levels[i].max, levels[i].min);
    }
    
}