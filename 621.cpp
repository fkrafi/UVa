#include<stdio.h>
#include<string.h>

char s[10000];


int main(){
	int t, l;
	scanf("%d", &t);
	while( t-- ){
		scanf("%s", s);
		l = strlen(s);
		if( !strcmp(s, "1") || !strcmp(s, "4") || !strcmp(s, "78") ){
			puts("+");
		}else if(s[l-2]=='3' && s[l-1]=='5'){
			puts("-");
		}else if(s[0]=='9' && s[l-1]=='4'){
			puts("*");
		}else{
			puts("?");
		}
	}
	return 0;
}