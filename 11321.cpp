#include<stdio.h>
#include<algorithm>
using namespace std;


int a[10002], n, m;

bool comp(int x, int y)
{
	int k=x%m, l=y%m;
	if(k == l)
	{
		if(abs(x%2)==1 && y%2==0)return 1;
		if(x%2==0 && abs(y%2)==1)return 0;
		if(abs(x%2)==1 && abs(y%2)==1)return x>y;
		if(x%2==0 && y%2==0)return x<y;
	}
	return k<l;
}


int main()
{
	freopen("11321.txt", "r", stdin);
	int i;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m)
		{
			printf("%d %d\n", n, m);
			break;
		}
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n, comp);
		printf("%d %d\n", n, m);
		for(i=0; i<n; i++)
			printf("%d\n", a[i]);
	}
	return 0;
}