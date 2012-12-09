#include<stdio.h>
#include<math.h>
#include<time.h>
#define M 1000000
int x[1000005];

void gen(){
	double i;
	double a, b, c;
	int j=1;
	x[0] = 1;
	for(i=1; i<=1000000; i++){
		a = floor(i-sqrt(i));
		b = floor(log(i));
		c = floor(i*sin(i)*sin(i));
		x[j++] = ( x[(int)a]%M + x[(int)b]%M + x[(int)c]%M )%M;
	}
}

int main(){
	//freopen("11703.txt", "r", stdin);
	int n;
	gen();
	while(scanf("%d", &n)){
		if(n<0)break;
		printf("%d\n", x[n]);
	}
	return 0;
}