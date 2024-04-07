#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct Point{
	int x,y;
	Point(){
		x=0;
		y=0;
	}
	Point(int i,int j){
		x=i;
		y=j;
	}
	void print(){
		cout<<x<<' '<<y<<endl;
	}
	bool operator <(Point t)const{
		return x<t.x||x==t.x&&y<t.y;
	}
	bool operator >(Point t)const{
		return x>t.x||x==t.x&&y>t.y;
	}
	void operator =(Point t){
		x=t.x;
		y=t.y;
	}
	friend Point operator +(Point i,Point j){
		return Point(i.x+j.x,i.y+j.y);
	}
};
priority_queue< Point,vector<Point>,greater<Point> >heap;
int n,k;
void init(){
	freopen("a.in","r",stdin);
	cin>>n>>k;
	while(!heap.empty())
		heap.pop();
	for(int i=1;i<=n;i++){
		Point t;
		cin>>t.x>>t.y;
		heap.push(t);
	}
	fclose(stdin);
}
void sortit(){
	for(int i=1;i<=n;i++){
		Point t=heap.top();
		t.print();
		heap.pop();
	}
}
void doit(){
	freopen("a.in","r",stdin);
	cin>>n>>k;
	while(!heap.empty())
		heap.pop();
	for(int i=1;i<=n;i++){
		Point t;
		cin>>t.x>>t.y;
		heap.push(t);
		if(heap.size()<k)
			continue;
		queue<Point>q;	
		cout<<i<<":\n";
		for(int j=1;j<=k;j++){
			Point t=heap.top();
			t.print();
			q.push(t);
			heap.pop();
		}	
		while(!heap.empty())
			heap.pop();
		for(int j=1;j<=k;j++){
			heap.push(q.front());
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
