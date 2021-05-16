#include <stdio.h>
#include<stdlib.h>
#define MAX 500

void quickSort(int a[], int left, int right) {
	int pivot, i, j;
	int temp;
	if (left < right){
		i = left; j = right + 1;
		pivot = a[left];
		do {
			do {
				i++;
			} while (a[i] < pivot);
			do {
				j--;
			} while (a[j] > pivot);
			if (i < j) {
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		int temp;
		temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

int select(int a[],int left,int right,int k) {
	int n=right-left;
	if (n<5){
		quickSort(a,left,right-1);
		return a[left+k-1];
	}
	int i;
	int s=n/5;
	int *m = new int[s];//中位数数组
	for (i=0;i<s;i++) {
		quickSort(a,left+i*5,left+i*5+5-1);
		m[i] = a[left+i*5+2];
	}
	quickSort(m,0,i-1);
	int mid=m[i/2];
	int *a1=new int[n];
	int *a2=new int[n];
	int *a3=new int[n];
	int num1=0,num2=0,num3=0;
	for(int i=left;i<right;i++){
		if(a[i]<mid)
			a1[num1++]=a[i];
		else if(a[i]==mid)
			a2[num2++]=a[i];
		else
			a3[num3++]=a[i];
	}
	if(num1>=k)
		return select(a1,0,num1,k);
	if (num1+num2>=k)
		return mid;
	else
		return select(a3,0,num3,k-num1-num2);
}

int main(){
	int a[MAX];
	int n,k;
	printf("请输入元素个数：");
	scanf("%d", &n);
	printf("请输入元素："); 
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	printf("请输入k：");
	scanf("%d", &k);
	printf("第k小的值是：%d", select(a, 0, n, k));
}
