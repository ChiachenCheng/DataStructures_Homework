#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;
const int maxn=10001;
struct ListNode 
{
    int  value; 
    ListNode*  next;
};
class List{
	public:
		List(){
			clear();
		}
		void clear(){
			memset(pool,0,sizeof(pool));
			n=0;
			prehead=&(pool[0]);
			prehead->value=0x80000000;
			memset(pool,0,sizeof(pool));
		}
		ListNode* insert(int i){
			ListNode *p=newnode();
			p->value=i;
			for(ListNode *j=prehead;j!=NULL;j=j->next)
				if((j->next==NULL)||(j->next->value>=i&&j->value<=i)){
					p->next=j->next;
					j->next=p;
					break;
				}
			return p;	
		}
		void print(){
			for(ListNode *j=prehead->next;j!=NULL;j=j->next)
				printf("%d ",j->value);
		}
		ListNode *start(){
			return prehead;
		}
		ListNode *next(ListNode *p){
			return p->next;
		}
	private:	
		ListNode pool[maxn];
		int n;
		ListNode *prehead;
		ListNode *newnode(){
			return &(pool[++n]);
		}
}l[2];
void merge(List s,List t){
	ListNode *i,*j=t.next(t.start());
	for(i=s.start();j!=NULL;){
		s.insert(j->value);
		j=t.next(j);
	}
}
int main(){
	freopen("2.txt","r",stdin);
	string line;
	while(getline(cin,line)){
		l[0].clear();
		l[1].clear();
		stringstream s,t;
		s<<line;
		int x;
		while(s>>x)
			l[0].insert(x);
		getline(cin,line);
		t<<line;
		while(t>>x)
			l[1].insert(x);
		for(ListNode *j=l[1].next(l[1].start());j!=NULL;j=l[1].next(j))
			l[0].insert(j->value);
		l[0].print();
		printf("\n");
		getline(cin,line);
	}	
	return 0;
}
