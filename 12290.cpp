#include<stdio.h>

int n, m, k;

int chk( int t ){
	if( t%7 == 0 )return 1;
	while( t ){
		if( t%10 == 7 )return 1;
		t /= 10;
	}
	return 0;
}

int count(){
	int i=0, p=0, c=1, cnt=0;
	while( 1 ){
		p++;
		i += c;
		if( i>n ){
			i = n-1;
			c = -1;
		}else if( !i ){
			i = 2;
			c = 1;
		}
		if( i==m && chk(p) ){
			cnt++;
			if( cnt == k )return p;
		}
	}
	return 0;
}

int main(){
	while( scanf("%d%d%d", &n, &m, &k) ){
		if( !n && !m && !k )break;
		printf("%d\n", count());
	}
	return 0;
}