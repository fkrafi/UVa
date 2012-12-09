#include<stdio.h>
#include<string.h>

int sz;
int seen[1000];
int len[10000];
char str[10000][25];

void print(){
	int i, j=0;
	for(i=0; i<20; i++){
		for(j=0; j<sz; j++){
			if( seen[ str[j][i] ] )continue;
			if( str[j][i]>='A' && str[j][i]<='Z'){
				seen[ str[j][i] ] = 1;
				printf("%c", str[j][i]);
			}
		}
	}
	printf("\n");
}

int main(){
	freopen("200.txt", "r", stdin);
	while( gets(str[sz]) ){
		if( strcmp(str[sz], "#") == 0 )break;
		len[sz] = strlen(str[sz]);
		sz++;
	}
	print();
	return 0;
}