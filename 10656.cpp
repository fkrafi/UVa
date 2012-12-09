#include<stdio.h>


int main(){
	freopen("10656.txt", "r", stdin);
	int n, a, flag, i;
	while(scanf("%d", &n)){
		if(!n)break;
		flag = 0;
		for(i=0; i<n; i++){
			scanf("%d", &a);
			if(a && !flag){
				printf("%d", a);
				flag = 1;
			}else if(a)
				printf(" %d", a);
		}
		if(!flag)printf("0");
		printf("\n");
	}
	return 0;
}