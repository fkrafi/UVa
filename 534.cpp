#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define SZ 205
#define INF 99999999
typedef pair<int, int> pii;


int N;
double wght[SZ][SZ];
pii pos[SZ];

void init(){
	int i, j;
	double a, b;
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			if( i==j )
				wght[i][j] = INF;
			else{
				a = pos[i].first - pos[j].first;
				b = pos[i].second - pos[j].second;
				wght[i][j] = sqrt( a*a + b*b );
			}
		}
	}
}

double MIN(double a, double b){
	return (a<b)?a:b;
}

double MAX(double a, double b){
	return (a>b)?a:b;
}

void floyd_warshall(){
	int i, j, k;
	for(k=1; k<=N; k++){
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				//if( i==j )continue;
				wght[i][j] = MIN( wght[i][j], MAX(wght[i][k],wght[k][j]) );
			}
		}
	}
}


int main(){
	freopen("534.txt", "r", stdin);
	int i, cs=1;
	while( scanf("%d", &N) ){
		if( !N )break;
		for(i=1; i<=N; i++)
			scanf("%d%d", &pos[i].first, &pos[i].second);
		init();
		floyd_warshall();
		printf("Scenario #%d\n", cs++);
		printf("Frog Distance = %.3lf\n\n", wght[1][2]);
	}
	return 0;
}