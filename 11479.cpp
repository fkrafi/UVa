#include<stdio.h>

int main(){
	int t, i;
	double a, b, c;
	scanf("%d", &t);
	for(i=1; i<=t; i++){
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a+b<=c || a+c<=b || b+c<=a){
			printf("Case %d: Invalid\n", i);
		}else if(a==b && b==c && c==a){
			printf("Case %d: Equilateral\n", i);
		}else if(a==b || b==c || c==a){
			printf("Case %d: Isosceles\n", i);
		}else{
			printf("Case %d: Scalene\n", i);
		}
	}
	return 0;
}