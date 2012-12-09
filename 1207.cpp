#include<stdio.h>
#include<string.h>
#define SZ 10005

char s1[SZ], s2[SZ];
int d[SZ][SZ];
int len1, len2;

int MIN(int a, int b){
	return (a<b)?a:b;
}

int MAX(int a, int b){
	return (a>b)?a:b;
}


int dp(){
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
	freopen("1207.txt", "r", stdin);
	while( scanf("%d%s", &len1, s1) != EOF ){
		scanf("%d%s", &len2, s2);
		printf("%d\n", dp());
	}
	return 0;
}