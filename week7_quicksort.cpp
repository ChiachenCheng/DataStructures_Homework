#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int MAXN=100001;
int a[MAXN]; 
int n;
void qsort(int l,int r){
	int i=l,j=r,x=a[(l+r)/2];
	while(i<=j){
		while(a[i]<x) i++;
		while(a[j]>x) j--;
		if(i<=j){
			int t=a[i];
			a[i++]=a[j];
			a[j--]=t;
		}
	}
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
}
void print(){
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=rand();
	print();
	qsort(1,n);
	print();
	return 0;
} 
