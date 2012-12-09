#include<stdio.h>
#include<math.h>


int a[1000001];

int prime(int n){
	int i, s, c=1;
	if(n<=1)return 0;
	if(n==2)return 1;
	s = int(sqrt(n));
	for(i=2; i<=s+1; i++){
		if(n%i==0){
			c = 0;
			break;
		}
	}
	return c;
}

void allPrimes(){
	int i, l, count=0, sum, temp;
	for(i=0; i<=1000000; i++){
		if(i==2 || i%2){
			l = prime(i);
			if(l == 1){
				sum = 0;
				temp = i;
				while(temp){
					sum += (temp%10);
					temp /= 10;
				}
				l = prime(sum);
				if(l == 1)count++;
			}
		}
		a[i] = count;
	}
}

int main(){
	int t1, t2, n, res, i;
	allPrimes();
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d%d", &t1, &t2);
		res = a[t2] - a[t1-1];
		printf("%d\n", res);
	}
	return 0;
}
