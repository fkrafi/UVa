#include<stdio.h>
#include<math.h>

int main(){
	double u, v, t, a, s;
	int nC=1, c;
	while(scanf("%d", &c)){
		if(c==0)break;
		switch(c){
			case 1:
				scanf("%lf%lf%lf", &u, &v, &t);
				a = ((v-u)/t);
				s = (u*t + .5*a*t*t);
				printf("Case %d: %.3lf %.3lf\n", nC++, s, a);
				break;
			case 2:
				scanf("%lf%lf%lf", &u, &v, &a);
				t = ((v-u)/a);
				s = (u*t + .5*a*t*t);
				printf("Case %d: %.3lf %.3lf\n", nC++, s, t);
				break;
			case 3:
				scanf("%lf%lf%lf", &u, &a, &s);
				v = sqrt((u*u) + (2*a*s));
				t = ((v - u)/a);
				printf("Case %d: %.3lf %.3lf\n", nC++, v, t);
				break;
			case 4:
				scanf("%lf%lf%lf", &v, &a, &s);
				u = sqrt(v*v - 2*a*s);
				t = (v-u)/a;
				printf("Case %d: %.3lf %.3lf\n", nC++, u, t);
		}
	}
	return 0;
}