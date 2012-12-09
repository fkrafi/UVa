#include<stdio.h>

struct array
{
	int n, cnt;
}a[10000000];

int main()
{
	int d, i, j=0;
	while(scanf("%d", &d) == 1)
	{
		for(i=0; i<j; i++)
		{
			if(a[i].n == d)break;
		}
		if(i==j)
		{
			a[j].n = d;
			a[j++].cnt = 1;
		}else
			a[i].cnt++;
	}
	for(i=0; i<j; i++)
		printf("%d %d\n", a[i].n, a[i].cnt);
	return 0;
}