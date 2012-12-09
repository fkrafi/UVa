#include<stdio.h>
double fact(int n){
	int i;
	double f=1;
	for(i=2; i<=n; i++){
		f*=double(i);
	}
	return f;
}

int main(){
	double c;
	int n, m;
	while(scanf("%d%d", &n, &m)){
		if(n==0 && m==0)break;
		c = fact(n)/(fact(n-m)*fact(m));
		printf("%d things taken %d at a time is %.0lf exactly.\n", n, m, c); 
	}
	return 0;
}