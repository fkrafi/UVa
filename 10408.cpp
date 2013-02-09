#include<stdio.h>

int N, K;

void farey(){
	int a=0, b=1, c=1, d=N, t, k=0, x, y;
	while( k!=K ){
		t = (N+b)/d;
		x = t*c - a;
		y = t*d - b;
		a = c;
		b = d;
		c = x;
		d = y;
		k++;
	}
	printf("%d/%d\n", a, b);
}

int main(){
	freopen("10408.txt", "r", stdin);
	while( scanf("%d%d", &N, &K) != EOF ){
		farey();
	}
	return 0;
}