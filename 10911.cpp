#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define SZ 700000
#define INF 9999999999;

typedef pair<double, double> PDD;


int n;
PDD d[20];
double memo[SZ];


double dis(int i, int j){
	double x = (d[i].first-d[j].first)*(d[i].first-d[j].first);
	double y = (d[i].second-d[j].second)*(d[i].second-d[j].second);
	return sqrt( x + y );
}

double solve(int mask){
	int i, j;
	double ret = INF;
	if( mask == (1<<2*n)-1 )return 0;
	if( memo[mask] != -1 )return memo[mask];
	for(i=0; i<2*n; i++){
		for(j=i+1; j<2*n; j++){
			if( (mask&(1<<i)) || (mask&(1<<j)) )continue;
			double q = dis(i, j) + solve( mask | (1<<i) | (1<<j) );
			if( q<ret )
				ret = q;
		}
	}
	return memo[mask] = ret;
}

void CLEAR(){
	for(int i=0; i<SZ; i++)
		memo[i] = -1;
}

int main(){
	freopen("10911.txt", "r", stdin);
	int i, cs=1;
	char s[25];
	while( scanf("%d", &n) && n ){
		for(i=0; i<2*n; i++){
			scanf("%s%lf%lf", s, &d[i].first, &d[i].second);
		}
		CLEAR();
		printf("Case %d: %.2lf\n", cs++, solve(0));
	}
	return 0;
}