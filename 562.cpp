#include<stdio.h>
#define SZ 50005

int can[SZ];
int coins[105];

void init(int T){
	int i;
	for(i=0; i<T; i++)
		can[i] = 0;
	can[0] = 1;
}

void coin_change(int N, int T){
	int i, j;
	for(i=0; i<N; i++){
		for(j=T; j>=1; j--){
			if( j-coins[i]<0 )continue;
			if( can[j-coins[i]] )
				can[j] = 1;
		}
	}
}

int ABS(int n){
	return (n<0)?-n:n;
}

int main(){
	freopen("562.txt", "r", stdin);
	int t, N, i, sum, avg;
	scanf("%d", &t);
	while( t-- ){
		scanf("%d", &N);
		sum = 0;
		for(i=0; i<N; i++){
			scanf("%d", &coins[i]);
			sum += coins[i];
		}
		avg = sum/2;
		init(sum);
		coin_change(N, avg);
		while( can[avg] == 0 && avg>=0 )avg--;
		sum = sum - avg;
		printf("%d\n", ABS(sum-avg));
	}
	return 0;
}