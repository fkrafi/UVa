#pragma warning(disable : 4786)
#include<stdio.h>
#include<algorithm>
using namespace std;

struct storage{
	int u, v;
}a[500005];

bool comp(struct storage a, struct storage b){
	if( a.u == b.u )
		return a.v < b.v;
	return a.u < b.u;
}

int chk(int n){
	int i;
	for(i=0; i<n; i+=2){
		if( a[i].u!=a[i+1].u || a[i].v!=a[i+1].v )
			return 0;
	}
	return 1;
}

int main(){
	freopen("10763.txt", "r", stdin);
	int n, u, v, i, con;
	while( scanf("%d", &n) ){
		if( !n )break;
		for(i=0; i<n; i++){
			scanf("%d%d", &u, &v);
			if(u<v){
				a[i].u = u;
				a[i].v = v;
			}else{
				a[i].u = v;
				a[i].v = u;
			}
		}
		sort(a, a+n, comp);
		con = chk(n);
		if(con)puts("YES");
		else puts("NO");
	}
	return 0;
}