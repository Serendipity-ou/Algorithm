#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int n;      //n���ڵ�
int m;      //m����ɫ
int mm[100][100];       //��¼ͼ���ڽӾ���
int x[100];     //��¼ͼ��ɫ��һ�ֿ����ԣ�x[i]=1,2,3..k..n����ڽڵ�i��ɫΪk
int bestx[100];
int sum = 0;//������¼��ǰ���е���ɫ����

//����Լ������Ϊ���ڵ�������ͬ����ɫʱ������������·�չ���ֿ�����
bool judge(int i){
    int j;
    for (j = 1; j <= n; j++){
        if ((mm[i][j] == 1) && (x[i] == x[j]))//�ҵ��׺���Щ�ڵ���������ɫһ��
            return false;
    }
    return true;
}
void dfs(int i){
    int j;
    if (i > n){
        sum++;
        for (j = 1; j <= n; j++) 
            bestx[j] = x[j];    //��¼һ����ɫ�Ŀ�����      
    }
    else{
        //��i�ڵ㴦�����ܵ�m�ֿ�����
        for (j = 1; j <= m; j++){
            x[i] = j;   //i�ڵ�ѡ����һ����ɫ
            ////ͨ��Լ������ȥ�����������ɫ������
            if (judge(i))
                dfs(i + 1);     //��ڵ�ת�Ƶ���һ��ĵ�i+1���ڵ�
            x[i] = 0;   //i�����������ɫ������
        }
    }
}
int main(){
    int t, k;
    int i, j;
    printf("��ֱ������ĸ������ߵĸ�������ɫ������");
    scanf("%d %d %d", &n, &k, &m);//k��k����
    for (t = 0; t < k; t++){
        scanf("%d %d", &i, &j);
        mm[i][j] = 1;
        mm[j][i] = 1;
    }
    dfs(1);
    printf("�ܵĲ�ͬ��ɫ����Ϊ��%d", sum);
    return 0;
}
