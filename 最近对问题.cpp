#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int n;

struct point{
    int x;
	int y;
};

int cmp(point a ,point b){
    return a.y<b.y;
}

double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closest(point arry[],int low,int high){
    double d1,d2,d3,min_d;
    int i,j;
    int mid,index;
    
    point p[n];
    
    if(high-low == 1)
        return dist(arry[low],arry[high]);
       
    if(high-low == 2){
        d1 = dist(arry[low],arry[low+1]);
        d2 = dist(arry[low+1],arry[high]);
        d3 = dist(arry[low],arry[high]);
        if(d1<d2 && d1<d3)
            return d1;
        else{
            if(d2<d3)
                return d2;
            else
                return d3;
        }
    }
    else{
        mid = (low+high)/2;
        d1 = closest(arry,low,mid);
        d2 = closest(arry,mid+1,high);
        if(d1<d2)
            min_d = d1;
        else
            min_d = d2;
        index = 0;
        for(i=mid;i>=low && arry[i].x-arry[mid].x<min_d;i--)
            p[index++] = arry[i];
        for(j=mid+1;j<=high && arry[j].x-arry[mid].x<min_d;j++)
            p[index++] = arry[j];
        sort(p,p+index,cmp);
        for(i=0;i<index;i++){
            for(j=i+1;j<index;j++){
                if(p[j].y-p[i].y>=min_d)
                    break;
                else{
                    d3 = dist(p[j],p[i]);
                    if(d3<min_d)
                        min_d = d3;
                }
            }
        }
    }
    return min_d;
}

int main(){
    double min;
    point p[10010];
    cout<<"点的数量：";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"点的坐标：";
		cin>>p[i].x>>p[i].y;
    }
    min = closest(p,0,n-1);
    cout<<"最短距离为："<<fixed<<setprecision(2)<<min<<endl;

    return 0;
}



