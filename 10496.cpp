#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;


int R, C, N;
pii P[15];

int ABS(int n){
	return (n<0)?-n:n;
}

int dis(int i, int j){
	return ( ABS(P[i].first-P[j].first) + ABS(P[i].second-P[j].second) );
}

int MIN(int a, int b){
	return (a<b)?a:b;
}

int dp(int mask, int in){
	if( mask==(1<<N)-1 ){
		return dis(in, 0);
	}
	int i, ret=999999999;
	for(i=0; i<N; i++){
		if( mask&(1<<i) )continue;
		ret = MIN(ret, dp(mask|(1<<i), i+1) + dis(in, i+1));
	}
	return ret;
}

int main(){
	freopen("10496.txt", "r", stdin);
	int T, i;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &R, &C);
		scanf("%d%d", &P[0].first, &P[0].second);
		scanf("%d", &N);
		for(i=1; i<=N; i++){
			scanf("%d%d", &P[i].first, &P[i].second);
		}
		printf("The shortest path has length %d\n", dp(0, 0));
	}
	return 0;
}