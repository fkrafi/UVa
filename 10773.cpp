#include<stdio.h>
#include<math.h>

double FABS(double n){
	return (n<0)?-n:n;
}

int main(){
	int cs, T;
	double u, v, d, t1, t2;
	scanf("%d", &T);
	for(cs=1; cs<=T; cs++){
		scanf("%lf%lf%lf", &d, &v, &u);
		if( u<=v || !u || !v ){
			printf("Case %d: can\'t determine\n", cs);
			continue;
		}
		t1 = d/(u);
		t2 = d/sqrt(u*u-v*v);
		printf("Case %d: %.3lf\n", cs, FABS(t1-t2));
	}
	return 0;
}
