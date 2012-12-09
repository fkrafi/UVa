#include<stdio.h>
#include<string.h>
#define SZ 100005

int pi[SZ];
char T[SZ], P[SZ];

void Comput_Prefix_function(char P[]){
	int m, k, q;
	m = strlen(P);
	pi[1] = 0;
	k = 0;
	for(q=2; q<=m; q++){
		while( k>0 && P[k+1] != P[q] ){
			k = pi[k];
		}
		if( P[k+1] == P[q] ){
			k++;
		}
		pi[q] = k;
	}
}


int KMP_Matcher(char T[], char P[]){
	int n, m, i, q;
	n = strlen(T);
	m = strlen(P);
	Comput_Prefix_function(P);
	q = 0;
	for(i=1; i<=n; i++){
		while( q>0 && P[q+1]!=T[i] ){
			q = pi[q];
		}
		if( P[q+1] == T[i] ){
			q++;
		}
		if( q==m-1 ){
			return 1;
			q = pi[q];
		}
	}
	return 0;
}

int main(){
	int t, q;
	scanf("%d", &t);getchar();
	while( t-- ){
		gets(T);
		scanf("%d", &q);getchar();
		while( q-- ){
			gets(P);
			if( KMP_Matcher(T, P) )puts("y");
			else puts("n");
		}
	}
	return 0;
}