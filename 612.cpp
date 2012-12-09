#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct array
{
	char s[1000];
	int cnt, pos;
}a[110];

bool comp(array a, array b)
{
	if(a.cnt == b.cnt)
		return a.pos < b.pos;
	return a.cnt < b.cnt;
}

int main()
{
	freopen("612.txt", "r", stdin);
	int t, i, j, n, m, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%s", a[i].s);
			a[i].cnt = 0;
			for(j=0; j<n; j++)
			{
				for(k=j+1; k<n; k++)
				{
					if(a[i].s[j] > a[i].s[k])
						a[i].cnt++;
				}
			}
			a[i].pos = i;
		}
		sort(a, a+m, comp);
		for(i=0; i<m; i++)
			puts(a[i].s);
		if(t)printf("\n");
	}
	return 0;
}