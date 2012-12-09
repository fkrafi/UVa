#include<stdio.h>
#include<string.h>
#include<math.h>

int change(char c){
	int i;
	if(c>='A' && c<='Z'){
		i = c - 38;
	}else{
		i = c - 96;
	}
	return i;
}


void prime(int n){
	int i, s, con=1;
	s = int(sqrt(n));
	for(i=2; i<=s; i++){
		if(n%i==0){
			con = 0;
			break;
		}
	}
	if(con==1){
		printf("It is a prime word.\n");
	}else{
		printf("It is not a prime word.\n");
	}
}
char s[1000];

int main(){
	int i, l, sum;
	while(gets(s)){
		sum = 0;
		l = strlen(s);
		for(i=0; i<l; i++){
			sum += change(s[i]);
		}
		prime(sum);
	}
	return 0;
}