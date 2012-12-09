#include<stdio.h>

int ABS(int n){
	return (n<0)?-n:n;
}

int main(){
	freopen("10550.txt", "r", stdin);
	int a, b, c, d, res, t;
	while( scanf("%d%d%d%d", &a, &b, &c, &d) ){
		if(!a && !b && !c && !d)break;
		res = 1080;
		res += 9*(((t=a-b)<0)?t+40:t);
		res += 9*(((t=c-b)<0)?t+40:t);
		res += 9*(((t=c-d)<0)?t+40:t);
		printf("%d\n", res);
	}
	return 0;
}