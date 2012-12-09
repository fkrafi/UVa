#include<stdio.h>

double res[80];

int main(){
	int i;
	res[1] = 1; res[2] = 2; res[3] = 2;
	for(i=4; i<=76; i++)
		res[i] = res[i-2] + res[i-3];
	while( scanf("%d", &i) != EOF )
		printf("%.0lf\n", res[i]);
	return 0;
}
