#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
#define SZ 1005

map<string, int> M;
char u[SZ], v[SZ];

int check(){
	int i, ul=strlen(u), vl=strlen(v);
	for(i=0; i<vl; i++){
		u[i] = v[i];
		if( i>=ul )u[i] = '\0';
		if( M[string(u)] != 5 )return 0;
	}
	return 1;
}


int main(){
	freopen("12460.txt", "r", stdin);
	while(gets(u)){
		if( !strcmp(u, "--") )break;
		M[string(u)] = 5;
	}
	while( scanf("%s%s", u, v) != EOF ){
		if( check() )puts("Yes");
		else puts("No");
	}
	return 0;
}