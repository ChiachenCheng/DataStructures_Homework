#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100001;
struct bucket{
	int v,ne;
}b[MAXN];
char a[256][MAXN];
int l[MAXN];
int p[27];
int r[MAXN];
int n,m=0;
int getbit(int i,int k){
	return k>=l[i]?96:a[i][k];
}
void init(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]);
		l[i]=strlen(a[i]); 
		m=max(m,l[i]);
	}
	for(int i=1;i<=n;i++)
		r[i]=i;
}
void print(){
	for(int i=1;i<=n;i++)
		printf("%s\n",a[r[i]]);
}
void radix_sort_string(){
	for(int k=m-1;k>=0;k--){
		memset(b,0,sizeof(b));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			int j=getbit(r[i],k)-96;
			b[i]=(bucket){r[i],p[j]};
			p[j]=i;
		}
		int i=n;
		for(int l=26;l>=0;l--)
			for(int j=p[l];j;j=b[j].ne)
				r[i--]=b[j].v;
	}
}
int main(){
	init();
	radix_sort_string();
	print();
	return 0;
} 
