#include<stdio.h>
#include<string.h>
#define SZ 25


char img[SZ][SZ];
int cnt[256], R, C, M, N;

int input(){
	char ch;
	int i, j, Max=0, sum=0;
	memset(cnt, 0, sizeof(cnt));
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			scanf("%c", &ch);
			if( ch>='A' && ch<='Z' ){
				cnt[ch]++;
				if( Max<cnt[ch] )
					Max = cnt[ch];
			}else{j--;}
		}
	}
	for(i='A'; i<='Z'; i++){
		if( Max==cnt[i] )
			sum += cnt[i];
	}
	return (sum*M + (C*R-sum)*N);
}

int main(){
	freopen("11588.txt", "r", stdin);
	int T, cs;
	scanf("%d", &T);
	for(cs=1; cs<=T; cs++){
		scanf("%d%d%d%d", &R, &C, &M, &N);
		printf("Case %d: %d\n", cs, input());
	}
	return 0;
}