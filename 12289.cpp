#include<stdio.h>
#include<string.h>

char s[50];
char str[3][10] = {"one", "two", "three"};
int len[] = {3, 3, 5};

int chk( char s[] ){
	int l=strlen(s), i, j, mis;
	for(i=0; i<3; i++){
		mis = 0;
		if( len[i] != l )continue;
		for(j=0; j<l; j++){
			if( s[j] != str[i][j] )
				mis++;
		}
		if( mis <= 1 )return i+1;
	}
	return 0;
}


int main(){
	int t;
	scanf("%d", &t);getchar();
	while(t--){
		gets(s);
		printf("%d\n", chk(s));
	}
	return 0;
}
