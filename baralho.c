#include <stdio.h>
#include <string.h>

struct cartas{
    char nome[75];
    int k;
    int array[60];
    char proximo[75];
};
void troca(struct cartas *i, struct cartas *j){
    struct cartas aux = *i;
    *i = *j;
    *j = aux; 
}
int main(){
    int n;
    scanf("%d ", &n);
    struct cartas cartas[n];

    for(int i = 0; i < n; i++){
        gets(cartas[i].nome);
        scanf("%d", &cartas[i].k);
        for(int j = 0; j < cartas[i].k; j++){
            scanf("%d ", &cartas[i].array[j]);
        }
        gets(cartas[i].proximo);
        
    }

    char primeiro_nome[75];
    gets(primeiro_nome);

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(strcmp(cartas[i].nome, cartas[j].nome) > 0){
                troca(&cartas[i], &cartas[j]);
            }
        }
    }
    return 0;
}
