#ifndef LIFE_H
#define LIFE_H
#include <iostream>
using namespace std;
const int maxm=20,maxn=60;   
const int di[9]={0,1,0,-1,0,1,1,-1,-1};
const int dj[9]={0,0,1,0,-1,1,-1,1,-1};
class life
{
	public:
		life();
		void print(); 
		void update();
	private:
		int grid[maxm+2][maxn+2];  
   		int neighbor_count(int i, int j);
};
#endif
