#include<stdio.h>

int seen[100];
int b[100];

void CLEAR(int n, int arr[]){
	for( int i=0; i<=n; i++ )
		arr[i] = 0;
}

int chk(int n){
	for( int i=0; i<=n; i++)
		if( !seen[i] )return 0;
	return 1;
}

int ab(int n){
	return (n<0)?-n:n;
}

int main(){
	freopen("12239.txt", "r", stdin);
	int N, B, i, j;
	while( scanf("%d%d", &N, &B) ){
		if( !N && !B )break;
		CLEAR(N, seen);
		for(i=0; i<B; i++)scanf("%d", &b[i]);
		for(i=0; i<B; i++)
			for(j=0; j<B; j++)
				seen[ ab(b[i]-b[j]) ] = 1;
		if( chk(N) )
			puts("Y");
		else
			puts("N");
	}
	return 0;
}