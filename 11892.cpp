#include<stdio.h>

int main(){
	freopen("11892.txt", "r", stdin);
	int T, N, A, o, no;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &N);
		o = no = 0;
		while( N-- ){
			scanf("%d", &A);
			if( A==1 )o++;
			else no++;
		}
		if( o%2 || no ){puts("poopi");}
		else{puts("piloop");}
	}
	return 0;
}