#include<iostream>
#include<cstdio>
#include<queue>
#define d(x) cerr<<#x<<" = "<<x<<';'<<endl;
using namespace std;
class MovingAverage {
public:
    MovingAverage(int i) {
    	while(!q.empty())
    		q.pop();
    	size=i;
    	sum=0.0;	
    }
    double next(int val) {
    	q.push(val);
    	sum+=val;
    	if(size<q.size()){
    		sum-=q.front();
    		q.pop();
		}
    	return sum/q.size();
    }
private:
    queue<int> q;
    int size;
    double sum;
};

int main(){
	MovingAverage m(4);
	d(m.next(11))// = 1
	d(m.next(25))// = (1 + 10) / 2
	d(m.next(39))// = (1 + 10 + 3) / 3
	d(m.next(66))// = (10 + 3 + 5) / 3
	d(m.next(75))
	d(m.next(32))
	return 0;
}
