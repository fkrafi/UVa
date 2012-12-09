#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define SZ 755
#define INF 999999999
typedef pair<double, double> pdd;
typedef pair<int, int> pii;


int nB, nC, nE;
pdd bPos[SZ];
int p[SZ], rank[SZ];
vector<pii> A;

struct graph{
	int u, v;
	double c;
}edges[SZ*SZ+5];

void make_set(int x){
	p[x] = x;
	rank[x] = 0;
}


int find_set(int x){
	if( x != p[x] )
		p[x] = find_set(p[x]);
	return p[x];
}

void link(int x, int y){
	if( rank[x] > rank[y] ){
		p[y] = x;
	}else{
		p[x] = y;
		if( rank[x] == rank[y] )
			rank[y]++;
	}
}

void Union(int x, int y){
	link(find_set(x), find_set(y));
}


bool comp( graph a, graph b ){
	return a.c<b.c;
}

double MSTKruskal(){
	int i;
	double ret=0;
	pii node;
	for(i=0; i<nE; i++){
		node.first = edges[i].u;
		node.second= edges[i].v;
		if( find_set(node.first) != find_set(node.second) ){
			A.push_back(node);
			ret += edges[i].c;
			Union(node.first, node.second);
		}
	}
	return ret;
}

void gen_cost(){
	int u, v, i;
	double a, b;
	A.clear();
	for(i=1; i<=nB; i++)
		make_set(i);
	for(i=0; i<nC; i++){
		scanf("%d%d", &u, &v);
		A.push_back(pii(u, v));
		Union(u, v);
	}
	nE = 0;
	for(u=1; u<=nB; u++){
		for(v=u+1; v<=nB; v++){
			a = bPos[u].first - bPos[v].first;
			b = bPos[u].second - bPos[v].second;
			edges[nE].u = u;
			edges[nE].v = v;
			edges[nE].c = sqrt( a*a + b*b );
			nE++;
		}
	}
}

int main(){
	freopen("10397.txt", "r", stdin);
	int i;
	while( scanf("%d", &nB) != EOF ){
		for(i=1; i<=nB; i++){
			scanf("%lf%lf", &bPos[i].first, &bPos[i].second);
		}
		scanf("%d", &nC);
		gen_cost();
		sort(edges, edges+nE, comp);
		printf("%.2lf\n", MSTKruskal());
	}
	return 0;
}