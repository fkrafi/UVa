#include<stdio.h>

int main(){
	int i, n, l, j;
	for(i=1; i<=2000; i++){
		scanf("%d", &n);
		if(n<0)break;
		l=1;
		for(j=1; ; j++){
			l += l;
			if(l>=n)break;
		}
		if(n>1){
			printf("Case %d: %d\n", i, j);
		}else{
			j=0;
			printf("Case %d: %d\n", i, j);
		}
	}
	return 0;
}