#include<stdio.h>

int main(){
	int n, s, d, a, b, i, c;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		c=1;
		scanf("%d%d", &s, &d);
		if((s+d)%2!=0)c=0;
		a = (s+d)/2;
		b = s-a;
		if(a<0 || b<0 || c==0){
			printf("impossible\n");
		}else{
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}
