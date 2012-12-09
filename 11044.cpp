#include<stdio.h>

int main()
{
	freopen("11044.txt", "r", stdin);
	int t, n, m, a, b, r;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		n -= 2;
		a = 0;
		if(n%3)a++;
		a += n/3;
		m -= 2;
		b = 0;
		if(m%3)b++;
		b += m/3;
		r = a*b;
		printf("%d\n", r);
	}
	return 0;
}