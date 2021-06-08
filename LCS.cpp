#include <stdio.h>

#define maxsize 150

char X[maxsize], Y[maxsize];
int C[maxsize][maxsize] = { 0 };
int B[maxsize][maxsize] = { 0 };
int m, n;

void print(int B[][maxsize], int i, int j) {
	if (i == 0 || j == 0) 
		return;
	
	if (B[i][j] == 2) {
		print(B, i - 1, j - 1);
		printf("%c ", X[i]);
	}
	else if (B[i][j] == 1) 
		print(B, i - 1, j);
	
	else 
		print(B, i, j - 1);
	
}

void LCS(char X[], char Y[], int C[][maxsize], int B[][maxsize]) {
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; ++j) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 2;
			}
			else{
				if (C[i - 1][j] > C[i][j - 1]){
					C[i][j] = C[i - 1][j];
					B[i][j] = 1;
				}
				else {
					C[i][j] = C[i][j - 1];
					B[i][j] = 0;
				}
			}
		}
	}
	print(B, m, n);
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) 
		scanf(" %c", &X[i]);
	
	for (int i = 1; i <= n; i++) 
		scanf(" %c", &Y[i]);
	
	LCS(X, Y, C, B);

	return 0;
}
