#include<stdio.h>
#include<string>
using namespace std;

char line[100010], line1[100010];

int main()
{
	freopen("11074.txt", "r", stdin);
	freopen("11074_out.txt", "w", stdout);
	int s, t, n, i, j, l, cs=1, sz;
	while(scanf("%d%d%d", &s, &t, &n))
	{
		if(!s && !t && !n)break;
		l = n*s + (n+1)*t;
		for(i=0; i<l; i++)
			line[i] = '*';
		line[i] = '\0';
		l = 2*n+1;
		sz = 0;
		for(i=0; i<l; i++)
		{
			if(!(i%2))
			{
				for(j=0; j<t; j++)
					line1[sz++] = '*';
			}
			else
			{
				for(j=0; j<s; j++)
					line1[sz++] = '.';
			}
		}
		line1[sz] = '\0';
		printf("Case %d:\n", cs++);
		for(i=0; i<l; i++)
		{
			if(!(i%2))
			{
				for(j=0; j<t; j++)
					puts(line);
			}
			else
			{
				for(j=0; j<s; j++)
					puts(line1);
			}
		}
		printf("\n");
	}
	return 0;
}