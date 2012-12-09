#pragma warning(disable : 4786)
#include<stdio.h>
#include<math.h>
#include<set>
using namespace std;
typedef long long int lld;
#define SZ 100005

lld sqr[100005];
set<lld> S;
set<lld>::iterator it;


void init(){
	int i;
	for(i=1; i<SZ; i++){
		sqr[i] = i*i;
	}
}



int main(){
	init();
	int t, cs, i;
	lld N, X;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%lld", &N);
		S.clear();
		for(i=1; sqr[i]<=N, i<SZ-4; i++){
			X = N - sqr[i];
			if( X<=0 )break;
			if( !(X%i) )
				S.insert(X);
		}
		printf("Case %d:", cs);
		for (it=S.begin(); it!=S.end(); it++){
			printf(" %lld", *it);
		}
		printf("\n");
	}
	return 0;
}