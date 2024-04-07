#include "life.h"
life cell;
int main(int argc, char** argv) {
	int T=10,x=0;
	while(T--){
		cout<<"After "<<x++<<" second"<<endl;
		cell.print();
		cell.update();
	}
	return 0;
}
