#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
#define INF 99999999
#define SZ 130

int nV;
char str[1000];
string u, v;
map<string, int> M;
map<int,string> rM;

struct storage{
	int pi;
	int wght;
	string route;
}edge[SZ][SZ];

void init(){
	int i, j;
	M.clear();
	rM.clear();
	for(i=1; i<=100; i++)
		for(j=1; j<=100; j++){
			edge[i][j].wght = INF;
			edge[i][j].pi = -1;
		}
}


int strToNum( char s[] ){
	int i, ret=0, l=strlen(s);
	for(i=0; i<l; i++)
		ret = ret*10 + s[i]-48;
	return ret;
}

int MIN(int a, int b){
	return (a<b)?a:b;
}

void input(){
	nV = 0;
	while(gets(str)){
		if( strlen(str) == 0 || str[0]=='\n' )break;
		char *pch = strtok(str, ",");
		u = string(pch);
		if( M.find(u) == M.end() ){
			M[u] = ++nV;
			rM[nV] = u;
		}
		pch = strtok(NULL, ",");
		v = string(pch);
		if( M.find(v) == M.end() ){
			M[v] = ++nV;
			rM[nV] = v;
		}
		
		pch = strtok(NULL, ",");
		string route = string(pch);
		
		pch = strtok(NULL, ",");
		int temp = strToNum(pch);

		if( edge[M[u]][M[v]].wght > temp ){
			edge[M[u]][M[v]].route = route;
			edge[M[u]][M[v]].wght = temp;
		}
		if( edge[M[v]][M[u]].wght > temp ){
			edge[M[v]][M[u]].wght = temp;
			edge[M[v]][M[u]].route = route;
		}
	}
}


void floyd_warshall(){
	int k, i, j;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				if( edge[i][j].wght > (edge[i][k].wght+edge[k][j].wght) ){
					edge[i][j].wght = edge[i][k].wght+edge[k][j].wght;
					edge[i][j].pi = k;
				}
}

void print_space(int l){
	for(int i=0; i<l; i++)printf(" ");
}

void print_path(int i, int j){
	if( edge[i][j].pi == -1 ){
		cout << rM[i];
		print_space(20 - rM[i].length() + 1);
		cout << rM[j];
		print_space(20 - rM[j].length()  + 1);
		cout << edge[i][j].route;
		u = edge[i][j].route;
		print_space(10 - u.length() + 1);
		printf("%5d\n", edge[i][j].wght);
		return;
	}
	int k = edge[i][j].pi;
	print_path(i, k);
	print_path(k, j);
}

void output(int i, int j){
	printf("\n\n");
	puts("From                 To                   Route      Miles");
	puts("-------------------- -------------------- ---------- -----");

	print_path(M[u], M[v]);

	puts("                                                     -----");
    printf("                                          Total      %5d\n", edge[i][j].wght);
}

int main(){
	freopen("186.txt", "r", stdin);
	init();
	input();
	floyd_warshall();
	while( gets(str) ){
		char *pch = strtok(str, ",");
		u = string(pch);
		pch = strtok(NULL, ",");
		v = string(pch);
		output(M[u], M[v]);
	}
	return 0;
}