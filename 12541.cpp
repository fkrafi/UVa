#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct storage{
	char s[20];
	int d, m, y;
}db[105];


bool comp(struct storage a, struct storage b){
	if( a.y==b.y ){
		if( a.m==b.m ){
			return a.d<b.d;
		}
		return a.m<b.m;
	}
	return a.y<b.y;
}

int main(){
	freopen("12541.txt", "r", stdin);
	int N, i;
	while( scanf("%d", &N) != EOF ){
		for(i=0; i<N; i++){
			scanf("%s%d%d%d", db[i].s, &db[i].d, &db[i].m, &db[i].y);
		}
		sort(db, db+N, comp);
		printf("%s\n%s\n", db[N-1].s, db[0].s);
	}
	return 0;
}