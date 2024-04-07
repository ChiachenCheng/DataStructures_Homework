#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=100001;
const int ten[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
struct bucket{
	int v,ne;
}b[MAXN];
int a[MAXN];
int p[10];
int n,m=0;
int getbit(int i,int k){
	return (i%ten[k])/ten[k-1];
}
void init(){
	scanf("%d",&n);
	int j=0; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		j=max(j,a[i]);
	}
	for(int i=1;i<=8;i++)
		if(j>ten[i]) m=i;
	m++;	
}
void radix_sort_MSD(int m,int l,int r){
	bucket b[n+1];
	int p[10];
	memset(b,0,sizeof(b));
	memset(p,0,sizeof(p));
	for(int i=l;i<=r;i++){
		int j=getbit(a[i],m);
		b[i]=(bucket){a[i],p[j]};
		p[j]=i;
	}
	int nl=r,nr=r;
	for(int k=9;k>=0;k--){
		for(int j=p[k];j;j=b[j].ne)
			a[nl--]=b[j].v;
	}
	nl=r;
	for(int k=9;k>=0;k--){
		for(int j=p[k];j;nl--,j=b[j].ne);
		if(nl+1<nr&&m>1)
			radix_sort_MSD(m-1,nl+1,nr);
		nr=nl;	
	}
}
void print(){
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
int main(){
	init();
	radix_sort_MSD(m,1,n);
	print();
	return 0;
} 
