#include <iostream>
using namespace std;

#define N 7
#define MAXVALUE 10000

void matrix_chain(int* p, int len, int m[N][N], int s[N][N]) {
	int i, j, k, t;
	int n = len - 1;
	for (i = 1; i <= n; i++)
		m[i][i] = 0;

	for (t = 2; t <= n; t++){
		for (i = 1; i <= n - t + 1; i++) {
			j = i + t - 1;
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j]; 
			s[i][j] = i;
			for (k = i+1; k <= j - 1; k++){
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;     
				}
			}
		}
	}
}

void print_optimal_parents(int s[N][N], int i, int j){
	if (i == j)
		cout << "A" << i;
	else {
		cout << "(";
		print_optimal_parents(s, i, s[i][j]);
		print_optimal_parents(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main(){
	int p[N] = { 5,6,2,9,7,6 };
	int m[N][N], s[N][N];
	matrix_chain(p, 6, m, s);
	cout << "当n=5时最优解为：" << m[1][5] << endl;
	cout << "最优括号化方案：";
	print_optimal_parents(s, 1, 5);
	cout << endl;
	return 0;
}

