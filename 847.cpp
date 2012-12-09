#include<stdio.h>


void answer(int n){
	double last=1, temp=9;
	int i=1;
	while(1){
		if(last<=n && temp>=n)break;
		i++;
		last = temp;
		temp*= (i%2==0)? 2 : 9;
	}
	if( i%2 )
		puts("Stan wins.");
	else
		puts("Ollie wins.");
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		answer(n);
	}
	return 0;
}