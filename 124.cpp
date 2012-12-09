#pragma warning(disable : 4786)
#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define SZ 25


int nE, nV;
int in[SZ];
int seen[SZ];
int res[SZ];
char nodes[SZ];
vector<int> edges[SZ];
map<char, int> M;
map<int, char> rM;
char str[1000];
queue<int> Q, EQ;

int isChar(char ch){
	return (ch>='a' && ch<='z');
}

void create_map(){
	M.clear();
	rM.clear();
	Q = EQ;
	nV = 1;
	int l=strlen(str), i;
	for(i=0; i<l; i++){
		if( isChar(str[i]) ){
			nodes[nV] = str[i];
			in[nV] = 0;
			seen[nV] = 0;
			edges[nV].clear();
			rM[nV] = str[i];
			M[str[i]] = nV++;
		}
	}
}

void create_graph(){
	char u;
	int l=strlen(str), i, cnt=0;
	for(i=0; i<l; i++){
		if( isChar(str[i]) ){
			cnt++;
			if(cnt==1)u=str[i];
			else{
				cnt = 0;
				in[M[str[i]]]++;
				edges[M[u]].push_back(M[str[i]]);
			}
		}
	}
}

void output(){
	for(int i=0; i<nV-1; i++)
		printf("%c", rM[res[i]]);
	printf("\n");
}

int isValid(int n, int len){
	int i, j;
	for(i=0; i<len; i++){
		for(j=0; j<edges[n].size(); j++){
			if( edges[n][j] == res[i] )return 0;
		}
	}
	return 1;
}


void topological_sort(int len){
	if(len==nV-1){
		output();
	}else{
		for(int i=1; i<nV; i++){
			if( !seen[i] && isValid(i, len) ){
				seen[i] = 1;
				res[len] = i;
				topological_sort(len+1);
				seen[i] = 0;
			}
		}
	}
}

int main(){
	freopen("124.txt", "r", stdin);
	int flag=0;
	while( gets(str) ){
		if( flag )printf("\n");
		flag = 1;
		sort(str, str+strlen(str));
		create_map();
		gets(str);
		create_graph();
		topological_sort(0);
	}
	return 0;
}