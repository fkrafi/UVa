#include<stdio.h>

int MIN(int a, int b){
	return (a<b)?a:b;
}

int main(){
	int t, n, m, res;
	char s[5];
	scanf("%d", &t);
	while(t--){
		scanf("%s%d%d", s, &m, &n);
		if(s[0]=='Q' || s[0]=='r')
			res = MIN(m, n);
		else if(s[0]=='K')
			res = ((m+1)/2) * ((n+1)/2);
		else if(s[0]=='k')
			res = ((m+1)/2)*((n+1)/2) + (m/2)*(n/2);
		printf("%d\n", res);
	}
	return 0;
}