#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[10000], s2[10000], res[10000];

struct Fibonacci{
	char all[100000];
}f[5001];

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


void generate(){
	int i, k=2;
	strcpy(f[0].all, "0");
	strcpy(f[1].all, "1");
	for(i=2; i<5001; i++){
		strcpy(s1, f[k-1].all);
		strcpy(s2, f[k-2].all);
		add(s1, s2, res);
		strcpy(f[k].all, res);
		k++;
	}
}

int main(){
	generate();
	int n;
	while(scanf("%d", &n)!=EOF){
		printf("The Fibonacci number for %d is %s\n", n, f[n].all);
	}
	return 0;
}