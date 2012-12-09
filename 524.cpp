#include<stdio.h>
#include<math.h>

int N;
int prime[101], a[20];

void sieve(int n){
	prime[0]=1;
	prime[1]=1;
	int m = int(sqrt(n)), i=2, k;
	for(k=i*i; k<=n; k+=i)
		prime[k]=1;
	for (i=3; i<=m; i+=2)
		if(!prime[i])
			for (k=i*i; k<=n; k+=i)
				prime[k]=1;
}

void output(){
	int i;
	for(i=1; i<=N; i++){
		if( i==1 )
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	printf("\n");
}

void BkTk(int last, int pos, int seen[]){
	if( pos>N ){
		if( !prime[last+1] )
			output();
	}
	int i;
	for(i=2; i<=N; i++){
		if( seen[i] || prime[last+i] )continue;
		seen[i] = 1;
		a[pos] = i;
		BkTk(i, pos+1, seen);
		seen[i] = 0;
	}
}

void CLEAR(int seen[]){
	for(int i=0; i<=N; i++)
		seen[i] = 0;
}

int main(){
	freopen("524.txt", "r", stdin);
	sieve(100);
	int cs=1, seen[20], flag=0;
	while(scanf("%d", &N) != EOF){
		if( flag==1 )printf("\n");
		flag=1;
		printf("Case %d:\n", cs++);
		if( N==1 || N%2==0 ){
			CLEAR(seen);
			a[1] = 1;
			seen[1] = 1;
			BkTk(1, 2, seen);
		}
	}
	return 0;
}