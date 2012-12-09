#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 505

int s[SZ];

int abs(int n)
{
	return (n<0)?-n:n;
}

int main()
{
	freopen("10041.txt", "r", stdin);
	int r, i, t, m, dis;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &r);
		for(i=1; i<=r; i++)scanf("%d", &s[i]);
		sort(s+1, s+r+1);
		m = r/2;
		if(r%2)m++;
		dis = 0;
		for(i=1; i<m; i++)
			dis += abs(s[i]-s[m]);
		for(i=m+1; i<=r; i++)
			dis += abs(s[i]-s[m]);
		printf("%d\n", dis);
	}
	return 0;
}