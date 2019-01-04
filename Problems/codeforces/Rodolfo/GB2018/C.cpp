#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=0;i<j;i+=k)
#define first f
#define second s
#define pb push_back

using namespace std;

typedef pair<int,int> PII;

/*bool memo[35][100010];
int choice[100010];
bool mark[35][100010];

bool dp(int w, int k, int n){
	cout<<n<<" "<<k<<endl;
	if(n==0 && k==0)
		return true;

	bool &best = memo[w][k];
	if(mark[w][k]) return best;
	mark[w][k]=true;
	best=false;

	for(int i=0;i<=30;++i){
		if(n-(1<<i)<0) continue;
		if(k-1==0 && n-(i<<i)!=0) continue;
		best = best || dp(i,k-1,n-(1<<i));
		if(best){
			choice[k]=i;
			break;
		}
	}

	return best;
}

void print_path(int w,int k, int n){
	if(k==0) return;
	cout<<(1<<choice[k])<<" ";
	print_path(choice[k],k-1,n-(1<<choice[k]));
}*/

bool check(long long n) 
{ 
   return (ceil(log2(n)) == floor(log2(n))); 
} 

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n;
	long long k;
	cin>>n>>k;
	multiset <long long> ms;
	for(int i=0;i<=30;++i){
		if(n & (1<<i)){
			ms.insert(1<<i);
		}
	}

	if(ms.size()>k || k>n){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		while(ms.size()<k){
			for(int i=1;i<=30;++i){
				if(ms.size()==k) break;
				if(ms.count(1<<i)){
					ms.insert((1<<i)/2);
					ms.insert((1<<i)/2);
					ms.erase(ms.find(1<<i));
				}
			}
		}

		multiset <long long> :: iterator it;
		for(it=ms.begin();it!=ms.end();it++){
			cout<<(*it)<<' ';
		}
	}

	
	return 0;
}