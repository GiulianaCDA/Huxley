#include <stdio.h>
#include <string.h>


int main(){
    char number[15];

    while(scanf("%s", number) != EOF){
        if(!strcmp(number, "0")){
            break;
        }
        int total = 0;
        int size = strlen(number);
        int n;
        
        for(int i = 0; i < size; i++){
            n = number[i] - '0';
            if(n % 2 == 0){
                total += n * (size - i) * 2;
            }
            else{
                total += n * (size - i) * 3;
            }
        }
        printf("%d\n", total);
        
    }

    return 0;
}