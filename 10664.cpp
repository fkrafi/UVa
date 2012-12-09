#include<stdio.h>
#include<string.h>

int N, T;
int can[205];
int wght[25];
char str[10000];

void init(int T){
	can[0] = 1;
	for(int i=1; i<=T; i++)
		can[i] = 0;
}

void coin_change(int N, int T){
	int i, j;
	for(i=0; i<N; i++){
		for(j=T; j>=1; j--){
			if( j-wght[i]<0 )continue;
			if( can[j-wght[i]] )
				can[j] = 1;
		}
	}
}

int strToInt(char s[]){
	int i, n=0, l=strlen(s);
	for(i=0; i<l; i++){
		n = n*10 + (s[i]-48);
	}
	return n;
}

void input(){
	N = T = 0;
	gets(str);
	char *pch = strtok(str, " ");
	while( pch != NULL ){
		wght[N] = strToInt(pch);
		T += wght[N++];
		pch = strtok(NULL, " ");
	}
}

int main(){
	freopen("10664.txt", "r", stdin);
	int t;
	scanf("%d", &t);getchar();
	while( t-- ){
		input();
		if( T%2 ){
			puts("NO");
			continue;
		}
		init(T);
		coin_change(N, T/2);
		if( can[T/2] )puts("YES");
		else puts("NO");
	}
	return 0;
}