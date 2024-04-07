#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1001;
struct tree_node{
	tree_node *ch[2];
	tree_node *f;
	char value;
};
void do_nothing(tree_node *r){};
class binary_tree{
	public:
		binary_tree(){
			memset(pool,0,sizeof(pool));
			pool_n=0;
			null=NULL;
			null=new_node('\0',null);
			null->ch[0]=null;
			null->ch[1]=null;
			root=null;
		};
		tree_node *build_postorder(char *s){
			int l=strlen(s)-1;
			root=new_node(s[l],null);
			build_post(root,s,l);
			return root;
		}
		void test(tree_node *r,int i){
			if(r==null) return;
			cout<<i<<' '<<r->value<<endl;
			test(r->ch[0],2*i);
			test(r->ch[1],2*i+1);
		}
		tree_node *find(tree_node *r,char c,void (*visit)(tree_node*))const{
			if(r==null)
				return r; 
			(*visit)(r);
			if(r->value==c){
				return r;
			}
			if(r->value>c)
				return find(r->ch[0],c,visit);
			else
				return find(r->ch[1],c,visit);
		}
		void del(char c){
			del(find(root,c,do_nothing));
		};
		void del(tree_node *p){
			short j=(p->f->ch[0]==p)?0:1,k=(p->ch[0]==null)?1:0;
			if(p!=root&&(p->ch[0]==null||p->ch[1]==null)){
				p->f->ch[j]=p->ch[k];
				delete_node(p);
				return;
			}
			tree_node *t=p->ch[k];
			while(t->ch[!k]!=null)
				t=t->ch[!k];
			swap(t->value,p->value);
			del(t);
		}
		tree_node *root;
	protected:
		tree_node *null;
		tree_node pool[MAXN];
		int pool_n;
		tree_node *new_node(char c,tree_node *fa){
			tree_node *p=&pool[++pool_n];
			p->ch[0]=null;
			p->ch[1]=null;
			p->f=fa;
			p->value=c;
			return p;
		};
		void build_post(tree_node *r,char *s,int &i){
			for(int k=1;k>=0;k--)
				if(i>0&&s[--i]!='#'){
					r->ch[k]=new_node(s[i],r); 
					build_post(r->ch[k],s,i);
				}
		};
		void delete_node(tree_node *t){
			t->ch[0]=null;
			t->ch[1]=null;
			t->f=null;
			t->value='\0';
		}
};
void print(tree_node *r){
		cout<<r->value<<' ';
	}		
int main(){
	binary_tree t;
	char str[]="###ca##ji####spom";
	t.build_postorder(str);
	t.test(t.root,1);
	t.find(t.root,'c',print);
	cout<<endl;
	t.del('m');
	t.test(t.root,1);
	t.del('p');
	t.test(t.root,1);
	return 0;
} 
