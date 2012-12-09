#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
using namespace std;
#define INF 9999999
#define SZ 150

int wght[SZ][SZ], cs=1, nV;
int seen[SZ], cst[SZ][SZ];
map<int, int> M;

int MIN(int a, int b){
	return (a<b)?a:b;
}

int MAX(int a, int b){
	return (a>b)?a:b;
}

void init(){
	int i, j;
	for(i=0; i <=100; i++)
		for(j=0; j<=100; j++)
			wght[i][j] = INF;
}

void floyd_warshall(){
	int i, j, k;
	for(k=1; k<=nV; k++){
		for(i=1; i<=nV; i++){
			for(j=1; j<=nV; j++){
				if( i==j || j==k || k==i )continue;
				wght[i][j] = MIN(wght[i][j], wght[i][k]+wght[k][j]);
			}
		}
	}
}

double solve(){
	int i, j;
	double sum=0, n=0;
	for(i=1; i<=nV; i++){
		for(j=1; j<=nV; j++){
			if(i==j || wght[i][j]>=INF)continue;
			sum += wght[i][j];
			n++;
		}
	}
 	return (sum/n);
	return sum;
}

int main(){
	freopen("821.txt", "r", stdin);
	int a, b;
	double res;
	nV = 0;
	while(scanf("%d%d", &a, &b)){
		init();
		if(!a && !b)break;
		if( M.find(a) == M.end() )M[a] = ++nV;
		if( M.find(b) == M.end() )M[b] = ++nV;
		wght[M[a]][M[b]] = 1;
		seen[a] = seen[b] = cs;
		while(scanf("%d%d", &a, &b)){
			if(!a && !b)break;
			if( M.find(a) == M.end() )M[a] = ++nV;
			if( M.find(b) == M.end() )M[b] = ++nV;
			wght[M[a]][M[b]] = 1;
		}
		floyd_warshall();
		res = solve();
		printf("Case %d: average length between pages = %.3lf clicks\n", cs++, res);
		nV = 0;
		M.clear();
	}
	return 0;
}