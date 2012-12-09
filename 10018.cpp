#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[100], s[100], s2[100];

void add(char f[], char s[], char r[]){
	int lf, ls, d=0, i, j=0, c=0, sum;
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
	int i, j, n, l;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%s", s1);
		for(j=0; ; j++){
			strcpy(s2, s1);
			l = strlen(s2);
			reverse(s2, s2+l);
			if(strcmp(s1, s2)==0)break;
			add(s1, s2, s);
			strcpy(s1, s);
		}
		printf("%d %s\n", j, s);
	}
	return 0;
}