#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct edge{
	int a,b;
	double c;
};
edge edges[100005];
int p[105];
double x[100], y[100];

bool comp(edge A, edge B){
	return A.c < B.c;
}

int find_set(int u){
	if(u != p[u])
		return p[u] = find_set(p[u]);
	return p[u];
}

void link(int  a, int b){
	p[b]=a;
}

int main(){
	freopen("10034.txt", "r", stdin);
	int t, i, j, n, sz, a, b, flag=0;
	double ans;
	scanf("%d", &t);
	while(t--){
		if( flag )printf("\n");
		flag = 1;
		scanf("%d", &n);
		for(i=1; i<=n; i++){
			scanf("%lf%lf", &x[i], &y[i]);
		}
		sz = 0;
		for(i=1; i<=n; i++){
			for(j=i+1; j<=n; j++){
				edges[sz].a = i;
				edges[sz].b = j;
				edges[sz++].c = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
			}
		}
		sort(edges, edges+sz, comp);
		for(i=0; i<=n; i++)p[i]=i;
		ans = 0;
		for(i=0; i<sz; i++){
			a = find_set(edges[i].a);
			b = find_set(edges[i].b);
			if(a != b){
				ans += edges[i].c;
				link(a,b);
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}