#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=100002;
char stack[MAXN];
string s,t;
void doit(string& s){
	int l=s.length(),top=0;
	memset(stack,0,sizeof(stack));
	for(int i=0;i<l;i++){
		if(s[i]!='#'){
			stack[top++]=s[i];
			continue;
		} 
		if(top) top--;
	} 
	stack[top]='\0';
	s=string(stack,stack+top);
}
int main(){
	cin>>s;
	cin>>t;
	doit(s);
	doit(t);
	printf(s==t?"true":"false");
	return 0;
} 
