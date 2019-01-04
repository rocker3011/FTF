#include <bits/stdc++.h>
#define LL long long
//N = (ceil)((log(N) / log(2)) + 1)
//size = 1 << N optimal size for ST , if you use it sum 10 to it just in case there is an overflow

using namespace std;

int left (int p) {return (p<<1);}
 
int right (int p){return (p<<1)+1;}

struct Node{
	
	int pairs;
	int open;
	int closed;

	Node(){
		pairs=open=closed=0;
	}
};

Node st[3000100];

int n, q;
string x;

Node merge(Node l, Node r){
	Node p;
	int minmatch = min(l.open, r.closed);
	p.pairs = l.pairs + r.pairs + minmatch;
	p.open = l.open + r.open - minmatch;
	p.closed = l.closed + r.closed - minmatch;
	return p;
}

Node query(int node, int li, int ls, int i, int j){
	//if(lazy[node]) lazy_update(node, li, ls); //remove for no lazy
	if(i>ls || j<li){ Node x; x.pairs=x.open=x.closed=0;}
	if(li>=i && ls<=j) return st[node];
	int mid = (li+ls)/2;
	Node left = query(2*node, li, mid, i, j);
	Node right = query(2*node+1, mid+1, ls, i, j);
	return merge(st[node*2],st[node*2+1]);
}

void update(int node, int li, int ls, int i, int j, int val){ //Simple , node (node of the tree), i (current floor) , j (current ceiling), li(start of st) , ls(en of st), val(value to be added)
	//if(lazy[node]) lazy_update(node, li, ls); //remove for no lazy
	if(i>ls || j<li) return;
	if(ls==li){
		if(val==-1){
			st[node].open=0;
			st[node].closed=1;
		}else{
			st[node].open=1;
			st[node].closed=0;
		}
		return;
	}

	int mid = (li+ls)/2;
	update(2*node, li, mid, i, j, val);
	update(2*node+1, mid+1, ls, i, j, val);
	st[node] = merge(st[node*2],st[node*2+1]);
}

void construct(int node, int li,int ls){
	if(li==ls){
		
		st[node].pairs = 0;
		if(x[li]=='('){
			st[node].open = 1;
			st[node].closed=0;
		}else{
			st[node].open = 0;
			st[node].closed=1;
		}
		return ;
	}

	int mid = (li+ls)/2;
	construct(node*2,li,mid);
	construct(node*2+1,mid+1,ls);
	st[node] = merge(st[node*2],st[node*2+1]);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin>>n;
    cin>>x;
    construct(1,0,n-1);
    int cont=0;
    for(int i=0;i<n;++i){

    	if(x[i]=='('){

    		update(1,0,n-1,i,i,-1);
    		Node node =query(1,0,n-1,0,n-1);
    		//cout<<node.pairs<<endl;
    		if(node.open==0 && node.closed==0){
    			cont++;
    		}
    		update(1,0,n-1,i,i,1);
    	}else{
    		update(1,0,n-1,i,i,1);
    		Node node =query(1,0,n-1,0,n-1);
    		//cout<<node.pairs<<endl;
    		if(node.open==0 && node.closed==0){
    			cont++;
    		}
    		update(1,0,n-1,i,i,-1);
    	}



    }

    cout<<cont<<'\n';

	
	return 0;
}
