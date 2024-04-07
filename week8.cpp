#include<iostream>
#include<cstdio>
#include<map>
using namespace std; 
map<int,int>hash;
int a[10001];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		hash[a[i]]=i;
	}
	int s;
	while(m--){
		cin>>s;
		for(int j=1;j<=n;j++)
			if(2*a[j]<s&&hash[s-a[j]]!=0)
				printf("%d: %d %d\n",s,j,hash[s-a[j]]);
	}
	return 0;
}
