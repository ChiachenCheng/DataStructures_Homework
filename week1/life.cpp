#include "life.h"
#include<cstring>
#include<cstdlib>
life::life()
{
	srand(2333);
	int r;
	memset(grid,0,sizeof(grid));
	for(int i=1;i<=maxm;i++)
		for(int j=1;j<=maxn;j++)
			grid[i][j]=rand()%3?0:1;
}
void life::print(){
	for(int i=1;i<=maxm;i++){
		for(int j=1;j<=maxn;j++)
			cout<<grid[i][j];
		cout<<endl;	
	}
}
void life::update(){
	int a[maxm+2][maxn+2];
	memcpy(a,grid,sizeof(grid));
	for(int i=1;i<=maxm;i++)
		for(int j=1;j<=maxn;j++){
			int k=neighbor_count(i,j);
			if(grid[i][j]&&(k<2||k>3))
				a[i][j]=0;
			if(!grid[i][j]&&k==3)
				a[i][j]=1;
		}
	memcpy(grid,a,sizeof(a));
}
int life::neighbor_count(int i, int j){
	int s=0;
	for(int k=1;k<=8;k++)
		s+=grid[i+di[k]][j+dj[k]];
	return s;	 
}
