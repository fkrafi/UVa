#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[10000], s2[10000], temp[10000], res[10000], temp2[10000];

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

void multiply(){
	int i, j, k, l1, l2, carry, n, l3, m;
	l1 = strlen(s1);
	l2 = strlen(s2);
	reverse(s1, s1+l1);
	reverse(s2, s2+l2);
	temp2[0] = '\0';
	for(i=0; i<l2; i++){
		k = 0;
		carry = 0;
		m = s2[i]-48;
		for(j=0; j<i; j++)temp[k++] = '0';
		for(j=0; j<l1; j++){
			n = ((s1[j] - 48) * m) + carry;
			temp[k++] = ((n%10)+48);
			carry = n/10;
		}
		while(carry){
			temp[k++] = carry%10+48;
			carry /= 10;
		}
		temp[k] = '\0';
		l3 = strlen(temp);
		reverse(temp, temp+l3);
		add(temp2, temp, res);
		strcpy(temp2, res);
	}
}


int main(){
	while(gets(s1)){
		gets(s2);
		multiply();
		int l = strlen(res);
		int flag = 0;
		for(int i=0; i<l; i++){
			if(flag==0 && res[i] == '0' ){
				flag = 0;
			}else{
				printf("%c", res[i]);
				flag = 1;
			}
		}
		if(flag==0)printf("0");
		printf("\n");
	}
	return 0;
}