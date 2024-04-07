#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
	public:
		Node(int v,Node* pt){
			value=v;
			next=pt;
		};
		int value;
		Node* next; 
}; 
const Node zero(0,NULL);
class CirLinkedList{
	public:
		void insert(int i){
			Node* p=new Node(i,head);
			head=p;
		};
		CirLinkedList(int n){
			it=NULL;
			head=NULL;
		    insert(n);
			tail=head; 
		};
		~CirLinkedList(){
			delete head;
		}; 
		void circle(){
			tail->next=head;
		};
		void delnext(){
			Node* p=it->next; 
			it->next=p->next;
			if(head==p)
				head=p->next;
			//cout<<p->value<<' ';	
			delete p; 
		};
		Node* itstart(){
			it=head;	
		};
		Node* itnext(){
			it=it->next;
			return it;
		};
		void print(){
			cout<<head->value<<endl;
		};
	private:
		Node* head;
		Node* it;
		Node* tail;
};
int n,m;
int main(){
	cin>>n>>m;
	if(m==1){
		cout<<n<<endl;
		exit(0);
	} 
	CirLinkedList l(n);
	for(int i=n-1;i>0;i--)
		l.insert(i);
	l.circle();
	l.itstart();
	for(int i=n;i>1;i--){
		for(int j=2;j<m;j++)
			l.itnext();	
		l.delnext();
		l.itnext();	
	}
	l.print();
	delete &l;
	return 0;
}
