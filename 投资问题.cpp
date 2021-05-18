#include<iostream>
using namespace std;
#define maxsize 100
int main() {
	int	m, n;
	int start[maxsize][maxsize];	
	int localmax[maxsize][maxsize] = { 0 };	
	int result[maxsize][maxsize];	
	cin >> n>> m;
	for (int i = 0; i <= m; i++){
		for (int j = 1; j <= n; j++)
			cin >> start[j][i];
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 0; k <= j; k++){
				if (localmax[i][j] <= localmax[i - 1][j - k] + start[i][k]){
					localmax[i][j] = localmax[i - 1][j - k] + start[i][k];
					result[i][j] = k;
				}
			}
		}
	}
	cout << "最大收益：" << localmax[n][m] << endl;
	return 0;
}
