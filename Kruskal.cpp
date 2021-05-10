#include <stdio.h>
#define maxsize 100

typedef struct{
	int vex_start; 	//边的起始顶点
	int vex_end; 	//边的终止顶点
	int weight; 	//边的权值
}Edge;

void kruskal(Edge E[],int n,int e){ 
	int j=0,v1,v2,sn1,sn2;
	int k=1;	//当前生成树第k条边 
	int a[maxsize];
	
	for(int i=1;i<=n;i++)
		a[i]=i;
		
	while(k<e){
		v1=E[j].vex_start;
		v2=E[j].vex_end;
		sn1=a[v1];
		sn2=a[v2]; 
		
		if(sn1!=sn2){
			printf("%d - %d \n",v1,v2);
			k++;
			if(k>=n)
				break;
			for(int i=1;i<=n;i++) 
				if (a[i]==sn2)
					a[i]=sn1;
		}
		j++; 
	}
}

int fun(Edge arr[],int low,int high){
	Edge lowx=arr[low];
	int w=arr[low].weight;
	
	while(low<high){
		while(low<high && arr[high].weight>=w)
			high--;
			if(low<high)
				arr[low++]=arr[high];

		while(low<high && arr[low].weight<=w)
			low++;
			if(low<high)
				arr[high--]=arr[low];
	}
	arr[low]=lowx;
	return low;
 } 

void sort(Edge arr[],int start,int end){
	int i;
	if(start<end){
		i=fun(arr,start,end);
		sort(arr,start,i-1);
		sort(arr,i+1,end);
	}
}

int main(){
	Edge E[maxsize];
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d %d %d",&E[i].vex_start,&E[i].vex_end,&E[i].weight);
	sort(E,0,m-1);
	kruskal(E,n,m);
	return 0;
}
