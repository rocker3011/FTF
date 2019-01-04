#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
vector <int> tree[MAXN]; //arbol
vector <int> centroidTree[MAXN]; //arbol de centroides como raiz
bool centroidMarked[MAXN]; //es o no centroide
bool visited[MAXN]; // esta o no visitado
int subtree_size[MAXN]; //tamaño subárbol
bool addedCentroidTree[MAXN]; //agregado al arbol de centroides

void addEdge(int u, int v){
	tree[u].push_back(v);
	tree[v].push_back(u);
}

void DFS(int src,int &n){ //DFS que calcula los tama;os de los subarboles
	visited[src]=true;
	n++;
	subtree_size[src]=1;
	addedCentroidTree[src]=true;
	vector <int> :: iterator it;

	for (it=tree[src].begin();it!=tree[src].end();it++){
		if(!visited[*it] && !centroidMarked[*it]){
			DFS(*it,n);
			subtree_size[src]+=subtree_size[*it];
		}
	}
}

int getCentroid(int src,int n){ //DFS que determina el centroide del arbol
	bool is_centroid = true;
	visited[src]=true;
	int heaviest_child = 0;
	vector <int> ::iterator it;

	for(it=tree[src].begin();it!=tree[src].end();it++){
		if(!visited[*it] && !centroidMarked[*it]){
			//si cualquier nodo adyacente tiene mas de n/2 nodos
			//el nodo actual no puede ser centroide

			if(subtree_size[*it]>n/2)
				is_centroid=false;

			//actualizar el hijo mas pesado
			if(heaviest_child==0 || 
				subtree_size[*it]>subtree_size[heaviest_child]){
					heaviest_child = *it;
			}
		}
	}

	//si nodo actual es un centroide LISTO

	if (is_centroid && n-subtree_size[src]<=n/2)
		return src;

	//sino entonces seguimos buscando por el hijo mas pesado

	return getCentroid(heaviest_child,n);
}

// esta funcion llama a ambas funciones DFS y getCentroid para determinar el centroide
// en O(Nlog(N));

int getCentroidInit(int src){
	memset(visited,false,sizeof(visited));
	memset(subtree_size,0,sizeof(subtree_size));

	int n=0;

	DFS(src,n);

	memset(visited,false,sizeof(visited));

	int centroid = getCentroid(src,n);

	centroidMarked[centroid]=true;

	return centroid;
}

int decomposeTree(int root){
	int cend_tree = getCentroidInit(root);

	vector <int> :: iterator it;

	for (it=tree[cend_tree].begin();it!=tree[cend_tree].end();it++){
		if(!centroidMarked[*it]){
			int cend_subtree=decomposeTree(*it);
			centroidTree[cend_tree].push_back(cend_subtree);
			centroidTree[cend_subtree].push_back(cend_tree);
		}
	}

	return cend_tree;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		addEdge(x,y);
	}

	decomposeTree(1);
	vector <int> :: iterator it;
	for (int i=1;i<=n;++i){
		printf("ADYACENCIAS DE %d\n",i);
		for (it=centroidTree[i].begin();it!=centroidTree[i].end();it++){
			printf("%d\n",*it);
		}
	}
}