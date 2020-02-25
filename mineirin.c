#include <stdio.h>

int eh_primo(int n, int x){
	if(x == 1){
		return 1;
	}
	if((n == 1) || (n % x == 0)){
		return 0;
	}
	eh_primo(n, x-1);
}
int primos(int n, int m, int j){//verifica se são coprimos
	if(j == 1){
		return 1;
	}
	if(n % j == 0 && m % j == 0 || m == 1 && n == 1){
		return 0;
	}
	primos(n, m, j-1);
}
void calcula(int t, int n, int m, int i){
	if(i == t){
		return;
	}
	int j, copy_n;
	copy_n = n;
	if(n < m){
		j = n;
	}
	else{
		j = m;
	}

	if(eh_primo(n, n-1) == 1){
		n = n * 2;
	}
	else if(primos(n, m, j) == 1){
		n = (2 * (n+m)) - 3;
	}
	else{
		n = n + 1;
	}
	printf("%d ", n);
	i++;
	m = n;
	calcula(t, n, m, i);
}
int main(){
	int t, n, m;
	scanf("%d%d%d",&t, &m, &n);
	printf("%d %d ", m, n);
	calcula(t, n, m, 2);
	return 0;
}
