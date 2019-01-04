int Find(int x){
	if(x==p[x]) return x;

	return p[x] = Find(p[x]);
}

void Union(int x,int y){
	x = Find(x);
	y = Find(y);

	if(tam[x] < tam[y]){
		swap(x,y);
	}

	p[y] = x;
	tam[x] = tam[x] + tam[y];
}