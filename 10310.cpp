#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef pair<double, double> pdd;

pdd g, d;

int main(){
	int N, i;
	double x, y, disG, disD;
	double resX, resY;
	while( scanf("%d", &N) != EOF ){
		scanf("%lf%lf%lf%lf", &g.first, &g.second, &d.first, &d.second);
		resX = resY = -10005;
		for(i=0; i<N; i++){
			scanf("%lf%lf", &x, &y);
			disG = sqrt( (x-g.first)*(x-g.first) + (y-g.second)*(y-g.second) );
			disD = sqrt( (x-d.first)*(x-d.first) + (y-d.second)*(y-d.second) );
			if( 2*disG<=disD && resX==-10005 ){
				resX = x;
				resY = y;
			}
		}
		if( resX == -10005 ){
			puts("The gopher cannot escape.");
		}else{
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", resX, resY);
		}
	}
	return 0;
}