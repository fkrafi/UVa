#include<stdio.h>


long long int a[12];


long long int gcd(long long int a, long long int b){
	if(!a)return b;
	return gcd(b%a, a);
}

long long int lcm(long long int a, long long int b){
	return (a*b)/gcd(a, b);
}

int main(){
	freopen("12068.txt", "r", stdin);
	long long int S, N, i, l, cs=1, Hn, Hd, num, dem;
	scanf("%lld", &S);
	while( S-- ){
		scanf("%lld", &N);
		
		for(i=1; i<=N; i++)scanf("%lld", &a[i]);
		
		l = a[1];
		for( i=2; i<=N; i++ ){
			l = lcm(l, a[i]);
		}
		num = l*N;
		dem = 0;
		for(i=1; i<=N; i++)
			dem += (l/a[i]);
		
		l = gcd(num, dem);
		if( l>1 ){
			num /= l;
			dem /= l;
		}
		printf("Case %lld: %lld/%lld\n", cs++, num, dem);
	}
	return 0;
}