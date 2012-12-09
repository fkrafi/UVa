#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;

map<string, int> M;

struct storage{
	char name[100];
	int gain, spend;
}store[15];

void CLEAR( int n ){
	int i;
	for(i=0; i<=n; i++){
		store[i].gain = store[i].spend = 0;
	}
}

char s[1000],p[1000];

int main(){
	freopen("119.txt", "r", stdin);
	int n, i, j, prc, per, g, flag=0;
	while(scanf("%d", &n) != EOF){
		if(flag)printf("\n");
		flag = 1;
		for(i=1; i<=n; i++){
			scanf("%s", s);
			strcpy(store[i].name, s);
			M[string(s)] = i;
		}
		CLEAR(n);
		for(i=0; i<n; i++){
			scanf("%s%d%d", s, &prc, &per);
			if(!per)continue;
			g = prc%per;
			//store[ M[string(s)] ].gain += g;
			store[ M[string(s)] ].spend += prc - g;
			for(j=0; j<per; j++){
				scanf("%s", p);
				store[ M[string(p)] ].gain += prc/per;
			}
		}
		for(i=1; i<=n; i++){
			printf("%s %d\n", store[i].name, (store[i].gain-store[i].spend));
		}
		M.clear();
	}
	return 0;
}