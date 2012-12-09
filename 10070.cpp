#include<stdio.h>
#include<string.h>

char s[10001];

double mod(char s[], int d){
 int i, l, n;
 int c=0;
 l = strlen(s);
 for(i=0; i<l; i++){
  n = ((s[i]-48)+(c*10));
  c = (n>=d)?(n%d):n;
 }
 return c;
}

int main(){
	int leap, hulu, bulu, flag=0;
	while(scanf("%s", s)==1 ){
		if(flag)
			printf("\n");
		flag=1;
		leap=0; hulu=0; bulu=0;
			if( (mod(s, 4)==0 && mod(s, 100)!=0) || (mod(s, 400)==0) ){
			 printf("This is leap year.\n");
	         leap=1;
		 }
		 if(mod(s, 15)==0){
			 printf("This is huluculu festival year.\n");
			 hulu=1;
		 }
		 if(mod(s, 55)==0 && leap==1){
			 printf("This is bulukulu festival year.\n");
			 bulu=1;
		 }
	 if(hulu!=1 && bulu!=1 && leap!=1){
		 printf("This is an ordinary year.\n");
	 }
	 //printf("\n");
 }
 return 0;
}
