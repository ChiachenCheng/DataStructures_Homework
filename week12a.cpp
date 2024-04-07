#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mn=1001;
struct edge{
	int p,ne;
}e[10001];
int fsp[mn],q[mn];
bool b[mn];
int n,m;
void init(){
	freopen("a.in","r",stdin);
	cin>>n>>m;
	memset(fsp,0,sizeof(fsp));
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		e[2*i-1]=(edge){y,fsp[x]};
		fsp[x]=2*i-1;
		e[2*i]=(edge){x,fsp[y]};
		fsp[y]=2*i;
	}
}
void dfs(int i){
	b[i]=1;
	printf("%d ",i);
	for(int j=fsp[i];j;j=e[j].ne)
		if(!b[e[j].p])
			dfs(e[j].p);
}
void bfs(int s){
	int he=0,ti=1;
	q[1]=s;
	b[s]=1;
	while(he<ti){
		int i=q[++he];
		printf("%d ",i);
		for(int j=fsp[i];j;j=e[j].ne)
			if(!b[e[j].p]){
				q[++ti]=e[j].p;
				b[e[j].p]=1;
			}
	}	
}
int main(){
	init();
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
		if(!b[i])
			dfs(i);
	cout<<endl;		
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
		if(!b[i])
			bfs(i);
	cout<<endl;			
	return 0;
} 
