#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
	public:
		void Nodeit(int v,Node* pt){
			value=v;
			next=pt;
		};
		int value;
		Node* next; 
}; 
int n,m;
int main(){
	cin>>n>>m;
	Node* firpt=(Node*)calloc(n+1,sizeof(Node));
	Node* p=firpt;
	for(int i=1;i<=n;i++){
		(*p).Nodeit(i,p+1);
		p++; 
	}
	p--;
	(*p).next=firpt;
	p=firpt;
	for(;n>1;n--){
		for(int i=2;i<m;i++)
			p=(*p).next;
		Node* j=(*((*p).next)).next;
		(*p).next=j;
		p=(*p).next;
	}
	cout<<(*p).value<<endl;
	free(firpt);
	return 0;
}
