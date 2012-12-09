#include<stdio.h>
#include<math.h>

//typedef __int64 LL;
typedef long long int LL;

int main(){
	int t;
	LL n, res;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		res = LL(sqrt(1+8*n));
		res = (res-1)/2;
		printf("%lld\n", res);
	}
	return 0;
}