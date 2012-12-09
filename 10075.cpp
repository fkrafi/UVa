#pragma warning(disable : 4786)
#include<string.h>
#include<map>
#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
#define INF 1<<30


typedef pair<double, double> pdd;

int nV, nC, Q, pos;
char _U[25], _V[25];
string u, v, S[105];
map<string, int> Map;

double wght[105][105];
pdd P[105];

double rad(double a){
	return ((acos(-1)*a)/180.0);
}

double round(double d){
	return floor(d + 0.5);
}

double distance(double lat1, double lat2,double lon1,double lon2){
	double R = 6378;
	lat1 = rad(lat1);
	lat2 = rad(lat2);
	lon1 = rad(lon1);
	lon2 = rad(lon2);
    return round(R*acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(lon2-lon1)));
}

double MIN(double a, double b){
	return (a<b)?a:b;
}



void init(){
	int i, j;
	for(i=1; i<=nV; i++)
		for(j=1; j<=nV; j++)
			wght[i][j] = (i==j)?0:INF;
}

void floyd_warshall(){
	int i, j, k;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = MIN(wght[i][j], wght[i][k]+wght[k][j]);
}


int main(){
	freopen("10075.txt", "r", stdin);
	int i, j, k, cs=1;
	double a, b;
	while( scanf("%d%d%d", &nV, &nC, &Q) ){
		if( !nV && !nC && !Q )break;
		if( cs>1 )printf("\n");
		Map.clear();
		for(i=0, pos=0; i<nV; i++){
			scanf("%s %lf %lf", _U, &a, &b);
			Map[string(_U)] = ++pos;
			S[pos] = string(_U);
			P[pos].first = a;
			P[pos].second = b;
		}
		init();
		for(i=0; i<nC; i++){
			scanf("%s%s", _U, _V);
			j = Map[string(_U)];
			k = Map[string(_V)];
			a = distance(P[j].first, P[k].first, P[j].second, P[k].second);
			wght[j][k] = a;
		}
		floyd_warshall();
		printf("Case #%d\n", cs++);
		while(Q--){
			scanf("%s%s", _U, _V);
			a = wght[Map[string(_U)]][Map[string(_V)]];
			if( a>=INF ){
				puts("no route exists");
			}else{
				printf("%.0lf km\n", a);
			}
		}
	}
	return 0;
}