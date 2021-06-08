#include <algorithm>
#include <iostream> 
#include<stdio.h>
using namespace std;

#define maxsize 10
int x[maxsize + 1];
int c = 8;
int m[maxsize][maxsize];

void bag(int value[], int weight[], int c, int n, int m[][maxsize]){
	int Max = min(weight[n] - 1, c);
	for (int j = 0; j <= Max; j++)
		m[n][j] = 0;

	for (int j = weight[n]; j <= c; j++)
		m[n][j] = value[n];

	for (int i = n - 1; i > 1; i--){
		Max = min(weight[i] - 1, c);
		for (int j = 0; j <= Max; j++)
			m[i][j] = m[i + 1][j];

		for (int j = weight[i]; j <= c; j++) 
			m[i][j] = max(m[i + 1][j], m[i + 1][j - weight[i]] + value[i]);
	}
	m[1][c] = m[2][c];
	if (c >= weight[1])
		m[1][c] = max(m[1][c], m[2][c - weight[1]] + value[1]);
}

//0不装入背包，1表示装入背包
void F(int m[][maxsize], int weight[], int c, int n, int x[]){
	for (int i = 1; i < n; i++){
		if (m[i][c] == m[i + 1][c])
			x[i] = 0;
		else{
			x[i] = 1;
			c -= weight[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
}

int main(){
	int  weight[maxsize], value[maxsize];
	int num;
	cout << "待装物品数量：";
	cin >> num;
	
	cout <<"待装物品重量和价值："<<endl;
	for (int i = 1; i <= num; i++)
		cin >> weight[i] >> value[i];

	bag(value, weight, c, num, m);

	cout << "背包能装的最大价值为：" << m[1][c] << endl;

	F(m, weight, c, num, x);
	cout << "背包装下的物品编号为：";
	for (int i = 1; i <= num; i++){
		if (x[i] == 1)
			cout << i << " ";
	}
	return 0;
}