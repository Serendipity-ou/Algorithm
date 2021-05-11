#include<stdio.h>
#define maxsize 100
int arr[maxsize], temp[maxsize];

void merge_sort(int left, int right){
	int mid = (left + right) / 2;
	int p = left, i = left, j = mid + 1;
	
	if (left == right) 
		return;							 
	
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	
	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) 
			temp[p++] = arr[j++]; 
		else 
			temp[p++] = arr[i++];					 
	}
	while (i <= mid) 
		temp[p++] = arr[i++];			 
	while (j <= right) 
		temp[p++] = arr[j++];
	for (int i = left; i <= right; i++)
		arr[i] = temp[i];							 
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&arr[i]);
		
	merge_sort(1, n);
	
	for (int i = 1; i <= n; i++)
		printf("%d ",arr[i]);					 
	return 0;
}

