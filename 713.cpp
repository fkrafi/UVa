#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[100000], s2[100000], s[100000];

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
	int i, t, l, l1, l2, j, flag;
	char ch;
	scanf("%d%c", &t, &ch);
	for(i=0; i<t; i++){
		scanf("%s%s", s1, s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		reverse(s1, s1+l1);
		reverse(s2, s2+l2);
		add(s1, s2, s);
		l = strlen(s);
		reverse(s, s+l);
		flag = 0;
		for(j=0; j<l; j++){
			if(flag==0 && s[j] == '0'){
				flag=0;
			}else{
				printf("%c", s[j]);
				flag = 1;
			}
		}
		printf("\n");
	}
	return 0;
}