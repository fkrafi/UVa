#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SZ 1000005

int pi[SZ], len;
char T[SZ], P[SZ];

void compute_prefix_function(char pattern[], int psize){
	int k = -1;
	int i = 1;
	pi[0] = k;
	for (i = 1; i < psize; i++) {
		while (k >=0 && pattern[k+1] != pattern[i])
			k = pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		pi[i] = k;
	}
}

int kmp(char target[], int tsize, char pattern[], int psize){
	int i, k, temp=0;
	compute_prefix_function(pattern, psize);
	k = -1;
	len = 0;
	for (i=0; i<tsize; i++) {
		while (k>=0 && pattern[k+1]!=target[i]){
			k = pi[k];
		}
		if (target[i] == pattern[k+1]){
			k++;
		}
	}
	return k;
}

int main(){
	freopen("T.txt", "r", stdin);
	int i, sz;
	while( gets(T) ){
		sz = strlen(T);
		strcpy(P, T);
		reverse(P, P+sz);
		len = kmp(T, sz, P, sz);
		printf("%s", T);
		for(i=sz-len-2; i>=0; i--)printf("%c", T[i]);
		printf("\n");
	}
	return 0;
}
