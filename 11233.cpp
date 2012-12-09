#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;

char u[50], v[50];
map<string, string> M;

int isVowel(char ch){
	return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int isEnds(int L){
	if( u[L]=='o' || u[L]=='s' || u[L]=='x' )return 1;
	if( u[L-1]=='c' && u[L]=='h' )return 1;
	if( u[L-1]=='s' && u[L]=='h' )return 1;
	return 0;
}

int main(){
	freopen("11233.txt", "r", stdin);
	int L, N;
	while( scanf("%d%d", &L, &N) != EOF ){
		while( L-- ){
			scanf("%s%s", u, v);
			M[string(u)] = string(v);
		}
		while( N-- ){
			scanf("%s", u);
			L = strlen(u);
			if( M.find(string(u)) != M.end() ){
				cout << M[string(u)] << "\n";
			}else if( u[L-1]=='y' && L>=2 && !isVowel(u[L-2]) ){
				cout << string(u).substr(0, L-1) << "ies\n";
			}else if( L>=2 && isEnds(L-1) ){
				cout << u << "es\n";
			}else{
				cout << u << "s\n";
			}
		}
	}
	return 0;
}
