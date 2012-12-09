#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char f[100], s[100], r[100];

int add(char f[], char s[], char r[]){
	int lf, ls, d, i, j=0, c=0, sum, carry=0;
	lf=strlen(f); ls=strlen(s);
	reverse(f, f+lf); reverse(s, s+ls);
	if(lf>=ls){
		d=lf-ls;
		for(i=0; i<ls; i++){
			sum = f[i]+s[i]-96+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
			carry += c;
		}
		for(i=ls; i<lf; i++){
			sum = f[i]-48+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
			carry += c;
		}
		if(c!=0){
			sum = c%10;
			r[j++] = sum+48;
			if(c>9)r[j++] = (c/10)+48;
		}

	}else{
		d=lf-ls;
		for(i=0; i<lf; i++){
			sum = f[i]+s[i]-96+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
			carry += c;
		}
		for(i=lf; i<ls; i++){
			sum = s[i]-48+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
			carry += c;
		}
		if(c!=0){
			sum = c%10;
			r[j++] = sum+48;
			if(c>9)r[j++] = (c/10)+48;
		}
	}
	return carry;
}

int main(){
	int c;
	while(scanf("%s%s", f, s)){
		if(f[0] == '0' && s[0]=='0')break;
		c = add(f, s, r);
		if(c==0){
			printf("No carry operation.\n");
		}else if(c==1){
			printf("1 carry operation.\n");
		}else{
			printf("%d carry operations.\n", c);
		}
	}
	return 0;
}