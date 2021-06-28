#include <stdio.h>

int sum_number(int number, int sum){
    if(number < 10) return number+sum;
    sum += number%10;
    return sum_number(number/10, sum);  
}
void function(int k, int raiz_digital, int i, int number){
    while(i < k){
        int number_sum = sum_number(number, 0); 
        while(number_sum >= 10){
            number_sum = sum_number(number_sum, 0); 
        }
        if(number_sum == raiz_digital) i++;
        number++; 
    }
    printf("%d\n", number-1); 
}
int main(){
    int n, k, raiz_digital;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &k, &raiz_digital);
        function(k, raiz_digital, 0 , 0);
    }

}