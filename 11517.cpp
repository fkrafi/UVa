#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int cs;
int coins[105];
int can[100000];
int cnt[100000];


int MIN(int a, int b){
	return (a<b)?a:b;
}

int main(){
	int t, m, i, N, S, j;
	scanf("%d", &t);
	while( t-- ){
		scanf("%d", &S);
		scanf("%d", &N);
		m = -1;
		for(i=0; i<N; i++){
			scanf("%d", &coins[i]);
			if( m<coins[i] )
				m = coins[i];
		}
		sort(coins, coins+N);
		m += S;
		memset(can, 0, sizeof(can));
		memset(cnt, 999999, sizeof(cnt));
		can[0] = 1;
		cnt[0] = 0;
		for(j=0; j<N; j++){
			for(i=m; i>=0; i--){
				if( i-coins[j] < 0 )continue;
				if( can[i-coins[j]] ){
					can[i] = 1;
					cnt[i] = MIN(cnt[i], cnt[i-coins[j]]+1);
				}
			}
		}
		while( can[S] != 1 )S++;
		printf("%d %d\n", S, cnt[S]);
	}
	return 0;
}
