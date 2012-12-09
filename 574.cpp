#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SZ 105

int S, N, con, vSz;
int a[SZ], res[SZ], seen[SZ];
vector<int> store[SZ*SZ+5], temp;

bool comp(int a, int b){
	return a>b;
}

int search(vector<int> v){
	int i;
	for(i=0; i<vSz; i++){
		if( v==store[i] )
			return 0;
	}
	return 1;
}

void BtKt(int S, int pos, int cur){
	if( S<0 )return;
	int i;
	if( !S ){
		temp.clear();
		for(i=0; i<pos; i++)
			temp.push_back(res[i]);
		if( search(temp) ){
			for(i=0; i<pos; i++){
				if( !i )printf("%d", res[i]);
				else printf("+%d", res[i]);
			}
			printf("\n");
			store[vSz] = temp;
			vSz++;
		}
		return;
	}
	for(i=cur; i<N; i++){
		res[pos] = a[i];
		BtKt(S-a[i], pos+1, i+1);
	}
}

int main(){
	freopen("574.txt", "r", stdin);
	int i;
	while( scanf("%d%d", &S, &N) ){
		if( !S && !N )break;
		for(i=0; i<N; i++){
			scanf("%d", &a[i]);
			seen[i] = 0;
		}
		vSz = 0;
		sort(a, a+N, comp);
		printf("Sums of %d:\n", S);
		BtKt(S, 0, 0);
		if( !vSz )puts("NONE");
	}
	return 0;
}