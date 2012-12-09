#include<stdio.h>
#include<math.h>

struct factors
{
	int num, cnt;
}f[1000000];

int sz;

int factor(int n)
{
	int s= int(sqrt(n)), i, j=0;
	if(n%2==0)
	{
		f[j].num = 2;
		f[j].cnt = 0;
		while(n%2==0)
		{
			f[j].cnt++;
			n /= 2;
		}
		j++;
	}
	for(i=3; i<=s; i+=2)
	{
		if(n%i==0)
		{
			f[j].num = i;
			f[j].cnt = 0;
			while(n%i==0)
			{
				f[j].cnt++;
				n /= i;
			}
			j++;
		}
	}
	if(n>1)
	{
		f[j].num = n;
		f[j].cnt = 1;
		j++;
	}
	return j;
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int n, g, i, sign;
	while(scanf("%d", &n))
	{
		if(!n)break;
		sign = 0;
		if(n<0)
		{
			n *= -1;
			sign = 1;
		}
		sz = factor(n);
		if(sz<2){
			g = f[0].cnt;
			while(sign && g%2==0)
				g /= 2;
			printf("%d\n", g);
		}else{
			g = f[0].cnt;
			for(i=1; i<sz; i++)
				g = gcd(g, f[i].cnt);
			while(sign && g%2==0)
				g /= 2;
			printf("%d\n", g);
		}
	}
	return 0;
}
