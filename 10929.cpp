#include<stdio.h>
#include<string.h>

char s[10001];

int mod(char s[], int d){
	int i, l;
	int c=0;
	l = strlen(s);
	for(i=0; i<l; i++){
		c = ((s[i]-48)+(c*10))%d;
	}
	return c;
}


int main(){
	while(gets(s)){
		if(s[0]=='0' && strlen(s)==1)break;
		if(mod(s, 11)){
			printf("%s is not a multiple of 11.\n", s);
		}else{
			printf("%s is a multiple of 11.\n", s);
		}
	}
	return 0;
}
