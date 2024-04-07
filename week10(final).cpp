#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=10001;
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
	bool operator ==(Point t)const{
		return x==t.x&&y==t.y;
	}
	bool operator <=(Point t)const{
		return x<t.x||x==t.x&&y<=t.y;
	}
	bool operator >=(Point t)const{
		return x>t.x||x==t.x&&y>=t.y;
	}
	friend Point operator +(Point i,Point j){
		return Point(i.x+j.x,i.y+j.y);
	}
	friend Point operator -(Point i,Point j){
		return Point(i.x-j.x,i.y-j.y);
	}
	friend int operator *(Point i,Point j){
		return i.x*j.x+i.y*j.y;
	}
};
template<class heap_entry>
class min_heap{
	public:
		min_heap(){
			clear();
		}
		bool empty()const{
			return n==0?true:false;
		}
		heap_entry top()const{
			return a[1];
		}
		void pop(){
			a[1]=a[n--];
			update_root();
		}
		void push(heap_entry i){
			a[++n]=i;
			update_leaf(n);
		}
		int size()const{
			return n;
		}
		void clear(){
			n=0;
			memset(a,0,sizeof(a));
		}
	private:
		int n;
		heap_entry a[MAXN];	
		void update_root(){
			int i=1,j=(n>=3&&a[3]<a[2])?3:2;
			while(j<=n&&a[i]>a[j]){
				swap(a[i],a[j]);
				i=j;
				j=2*i;
				if(j+1<=n&&a[j+1]<a[j]) j++;
			}
		}
		void update_leaf(int i){
			while(i&&a[i]<a[i/2]){
				swap(a[i],a[i/2]);
				i=i/2;
			}
		}
};
min_heap<Point>heap;
priority_queue<Point>max_heap;
int n,k;
void init(){
	freopen("a.in","r",stdin);
	cin>>n>>k;
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
	while(!max_heap.empty())
		max_heap.pop();
	for(int i=1;i<=n;i++){
		Point t;
		cin>>t.x>>t.y;
		if(i<=k){
			max_heap.push(t);
			continue;
		}
		if(t<max_heap.top()){
			max_heap.pop();
			max_heap.push(t);
		}
		queue<Point>q;	
		cout<<i<<":\n";
		for(int j=1;j<=k;j++){
			t=max_heap.top();
			t.print();
			q.push(t);
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
