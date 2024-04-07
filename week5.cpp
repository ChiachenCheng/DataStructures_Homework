#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10000;
struct Node{
	int w,ne;
};
class List{
	public:
		List(){
			memset(a,0,sizeof(a));
			n=0;
			fsp=0;
		};
		~List(){};
		virtual int insert(const int i){
			return push_head(i);		
		};
		int find(const int i)const{
			for(int j=fsp;j;j=a[j].ne)
				if(a[j].w==i)
					return j;
			return 0;		
		};
		void print()const{
			for(int j=fsp;j;j=a[j].ne)
				cout<<a[j].w<<' '; 
			cout<<endl;	
			return;
		}
		Node itstart()const{
			return a[fsp];
		}
		bool itnext(Node& i){
			bool b=!(i.ne)?false:true;
			i=a[i.ne];
			return b;
		}
	protected:
		Node a[MAXN+1];
		int n,fsp;
		int push_head(const int i){
			int j;
			a[++n].w=i;
			a[n].ne=fsp;
			fsp=n;
			return n;		
		};
};
class OrderedList: public List{
	public:
		int insert(const int i){
			if(!n||i<=a[fsp].w)
				return push_head(i);
			int j; 
			for(j=fsp;(a[a[j].ne].w<i)&&a[j].ne;j=a[j].ne);
			a[++n].w=i;
			a[n].ne=a[j].ne;
			a[j].ne=n;
			return n;
		};
	private:
};
int listinsert(List &l,int i){
	return l.insert(i);
} 
int main(){
	freopen("w5.in","r",stdin);
	List l;
	int n,m,x; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		listinsert(l,x);
	}
	l.print();
	for(int i=1;i<=m;i++){
		cin>>x;
		cout<<l.find(x)<<endl;
	}
	OrderedList ol;
	Node ni=l.itstart();
	do{
		listinsert(ol,ni.w);
	}while(l.itnext(ni));
	ol.print();
	for(int i=1;i<=m;i++){
		cin>>x;
		cout<<ol.find(x)<<endl;
	}
	return 0;
} 
