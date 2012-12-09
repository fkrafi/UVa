#include<stdio.h>
#include<string.h>

char s[1000];

int main(){
	int i, j, c, l, t;

	scanf("%d", &t);

	for(i=1; i<=t; i++){
		if(i==1){
			gets(s); gets(s);
		}else{
			gets(s);
		}
		l = strlen(s); c=0;
		for(j=0; j<l; j++){
			if(s[j]=='a' || s[j]=='d' || s[j]=='g' || s[j]=='j' || s[j]=='m' || s[j]=='p' || s[j]=='t' || s[j]=='w' || s[j]==' '){
				c += 1;
			}else if(s[j]=='b' || s[j]=='e' || s[j]=='h' || s[j]=='k' || s[j]=='n' || s[j]=='q' || s[j]=='u' || s[j]=='x'){
				c += 2;
			}else if(s[j]=='c' || s[j]=='f' || s[j]=='i' || s[j]=='l' || s[j]=='o' || s[j]=='r' || s[j]=='v' || s[j]=='y'){
				c += 3;
			}else{
				c += 4;
			}
		}
		printf("Case #%d: %d\n", i, c);
	}
	return 0;
}