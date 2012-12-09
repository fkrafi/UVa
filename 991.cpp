#include<stdio.h>


double mem[15], f[50];

int main(){
	int i, flag=0;
	f[1] = 1;
	for(i=2; i<=10*2; i++)f[i] = f[i-1]*i;

	for(i=1; i<=10; i++)
		mem[i] = f[2*i]/(f[i+1]*f[i]);
	while(scanf("%d", &i) != EOF){
		if(flag)printf("\n");
		flag = 1;
		printf("%.0lf\n", mem[i]);
	}
	return 0;
}