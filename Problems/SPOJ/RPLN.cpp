#include <bits/stdc++.h>

using namespace std;


int st[1<<((int)ceil((log(100000)/log(2)))+3)+5];
int arr[100010];


int left (int p) {return (p<<1);}
 
int right (int p){return (p<<1)+1;}


int constructST(int node,int li, int ls){
    if(li==ls){
        st[node] = arr[li];
        return st[node];
    }else{
        int mid = (ls+li)/2;
        int l = constructST(left(node),li,mid);
        int r = constructST(right(node),mid+1,ls);
        st[node] = min(l,r);
        return st[node];
    }
}

int query(int node, int i, int j, int li, int ls){
    if(i>ls || j<li) return 0x3f3f3f3f;
    if(i>=li && j<=ls){
        return st[node];
    }
    int mid = (i+j)/2;
    int l = query(left(node),i,mid,li,ls);
    int r = query(right(node),mid+1,j,li,ls);
    return min(l,r);
}

int main(){
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas){
        printf("Scenario #%d:\n",cas);
        int n,q;
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        constructST(1,0,n-1);
        while(q--){
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",query(1,0,n-1,a-1,b-1));
        }
    }
    return 0;
}