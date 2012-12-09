#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[1000];

int main(){
	int l, i, j, skrew, k;
	while(gets(s)){
		if(atol(s)==0)break;
		skrew=0;
		l = strlen(s);
		for(i=0; i<l; i++){
			k=1;
			for(j=l-i; j>0; j--){
				k*=2;
			}
			skrew+=((s[i]-48)*(k-1));
		}
		printf("%d\n", skrew);
	}
	return 0;
}