#include <stdio.h>

void invert(char line[]){
    if(scanf("%[^\n]%*c", line) == EOF) return;
    char line2[255];
    invert(line2);
    printf("%s\n", line);
}
int main(){
    char line[255];
    invert(line);
    return 0;
}