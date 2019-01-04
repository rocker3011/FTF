#include <bits/stdc++.h>

using namespace std;
long long b[200050];
long long a[200050];

long long bs(long long lo, long long hi, long long val){
	long long hit=hi;
	long long lot=lo;
    while (lo < hi){ 
        long long mid = lo + (hi-lo+1LL)/2LL;
        	
        if(val-mid>hit){
        	lo=mid+1LL;
        }else if(val-mid<lot){
        	hi=mid-1LL;
        }else if(val-mid<=hit && val-mid>=lot){
        	lo=mid;
        }
    }
    
    return lo;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin>>n;
	n=n/2;
	for(int i=0;i<n;++i){
		cin>>b[i];
	}
	int an=2*n-1;
	a[0]=0;
	a[an]=b[0];
	for (int i=1;i<n;++i){
		long long res=bs(a[i-1],a[an],b[i]);
		an--;
		a[an]=res;
		a[i]=b[i]-res;	
	}

	for (int i=0;i<2*n;++i){
		cout<<a[i]<<" ";
	}
	//puts("");	
	
	return 0;
}