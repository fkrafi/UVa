#include<stdio.h>
#include<math.h>
typedef long long int LL;

LL sum;
LL d[100005], sig[100005];

LL nod(LL n)
{
	LL ret=1, cnt=0, i, s=LL(sqrt(n))+1, t=n, p;
	if(n==1){
		sum = 1;
		return 1;
	}
	if(n<=3){
		sum = n+1;
		return 2;
	}
	sum = 1;
	while(n%2==0)
	{
		n/=2;
		cnt++;
	}
	if(cnt){
		ret *= (cnt+1);
		p = 1;
		cnt++;
		while(cnt--)p*=2;
		sum *= ((p-1)/(2-1));
	}
	for(i=3; i<=s; i+=2)
	{
		cnt = 0;
		while(n%i==0)
		{
			cnt++;
			n /= i;
		}
		if(cnt){
			ret *= (cnt+1);
			p = 1;
			cnt++;
			while(cnt--)p*=i;
			sum *= ((p-1)/(i-1));
		}
	}
	if(t==n){
		sum = t+1;
		return 2;
	}
	if(n>1){
		sum *= ( (n*n-1)/(n-1) );
		return ret*2;
	}
	return ret;
}

void dp(){
	LL i;
	for(i=1; i<=100000; i++){
		d[i] = nod(i);
		sig[i] = sum;
	}
}

void gh(LL a, LL b, LL k){
	LL i, ans1=0, ans2=0;
	for(i=a; i<=b; i++){
		if( i%k )continue;
		ans1 += d[i];
		ans2 += sig[i];
	}
	printf("%lld %lld\n", ans1, ans2);
}

int main(){
	freopen("D.txt", "r", stdin);
	LL t, a, b, k;
	dp();
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld", &a, &b, &k);
		gh(a, b, k);
	}
	return 0;
}