#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[10000];

int hex(char ch){
	if(ch>='0' && ch<='9')return (ch-48);
	return (tolower(ch)-'a'+10);
}

void hex2dec(){
	long long int l = strlen(s), i, p=1;
	long long int dec=hex(s[l-1]);
	for(i=l-2; i>1; i--){
		p *= 16;
		dec += (hex(s[i])*p);
	}
	printf("%lld\n", dec);
}


void dec2hex(){
	long long int l = strlen(s), dec=0, i;
	for(i=0; i<l; i++){
		dec = dec*10 + hex(s[i]);
	}
	printf("0x%X\n", dec);
}

int main(){
	freopen("10473.txt", "r", stdin);
	while(gets(s)){
		if(s[0]=='-')break;
		if(s[0]=='0' && s[1]=='x')hex2dec();
		else dec2hex();
	}
	return 0;
}