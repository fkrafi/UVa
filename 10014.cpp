#include<stdio.h>


int main(){
	freopen("10014.txt", "r", stdin);
	int n, t, i, l, flag=0;
	double a0, an, ci, a1;
	scanf("%d", &t);
	while(t--){
		if(flag)printf("\n");
		flag = 1;
		scanf("%d%lf%lf", &n, &a0, &an);
		l = n;
		a1 = 0;
		for(i=0; i<n; i++){
			scanf("%lf", &ci);
			a1 += (l*ci);
			l--;
		}
		a1 = (n*a0 + an - 2*a1)/(n+1);
		printf("%.2lf\n", a1);
	}
	return 0;
}