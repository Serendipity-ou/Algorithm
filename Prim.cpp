#include<stdio.h>
#include<stdlib.h>

#define maxsize 100
int m, n;
int graph[maxsize][maxsize] = {0};

void prim() {
	int v[maxsize]={0},weight[maxsize]={0};
	//����v1��ĳ�ʼ������
	for (int i = 2; i <= n; i++) {	
		weight[i] = graph[1][i];
		v[i] = 1;
	}
	for (int i = 0; i < n-1; i++){	//n�������n-1�� 
		int min = 0x3f3f3f3f;
		int point;
		for (int j = 2; j <= n; j++){
			if (weight[j]<min && weight[j]!=0){
				min = weight[j];
				point = j;
			}
		}
		printf("%d - %d \n", v[point], point);
		weight[point] = 0;	//��ǵ��ѷ���

		//���½ڵ��������ڵ�֮���Ȩֵ
		for (int j = 2; j <= n; j++) {     
			if (weight[j] > graph[point][j]&& weight[j]!=0){
				weight[j] = graph[point][j];
				v[j] = point;
			}
		}
	}
}

int main(){
	int u, v, w; 
	scanf("%d %d", &n, &m);//n���ǣ�m����
	for (int i = 1; i <= m; i++){
		scanf("%d %d %d", &u, &v, &w);
		graph[u][v] = w;
		graph[v][u] = w;
	}
	prim();
	return 0;
}
