#include<stdio.h>


int main(){
	freopen("11984.txt", "r", stdin);
	int t, cs;
	double C, F, d;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%lf%lf", &C, &d);
		F = (9.0/5.0)*C + 32 + d;
		C = (F-32)*(5.0/9.0);
		printf("Case %d: %.2lf\n", cs, C);
	}
	return 0;
}