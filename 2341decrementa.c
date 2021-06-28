#include <stdio.h>

void calcula(int n, int number){
    if(n < 10){
        n % 2 == 0 ? printf("%d\n", number-4) : printf("%d\n", number-3);
        return;
    }
    separaDigito(n/10, number);
}
int main(){
    int number;
    scanf("%d", &number);
    int n = number;
    calcula(n, number);
    return 0;
}