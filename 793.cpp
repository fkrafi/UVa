#include<stdio.h>
#include<string.h>
#define SZ 100005

int id[SZ];
char s[1005];

void init(int n) {
	for (int i=0; i<=n; i++) {
		id[i] = i;
	}
}

int root(int i) {
	while (i != id[i])
		i = id[i];
	return i;
}

void Union(int p, int q) {
	id[root(p)] = root(q);
}

bool connected(int p, int q) {
	return (root(p) == root(q));
}

int ATOI(char str[]){
	int ret=0, i, len=strlen(str);
	for(i=0; i<len; i++){
		ret = ret*10 + (str[i]-'0');
	}
	return ret;
}

int main(){
	freopen("793.txt", "r", stdin);
	char Oper;
	int T, N, C, W, u, v;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &N); getchar();
		init(N);
		C = W = 0;
		while( gets(s) ){
			if( strlen(s) == 0 )break;
			char *pch = strtok(s, " ");
			Oper = pch[0];
			pch = strtok(NULL, " ");
			u = ATOI(pch);
			pch = strtok(NULL, " ");
			v = ATOI(pch);
			if( Oper=='c' ){
				Union(u, v);
			}else{
				if( connected(u, v) ){
					C++;
				}else{
					W++;
				}
			}
		}
		printf("%d,%d\n", C, W);
		if( T )printf("\n");
	}
	return 0;
}


