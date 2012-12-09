#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int prime(int n){
	int i, c=1, s;
	s = int(sqrt(n));
	for(i=2; i<=s; i++){
		if(n%i==0){
			c=0;
			break;
		}
	}
	if(c==1){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int n, n2, t, i;
	char s[10];
	while(scanf("%d", &n) != EOF){
		t = n; i = 0;
		while(t){
			s[i++] = ((t%10) + 48);
			t = t/10;
		}
		s[i] = '\0';
		n2 = atoi(s);
		if(prime(n)==0){
			printf("%d is not prime.\n", n);
		}else if(prime(n)==1 && prime(n2)==1 && n>9 && n!=n2){
			printf("%d is emirp.\n", n);
		}else if(prime(n)==1){
			printf("%d is prime.\n", n);
		}
	}
	return 0;
}