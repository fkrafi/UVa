#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;


int N;
pair<double, double> C[10];

double dis(int i, int j){
	double a = C[i].first - C[j].first;
	double b = C[i].second - C[j].second;
	return sqrt( a*a + b*b ) + 16;
}

void copy(int *s, int *c){
	for(int i=0; i<N; i++)
		c[i] = s[i];
}

void solve(){
	double t, r=99999999;
	int i, j, k, s[20], c[10];
	for(i=0; i<N; i++)s[i]=i;
	do{
		t = 0;
		for(i=1; i<N; i++){
			t += dis(s[i-1], s[i]);
		}
		if( t<=r ){
			r = t;
			copy(s, c);
		}
	}while( next_permutation(s, s+N) );
	for(k=1; k<N; k++){
		i = c[k-1]; j = c[k];
		printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n", C[i].first, C[i].second, C[j].first, C[j].second, dis(i, j));
	}
	printf("Number of feet of cable required is %.2lf.\n", r);
}

int main(){
	freopen("216.txt", "r", stdin);
	int cs=1, i;
	while( scanf("%d", &N) && N){
		for(i=0; i<N; i++){
			scanf("%lf%lf", &C[i].first, &C[i].second);
		}
		puts("**********************************************************");
		printf("Network #%d\n", cs++);
		solve();
	}
	return 0;
}