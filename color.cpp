#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int n;      //n个节点
int m;      //m种颜色
int mm[100][100];       //记录图的邻接矩阵
int x[100];     //记录图着色的一种可能性，x[i]=1,2,3..k..n代表第节点i颜色为k
int bestx[100];
int sum = 0;//用来记录当前可行的着色方案

//分析约束函数为两节点相连且同种颜色时，不会继续往下发展这种可能性
bool judge(int i){
    int j;
    for (j = 1; j <= n; j++){
        if ((mm[i][j] == 1) && (x[i] == x[j]))//我到底和哪些节点相连且颜色一样
            return false;
    }
    return true;
}
void dfs(int i){
    int j;
    if (i > n){
        sum++;
        for (j = 1; j <= n; j++) 
            bestx[j] = x[j];    //记录一种着色的可能性      
    }
    else{
        //在i节点处检测可能的m种可能性
        for (j = 1; j <= m; j++){
            x[i] = j;   //i节点选定了一种颜色
            ////通过约束函数去掉不合理的颜色可能性
            if (judge(i))
                dfs(i + 1);     //活节点转移到下一层的第i+1个节点
            x[i] = 0;   //i继续换别的颜色可能性
        }
    }
}
int main(){
    int t, k;
    int i, j;
    printf("请分别输入点的个数、边的个数、颜色个数：");
    scanf("%d %d %d", &n, &k, &m);//k是k条边
    for (t = 0; t < k; t++){
        scanf("%d %d", &i, &j);
        mm[i][j] = 1;
        mm[j][i] = 1;
    }
    dfs(1);
    printf("总的不同着色方案为：%d", sum);
    return 0;
}
