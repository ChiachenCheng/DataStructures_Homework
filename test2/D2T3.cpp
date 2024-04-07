#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;
const int maxn=101;
const int maxm=10001;
map<string,int>mp;
struct edge{
	int p,ne;
}e[maxm];
int fsp[maxn],q[maxn];
bool b[maxn];
int n,m;
string s[maxn];
void initn(){
	memset(e,0,sizeof(e));
	memset(fsp,0,sizeof(fsp));
	mp={};
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
		mp[s[i]]=i;
}
void initm(){
	pair<int,int>p[maxm];
	string r,t;
	for(int i=1;i<=m;i++){
		cin>>r>>t;
		p[2*i-1].first=mp[r];
		p[2*i-1].second=-mp[t];
		p[2*i].first=mp[t];
		p[2*i].second=-mp[r];
	}
	sort(p+1,p+m*2+1);
	for(int i=1;i<=2*m;i++){
		e[i]=(edge){-p[i].second,fsp[p[i].first]};
		fsp[p[i].first]=i;
	}
}
void test(){
	for(int i=1;i<=n;i++){
		cout<<s[i]<<' ';
		for(int j=fsp[i];j;j=e[j].ne)
			cout<<s[e[j].p]<<' ';
		cout<<endl;	
	}
	cout<<endl;
}
void dfs(int i){
	b[i]=1;
	cout<<s[i]<<' ';
	for(int j=fsp[i];j;j=e[j].ne)
		if(!b[e[j].p])
			dfs(e[j].p);
}
void bfs(int sp){
	int he=0,ti=1;
	q[1]=sp;
	b[sp]=1;
	while(he<ti){
		int i=q[++he];
		cout<<s[i]<<' ';
		for(int j=fsp[i];j;j=e[j].ne)
			if(!b[e[j].p]){
				q[++ti]=e[j].p;
				b[e[j].p]=1;
			}
	}
	cout<<endl;	
}
int main(){
	freopen("3.txt","r",stdin);
	while(cin>>n>>m){ 
		initn();
		initm();
		test();
		string line;
		getline(cin,line);
		getline(cin,line);
		while(1){
			if(!getline(cin,line))
				break;
			stringstream temp;
			temp.str("");
			string t;
			temp<<line;
			if(temp>>t){
				if(mp[t]==0){
					printf("-1\n");
					continue;	
				}
				else{
					memset(b,false,sizeof(b));
					bfs(mp[t]);
					memset(b,false,sizeof(b));
					dfs(mp[t]);
					cout<<endl;
				}
			}
			else
				break;
		}
		cout<<endl;
	}
	return 0;
} 
