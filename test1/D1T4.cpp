#include<iostream>
#include<stack>
#include<cstdio>
#define d(x) cerr<<#x<<" = "<<x<<';'<<endl;
using namespace std; 
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        while(!s[0].empty())
        	s[0].pop();
        while(!s[1].empty())
        	s[1].pop();
        p=1;	
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(!p) cpy(0);
        s[1].push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int i=peek();
        s[0].pop();
        return i;
    }
    
    /** Get the front element. */
    int peek() {
    	if(p) cpy(1);
        return s[0].top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s[p].empty();
    }
    private:
    	stack<int> s[2];
    	int p;
    	void cpy(int i){
    		while(!s[i].empty()){
        	s[!i].push(s[i].top());
			s[i].pop(); 
			}
			p=!i;
		}
    	
};

int main(){
	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
	d(obj->pop()) 
	d(obj->peek())
	d(obj->empty())
	obj->push(5);
	d(obj->pop())
	d(obj->pop())
	d(obj->pop())
	d(obj->pop())
	d(obj->empty())
	return 0;
} 
