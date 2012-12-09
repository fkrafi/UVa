#include<stdio.h>
#include<string.h>
#define SZ 10005

char s[SZ];
char dic[SZ][50];
int len[SZ];
int d[SZ][SZ];
char r[SZ];

int MIN(int a, int b){
	return (a<b)?a:b;
}
int MAX(int a, int b){
	return (a>b)?a:b;
}

int dp(char s1[], int len1, char s2[], int len2){
	int a[3], i, j, k=MAX(len1, len2);
	for(i=0; i<=k; i++){
		d[i][0] = i;
		d[0][i] = i;
	}
	for(i=1; i<=len1; i++){
		for(j=1; j<=len2; j++){
			a[0] = d[i-1][j] + 1;
			a[1] = d[i][j-1] + 1;
			a[2] = d[i-1][j-1] + (s1[i-1]!=s2[j-1]);
			d[i][j] = MIN(a[0], MIN(a[1], a[2]));
		}
	}
	return d[len1][len2];
}

int main(){
	freopen("963.txt", "r", stdin);
	int N, i, flag, l, min, temp;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%s", &dic[i]);
		len[i] = strlen(dic[i]);
	}
	scanf("%d", &i);getchar();
	while( gets(s) ){
		char *pch = strtok(s, " ");
		flag = 0;
		while( pch != NULL ){
			l = strlen(pch);
			min = 9999999;
			for(i=0; i<N; i++){
				temp = dp(pch, l, dic[i], len[i]);
				if( temp<min ){
					min = temp;
					strcpy(r, dic[i]);
				}
			}
			if( flag )printf(" %s", r);
			else printf("%s", r); flag = 1;
			pch = strtok(NULL, " ");
		}
		printf("\n");
	}
	return 0;
}