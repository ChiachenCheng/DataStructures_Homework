#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1001;
struct tree_node{
	char value;
	tree_node *ch[2];
};
class binary_tree{
	public:
		binary_tree(){
			memset(pool,0,sizeof(pool));
			pool_n=0;
			null=NULL;
			null=new_node('\0');
			null->ch[0]=null;
			null->ch[1]=null;
			root=null;
		};
		tree_node *build_postorder(char *s){
			int l=strlen(s)-1;
			build_post(root,s,l);
			return root;
		}
		void test(tree_node *r,int i){
			if(r==null) return;
			cout<<i<<' '<<r->value<<endl;
			test(r->ch[0],2*i);
			test(r->ch[1],2*i+1);
		}
		tree_node *root;
	private:
		tree_node *null;
		tree_node pool[MAXN];
		int pool_n;
		tree_node *new_node(char c){
			tree_node *p=&pool[++pool_n];
			p->ch[0]=null;
			p->ch[1]=null;
			p->value=c;
			return p;
		};
		void build_post(tree_node *&r,char *s,int &i){
			r=new_node(s[i]);
			if(i==0) return;
			for(int k=1;k>=0;k--)
				if(s[--i]!='#')
					build_post(r->ch[k],s,i);
		};
};
int main(){
	binary_tree t;
	char str[]="###ca##ji####spom";
	t.build_postorder(str);
	t.test(t.root,1);
	return 0;
}
