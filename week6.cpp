#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int a[MAXN];
int n;
int bs_u_r(int l,int r,int t){//binary_search_upper_recursion(l,r,t)
	if(l==r)
		return l;
	int mid=(l+r+1)/2;
	if(a[mid]<=t) 
		return bs_u_r(mid,r,t);
	else 
		return bs_u_r(l,mid-1,t);
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
void binary_search_loop(int t){
	int lower,upper;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>=t) r=mid;
		else l=mid+1;
	}
	lower=l;
	/*while(l<r){
	 *	int mid=(l+r+1)/2;
	 *	if(a[mid]<=t) l=mid;
	 *	else r=mid-1;
	 *}
	 */ 
	upper=bs_u_r(1,n,t);
	cout<<lower<<' '<<upper<<endl;
}
int main(){
	init();
	int T,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&t);
		binary_search_loop(t);
	}
	return 0;
}
