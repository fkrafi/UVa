#include<stdio.h>
#include<math.h>

int main(){
	int T;
	double L, W, R, pi=acos(-1), aC, aR;
	scanf("%d", &T);
	while(T--){
		scanf("%lf", &L);
		W = 0.6*L;
		R = 0.2*L;
		aC = pi*R*R;
		aR = L*W - aC;
		printf("%.2lf %.2lf\n", aC, aR);
	}
	return 0;
}