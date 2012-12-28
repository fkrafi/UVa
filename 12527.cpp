#include<stdio.h>
#include<string.h>

int isValid(int n){
	int c[11];
	memset(c, 0, sizeof(c));
	while( n ){
		c[n%10]++;
		if( c[n%10]>1 )return 0;
		n /= 10;
	}
	return 1;
}

int main(){
	int N, M, i, res;
	while( scanf("%d%d", &N, &M) != EOF ){
		for(i=N, res=0; i<=M; i++){
			res += isValid(i);
		}
		printf("%d\n", res);
	}
	return 0;
}