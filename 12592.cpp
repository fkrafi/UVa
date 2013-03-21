#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

char u[105], v[105];
map<string, string> M;

int main(){
	freopen("12592.txt", "r", stdin);
	int N, Q;
	while( scanf("%d", &N) != EOF ){
		getchar();
		M.clear();
		while( N-- ){
			gets(u);
			gets(v);
			M[string(u)] = string(v);
		}
		scanf("%d", &Q); getchar();
		while( Q-- ){
			gets(u);
			cout << M[u] << "\n";
		}
	}
	return 0;
}