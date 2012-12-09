#include<stdio.h>

int main(){
	freopen("11936.txt", "r", stdin);
	int t, a, b, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &c);
		if(a+b>c && a+c>b && c+b>a)
			puts("OK");
		else
			puts("Wrong!!");
	}
	return 0;
}