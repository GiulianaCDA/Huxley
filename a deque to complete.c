node_t*  node_new (int value){
    node_t* new_node = (node_t*) malloc(sizeof(node_t)); 
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct(){
    deque_t* new_deque = (deque_t*) malloc(sizeof(deque_t));
    new_deque->front = NULL;
    new_deque->rear = NULL;
    new_deque->size = 0;
    
    return new_deque;
}
//Libera a memória do conteúdo e do próprio deque
void destruct(deque_t *deque){
    free(deque);
}

//Retorna o tamanho do deque
int size (deque_t *deque){
    return deque->size;
}
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool empty (deque_t *deque){
    if(size(deque) == 0) return true;
    else return false;
}
-
//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int front(deque_t *deque){
    if(deque->size == 0) return INT_MIN;
    else return deque->front->value;
}
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int rear(deque_t *deque){
    if(deque->size == 0) return INT_MIN;
    else return deque->rear->value;
}

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void enqueue_rear(deque_t *deque, int value){
    node_t* new_node = node_new(value);  
    if(deque->size == 0){
        deque->front = new_node;
        deque->rear = new_node;
    }
    else{
        deque->rear->next = new_node;
        new_node->prev = deque->rear;
        deque->rear = new_node;
    }
    deque->size++;
}
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void enqueue_front(deque_t *deque, int value){
    node_t* new_node = node_new(value); 
    if(deque->size == 0){
        deque->front = new_node;
        deque->rear = new_node;
    }
    else{
        deque->front->prev = new_node;
        new_node->next = deque->front;
        deque->front = new_node;
    }
    deque->size++;
}
//Retira o valor do final caso não esteja vazia
void dequeue_rear(deque_t *deque){
    if(deque->size > 0){
        node_t* aux = deque->rear;
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
        free(aux);
        deque->size--;
    }
}
//Retira o valor da frente caso não esteja vazia
void dequeue_front(deque_t *deque){
    if(deque->size > 0){
        node_t* aux = deque->front;
        deque->front = deque->front->next;
        free(aux);
        deque->size--;
    }
}
//Limpa o conteudo do deque(deixa ele vazio)
void erase(deque_t *deque){
    while(deque->size > 0) dequeue_rear(deque);
}

void print(deque_t *deque){
    node_t* current = deque->front;
    while(current->next != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("%d\n", current->value);
}
