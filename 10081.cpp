#include<stdio.h>

double mem[15][105][15];

int ABS(int n){ return (n<0)?-n:n; }

void CLEAR(int k, int n){
	for(int i=0; i<=k; i++)
		for(int j=0; j<=n; j++)
			for(int l=0; l<=k; l++)
				mem[i][j][l] = -1;
}

double dp(int k, int n, int last){
	if( !n )return 1;
	int i;
	if( mem[k][n][last] != -1 )return mem[k][n][last];
	double ret = 0;
	for( i=0; i<=k; i++ ){
		if( ABS( last - i ) <= 1 ){
			ret += dp( k, n-1, i );
		}
	}
	mem[k][n][last] = ret;
	return ret;
}


int main(){
	//freopen("10081.txt", "r", stdin);
	int n, k, i;
	double ans, total;
	while( scanf("%d%d", &k, &n) != EOF ){
		ans = 0;
		CLEAR(k, n);
		for(i=0; i<=k; i++)
			ans += dp(k, n-1, i);
		total = 1;
		for(i=0; i<n; i++)total *= (k+1);
		printf("%.5lf\n", (ans/total)*100);
	}
	return 0;
}
