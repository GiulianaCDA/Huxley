#include <stdio.h>

void transporte_linha(int n, int m, int matriz2[m][n], int matriz1[n][m], int i, int j){
	if(j == n){
		return;
	}
	else{
		matriz2[i][j] = matriz1[j][i];
		j++;
		transporte_linha(n, m, matriz2, matriz1, i, j);
	}
}
void teletransporte(int n, int m, int matriz2[m][n], int matriz1[n][m], int i){
	if(i == m){
		return;
	}
	else{
		transporte_linha(n, m, matriz2, matriz1, i, 0);
		i++;
		teletransporte(n, m, matriz2, matriz1, i);
	}
}

void ler_linha(int m, int matriz1[][m], int i, int j){
	if(j == m){
		return;
	}
	else{
		scanf("%d", &matriz1[i][j]);
		j++;
		ler_linha(m, matriz1, i, j);
	}
}
void ler_matriz(int n, int m, int matriz1[][m], int i){
	if(i == n){
		return;
	}
	else{
		ler_linha(m, matriz1, i, 0);
		i++;
		ler_matriz(n, m, matriz1, i);
	}
}

void printar_linha(int n, int m, int matriz2[m][n], int i, int j){
	if(j == n){
		return;
	}
	else{
		if(j == 0){
			printf("| %d ", matriz2[i][j]);
		}
		else if(j == n - 1){
			printf("%d |\n", matriz2[i][j]);
		}
		else{
			printf("%d ", matriz2[i][j]);
		}
		j++;
		printar_linha(n, m, matriz2, i, j);
	}
}
void printar(int n, int m, int matriz2[m][n], int i){
	if(i == m){
		return;
	}
	else{
		printar_linha(n, m, matriz2, i, 0);
		i++;
		printar(n, m, matriz2, i);
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int matriz1[n][m], matriz2[m][n];
	ler_matriz(n, m, matriz1, 0);
	teletransporte(n, m, matriz2, matriz1, 0);
	printar(n, m, matriz2, 0);
	return 0;
}
