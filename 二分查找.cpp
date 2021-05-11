#include<stdio.h>
int Binary_search(int T[],int n,int x){
	int mid;
	int left=0;
	int right=n-1;
	while(left<=right){
		mid=(left+right)/2;
		if(x<T[mid])
			right=mid-1;
		else if(x>T[mid])
			left=mid+1;
		else
			return mid;
	}
	return 0;
} 

int main(){
	int T[50];
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&T[i]);
	}
	scanf("%d",&x);
	printf("%d\n",Binary_search(T,n,x));
	return 0;
} 
