#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char f[100000], s[100000], r[100000];

void add(char f[], char s[], char r[]){
	int lf, ls, d, i, j=0, c=0, sum;
	lf=strlen(f); ls=strlen(s);
	reverse(f, f+lf); reverse(s, s+ls);
	if(lf>=ls){
		d=lf-ls;
		for(i=0; i<ls; i++){
			sum = f[i]+s[i]-96+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
		}
		for(i=ls; i<lf; i++){
			sum = f[i]-48+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
		}
		if(c!=0){
			sum = c%10;
			r[j++] = sum+48;
			if(c>9)r[j++] = (c/10)+48;
		}
		r[j] = '\0';
		lf = strlen(r);
		reverse(r, r+lf);
	}else{
		d=lf-ls;
		for(i=0; i<lf; i++){
			sum = f[i]+s[i]-96+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
		}
		for(i=lf; i<ls; i++){
			sum = s[i]-48+c;
			r[j++] = (sum%10)+48;
			c = sum/10;
		}
		if(c!=0){
			sum = c%10;
			r[j++] = sum+48;
			if(c>9)r[j++] = (c/10)+48;
		}
		r[j] = '\0';
		lf = strlen(r);
		reverse(r, r+lf);
	}
}

int main(){
	int i;
	s[0]='0';
	for(i=0; i<100; i++){
		gets(f);
		if(f[0]=='0')break;
		add(f, s, r);
		strcpy(s, r);
	}
	puts(r);
	return 0;
}