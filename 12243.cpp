#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[10000], ch;

int isEqual(char a, char b){
	return (tolower(a) == tolower(b));
}

int main(){
	freopen("12243.txt", "r", stdin);
	int flag;
	while(gets(s)){
		if( s[0]=='*' )break;
		char *pch = strtok(s, " ");
		flag = 1;
		ch = pch[0];
		while( pch != NULL ){
			if( !isEqual( ch, pch[0] ) ){
				flag = 0;
				break;
			}
			pch = strtok(NULL, " ");
		}
		if( flag )puts("Y");
		else puts("N");
	}
	return 0;
}