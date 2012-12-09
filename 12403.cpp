#include<stdio.h>
#include<string.h>

char s[100];


int main(){
	freopen("12403.txt", "r", stdin);
	int t, res=0, v;
	scanf("%d", &t);
	while( t-- ){
		scanf("%s", s);
		if( !strcmp(s, "donate") ){
			scanf("%d", &v);
			res += v;
		}else{
			printf("%d\n", res);
		}
	}
	return 0;
}