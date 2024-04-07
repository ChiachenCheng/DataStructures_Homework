#include<iostream>
#include<cstdio>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* head=NULL; 
ListNode* tail=NULL;
ListNode* deleteDuplicates(ListNode* head){
	ListNode *i=head;
	ListNode *j=NULL;
	while(i!=NULL){
		int t=i->val;
		while(i->next!=NULL&&t==i->next->val){
			j=i->next;
			i->next=i->next->next; 
			delete j;
			j=NULL;
		}
		i=i->next;
	}
	return head;
} 
int main(){
	int i,n;
	cin>>n;
	if(!n){
		cout<<"None";
		return -1;
	} 
	scanf("%d",&i);
	head=new ListNode(i);
	tail=head;
	n--; 
	while(n--){
		cin>>i;
		tail->next=new ListNode(i);
		tail=tail->next;
	}
	head=deleteDuplicates(head);
	for(ListNode* j=head;j!=NULL;j=j->next)
		cout<<j->val<<' ';
	for(ListNode* j=head;j!=NULL;){
		head=j->next;
		delete j;
		j=head; 
	}
	head=NULL;
	tail=NULL;
	return 0;
} 
