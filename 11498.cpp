#include<stdio.h>

int main()
{
	freopen("11498.txt", "r", stdin);
	int k, i, m, n, x, y;
	while(scanf("%d", &k))
	{
		if(!k)break;
		scanf("%d%d", &m, &n);
		for(i=0; i<k; i++)
		{
			scanf("%d%d", &x, &y);
			if(x==m || y==n)
				printf("divisa\n");
			else if(x<m && y>n)
				printf("NO\n");
			else if(x>m && y>n)
				printf("NE\n");
			else if(x>m && y<n)
				printf("SE\n");
			else
				printf("SO\n");
		}
	}
	return 0;
}