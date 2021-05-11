#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

int inf = 0x3f3f3f; //用inf存储一个我们认为的正无穷大值
int e[maxsize][maxsize];
int k, i, j;
int v, u,w ;

void Floyd(int n,int m){
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}

	for (i = 1; i <= m; i++){
		scanf("%d %d %d", &v, &u, &w);
		e[v][u] = w; 
	}

	for (k = 1; k <= n; k++){
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	
	Floyd(n,m);
	
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			printf("%5d", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}
