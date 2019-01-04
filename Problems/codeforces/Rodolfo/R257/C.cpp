#include <bits/stdc++.h>

using namespace std;

bool memo[3][301];
int choice[201];
bool mark[3][201];

vector < pair <pair <int,string> ,int> > v;
vector <string> c;

set <int> prefijo;

bool check(string &x,string &y){

	for (int i=0;i<(int)x.size();++i){
		if (y[i]!=x[i]) return false;
	}
	return true;
}

bool check_s(string &x,string &y){
	int tamx = x.size()-1;
	int tamy = y.size()-1;
	
	while(tamx>=0){
		if(x[tamx]!=y[tamy]) return false;
		tamx--;
		tamy--;
	}
	
	return true;
}

bool dp(int cual, int idx , string &x, set <string> &s){
	
	if (idx>=(int)v.size()){
		vector <string> el;
		for (int i=0;i<v.size();++i){
			if(s.count(v[i].first.second)) continue;
			el.push_back(v[i].first.second);
			int tam = el.size();
			if (tam>1){
			
				if (!check_s(el[tam-2],el[tam-1])) return false;
			}
		}
		return true;
	}

	bool &best = memo[cual][idx];

	if (mark[cual][idx]) return best;

	mark[cual][idx] = true;

	best = false;
	bool a = true;
	bool b = true;
	if (idx!=0){
		string y = v[idx].first.second;
		if (!check(x,y)){
			a=false;
		}
	}
	if (a){
		s.insert(v[idx].first.second);
		best = best || dp(0,idx+2,v[idx].first.second,s);
		s.erase(s.find(v[idx].first.second));
		if(best){
			
			choice[idx] = 0;
			return best;
		}
	}
	if (idx!=0){
		string y = v[idx+1].first.second;
		if (!check(x,y)){
			b=false;
		}
	}
	if (b){
		s.insert(v[idx+1].first.second);
		best = best || dp(1,idx+2,v[idx+1].first.second,s);
		s.erase(s.find(v[idx+1].first.second));
		if (best){
			choice[idx]=1;
			return best;
		}
	}
	return best;
}

void path (int idx){
	if(idx>=(int)v.size()) return;

	if (choice[idx]==0){
		prefijo.insert(v[idx].second);
	}else{
		prefijo.insert(v[idx+1].second);
	}
	path(idx+2);
}


int main(){
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	bool valido=true;

	for (int i=0;i<2*n-2;++i){
		string x; cin>>x;
		v.push_back({{(int)x.size(),x},i});
		c.push_back(x);
	}

	sort(v.begin(),v.end());
	memset(mark,0,sizeof(mark));
	string dd = "";
	set <string> s;
	dp(0,0,dd,s);
	
	path(0);

	for (int i=0;i<c.size();++i){
		if(prefijo.count(i)){
			cout<<"P";
		}else{
			cout<<"S";
		}
	}
	cout<<'\n';

	return 0;
}