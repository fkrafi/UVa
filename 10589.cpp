#include<stdio.h>
#include<math.h>

int N, a;



int inside_circles(double x, double y){
	double det;

	det = (x*x) + (y*y) - (a*a);
	if( det > 0 )return 0;
	
	det = ((x-a)*(x-a)) + (y*y) - (a*a);
	if( det > 0 )return 0;

	det = (x*x) + ((y-a)*(y-a)) - (a*a);
	if( det > 0 )return 0;

	det = ((x-a)*(x-a)) + ((y-a)*(y-a)) - (a*a);
	if( det > 0 )return 0;

	return 1;
}

int main(){
	freopen("10589.txt", "r", stdin);
	int M, i;
	double x, y, area;
	while(scanf("%d%d", &N, &a)){
		if(!N)break;
		M = 0;
		for(i=0; i<N; i++){
			scanf("%lf%lf", &x, &y);
			M += inside_circles(x, y);
		}
		area = (double(M)*a*a)/double(N);
		printf("%.5lf\n", area);
	}
	return 0;
}