#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
const int maxn=1001;
struct treenode{
	int value,d;
	treenode *ch[2];
	treenode *f;
}pool[maxn];
int n=0,si,sl;
int m1d;
string s;
treenode* root;
int read(){
	int j=0; 
	for(;si<sl;si++){
		if(s[si]=='#'){
			j=-1;
		}
		else if(s[si]==','||si>=sl){
			si++;
			return j;	
		}
		else if(isdigit(s[si]))
			j=10*j+(s[si]-48);
	}
	return -1;
}
treenode *newnode(){
	return &(pool[++n]);
}
void build(treenode *r){
	for(int k=0;k<2;k++){
		int i=read();
		if(i<0)
			r->ch[k]=NULL;
		else{
			r->ch[k]=newnode();
			r->ch[k]->value=i;
			r->ch[k]->f=r;
			build(r->ch[k]);
		}
	}
};
void init(){
	memset(pool,0,sizeof(pool));
	n=0;
	si=0;
	sl=s.size();
	root=newnode();
	root->value=read();
	root->d=root->value;
	root->f=&(pool[0]);
	build(root);
	m1d=-1;
}
int dfs(treenode *r){
	if(r==NULL)
		return 0;
	r->d=r->value+r->f->d;
	if((r->d)>m1d) m1d=(r->d);
	dfs(r->ch[0]);
	printf("%d ",r->value);
	dfs(r->ch[1]);
}
int main(){
	freopen("1.txt","r",stdin);
	while(getline(cin,s)){
		init();
		dfs(root);
		cout<<endl<<m1d<<endl;	
	}
	return 0;
}
