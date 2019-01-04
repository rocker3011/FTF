#include <bits/stdc++.h>
#define LL long long
//N = (ceil)((log(N) / log(2)) + 1)
//size = 1 << N optimal size for ST , if you use it sum 10 to it just in case there is an overflow

using namespace std;

int left (int p) {return (p<<1);}
 
int right (int p){return (p<<1)+1;}

LL st[300010];
LL lazy[300010];
int n, q;
//Example uses HORRIBLE for lazy updates however simple changes can be made to not use lazy updates
void lazy_update(int node, int li, int ls){
	st[node]+=(LL)(ls-li+1)*lazy[node];
	if(li!=ls){
		lazy[2*node]+=lazy[node];
		lazy[2*node+1]+=lazy[node];
	}
	lazy[node] = 0LL;
}

LL query(int node, int li, int ls, int i, int j){
	if(lazy[node]) lazy_update(node, li, ls); //remove for no lazy
	if(i>ls || j<li) return 0LL;
	if(li>=i && ls<=j) return st[node];
	int mid = (li+ls)/2;
	LL left = query(2*node, li, mid, i, j);
	LL right = query(2*node+1, mid+1, ls, i, j);
	return left+right;
}

void update(int node, int li, int ls, int i, int j, LL val){ //Simple , node (node of the tree), i (current floor) , j (current ceiling), li(start of st) , ls(en of st), val(value to be added)
	if(lazy[node]) lazy_update(node, li, ls); //remove for no lazy
	if(i>ls || j<li) return;
	if(li>=i && ls<=j){	// change to no lazy update, if(li==ls) then is a leaf st[node]+=val;
		st[node]+=(LL)(ls-li+1)*val;
		if(li!=ls){
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return;
	}
	int mid = (li+ls)/2;
	update(2*node, li, mid, i, j, val);
	update(2*node+1, mid+1, ls, i, j, val);
	st[node] = st[2*node]+st[2*node+1];
}