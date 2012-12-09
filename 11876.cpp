#include<stdio.h>
#include<math.h>
#include<time.h>
int ans[1000005];
int num[1000005];

int nod(int n)
{
	int ret=1, cnt=0, i, s=int(sqrt(n))+1, t=n;
	if(n==1)return 1;
	if(n==3)return 2;
	while(n%2==0)
	{
		n/=2;
		cnt++;
	}
	if(cnt)
		ret *= (cnt+1);
	for(i=3; i<=s; i+=2)
	{
		cnt = 0;
		while(n%i==0)
		{
			cnt++;
			n /= i;
		}
		ret *= (cnt+1);
	}
	if(t==n)return 2;
	if(n>1)return ret*2;
	return ret;
}


void generate()
{
	int i=1, j=2, n;
	ans[1] = 1;
	num[1] = 1;
	for(i=2; ; i++)
	{
		n = num[i-1] + nod(num[i-1]);
		if(n>=1000000)
			n = 1000000;
		for(; j<=n; j++)
			ans[j] = ans[j-1];
		if(n == 1000000)break;
		ans[n] = ans[n-1] + 1;
		num[i] = n;
	}
}

int main()
{
	freopen("11876.txt", "r", stdin);
	generate();
	int a, b, i, t;
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", i, (ans[b]-ans[a-1]));
	}
	return 0;
}