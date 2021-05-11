#include<stdio.h>
int Sequential_search(int T[],int n,int x){
	int j;
	for(j=0;j<n;j++){
		if(T[j]==x)
			return j;
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
	printf("%d\n",Sequential_search(T,n,x));
	return 0;
} 
