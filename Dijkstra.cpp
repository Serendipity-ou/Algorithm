#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

int inf = 0x3f3f3f; //用inf存储一个我们认为的正无穷大值
int map[maxsize][maxsize];	//邻接矩阵存边信息                  
int n,m;						                       
int dis[maxsize];	//点A到各点的距离 
int vis[maxsize] = {0};		//标记是否访问过
int i, j;

void Dijkstra(){
	int t,k,min;
	for (i = 1; i <= n; i++){
		min = inf;
		for (j = 1; j <= n; j++){
			if (vis[j] == 0 && dis[j] < min){
				min = dis[j];
				t = j;
			}
		}
		vis[t] = 1;
		for (k = 1; k <= n; k++){
			if (vis[k] == 0 && dis[k] > dis[t] + map[t][k]){
				dis[k] = dis[t] + map[t][k];
			}
		}
	}
}

int main(){
	int u, v, w; 
	scanf("%d %d",&n,&m);
	
	//初始化 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = inf;
		}
		if (i == 1)
			dis[i] = 0;
		else
			dis[i] = inf;
	}
	
	for (int i = 1; i <= m; i++) {
			scanf("%d %d %d",&u,&v,&w);
			map[u][v] = w;	
			if (u == 1)
				dis[v] = w;
	}
	Dijkstra();
	printf("a点到h点的最短距离为：%d\n",dis[8]);
	return 0;
}
