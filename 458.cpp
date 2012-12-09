#include<stdio.h>
#include<string.h>

char s[1000000];

int main(){
	int i, l, c;
	while(gets(s) != NULL){
		l = strlen(s);
		for(i=0; i<l; i++){
			c = s[i]-7;
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
