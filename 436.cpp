#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
using namespace std;
#define SZ 32


int nV, nC;
char u[50], v[50];
double wght[SZ][SZ];
map<string, int> M;


double MAX(double a, double b){
	return (a>b)?a:b;
}

void floyd_warshall(){
	int i, j, k;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = MAX(wght[i][j], wght[i][k]*wght[k][j]);
}

int isArbitrage(){
	int i;
	for(i=1; i<=nV; i++)
		if( wght[i][i]>1.0001 )return 1;
	return 0;
}


void init(){
	int i, j;
	M.clear();
	for(i=1; i<=nV; i++){
		for(j=1; j<=nV; j++){
			if( i==j ) wght[i][j] = 1;
			else wght[i][j] = 0;
		}
	}
}

void input(){
	int i, ui, vi;
	double c;
	for(i=1; i<=nV; i++){
		scanf("%s", u);
		M[string(u)] = i;
	}
	scanf("%d", &nC);
	for(i=1; i<=nC; i++){
		scanf("%s%lf%s", u, &c, v);
		ui = M[string(u)];
		vi = M[string(v)];
		wght[ui][vi] = c;
	}
}

int main(){
	freopen("436.txt", "r", stdin);
	int cs=1;
	while( scanf("%d", &nV) ){
		if( !nV )break;
		init();
		input();
		floyd_warshall();
		printf("Case %d: ", cs++);
		if( isArbitrage() ) puts("Yes");
		else puts("No");
	}
	return 0;
}