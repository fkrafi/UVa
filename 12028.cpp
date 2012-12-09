#include<stdio.h>
#include<algorithm>
using namespace std;

long long int a[1000005];

bool comp(long long int a, long long int b){
	return a>b;
}

int main(){
	freopen("12028.txt", "r", stdin);
	long long int t, cs, i, K, C, n, sum, res;
	scanf("%lld", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%lld%lld%lld%lld", &K, &C, &n, &a[0]);
		sum = a[0];
		for(i=1; i<n; i++){
			a[i] = (K*a[i-1] + C)%1000007;
			sum += a[i];
		}		
		sort(a, a+n, comp);
		res = 0;
		for(i=0; i<n; i++){
			sum -= a[i];
			res += ((n-i-1)*a[i] - sum);
		}
		printf("Case %lld: %lld\n", cs, res);
	}
	return 0;
}