#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > >heap;
priority_queue< pair<int,int> >max_heap;
int n,k;
void printp(pair<int,int>t){
	cout<<t.first<<' '<<t.second<<endl;
}
void init(){
	freopen("a.in","r",stdin);
	cin>>n>>k;
	while(!heap.empty())
		heap.pop();
	for(int i=1;i<=n;i++){
		pair<int,int>t;
		cin>>t.first>>t.second;
		heap.push(t);
	}
	fclose(stdin);
}
void sortit(){
	for(int i=1;i<=n;i++){
		printp(heap.top());
		heap.pop();
	}
}
void doit(){
	freopen("a.in","r",stdin);
	cin>>n>>k;
	while(!max_heap.empty())
		max_heap.pop();
	for(int i=1;i<=n;i++){
		pair<int,int>t;
		cin>>t.first>>t.second;
		if(i<=k){
			max_heap.push(t);
			continue;
		}
		if(t<max_heap.top()){
			max_heap.pop();
			max_heap.push(t);
		}
		queue< pair<int,int> >q;	
		cout<<i<<":\n";
		for(int j=1;j<=k;j++){
			printp(max_heap.top());
			q.push(max_heap.top());
			max_heap.pop();
		}	
		for(int j=1;j<=k;j++){
			max_heap.push(q.front());
			q.pop();
		}
	}
	fclose(stdin);
}
int main(){
	init();
	sortit();
	doit();
	return 0;
} 
