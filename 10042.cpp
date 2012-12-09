#include<stdio.h>
#include<math.h>


int isPrime(int n){
	if(n==1)return 0;
	if(n%2==0)return 0;
	int l = int(sqrt(n));
	for(int i=3; i<=l; i+=2){
		if(n%i==0)return 0;
	}
	return 1;
}

int factors(int n){
	int sum=0, l, i, t;
	l = int(sqrt(n));
	while(!(n%2)){
		sum += 2;
		n /= 2;
	}
	for(i=3; i<=l; i+=2){
		if(n==1)break;
		while(!(n%i)){
			t = i;
			while(t){
				sum += t%10;
				t /= 10;
			}
			n /= i;
		}
	}
	if(n!=1){
		while(n){
			sum += n%10;
			n /= 10;
		}
	}
	return sum;
}

int digitSum(int n){
	int sum=0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
	int t, i, n, j, s, f;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d", &n);
		if(n<=2)n=3;
		for(j=n+1; ; j++){
			if(!isPrime(j)){
				s = digitSum(j);
				f = factors(j);
				if(s == f){
					printf("%d\n", j);
					break;
				}
			}
		}
	}
	return 0;
}