#include<stdio.h>
#define SZ 100

int n, r, c, error, nr, nc;
int a[SZ][SZ];

void row_chk()
{
	int i, j, s;
	for(i=1; i<=n; i++)
	{
		s=0;
		for(j=1; j<=n; j++)
		{
			scanf("%d", &a[i][j]);
			s += a[i][j];
		}
		if(s%2)
		{
			r = i;
			error = 1;
			nr++;
		}
	}
}

void col_chk()
{
	int i, j, s;
	for(i=1; i<=n; i++)
	{
		s = 0;
		for(j=1; j<=n; j++)
			s += a[j][i];
		if(s%2)
		{
			c = i;
			error = 1;
			nc++;
		}
	}
}

int chk()
{
	a[r][c] = ~a[r][c];
	int i, s1=0, s2=0;
	for(i=1; i<=n; i++)
	{
		s1 += a[r][i];
		s2 += a[i][c];
	}
	if(s1%2 || s2%2)return 0;
	return 1;
}

int main()
{
	freopen("541.txt", "r", stdin);
	while(scanf("%d", &n))
	{
		if(!n)break;
		error = nr = nc = 0;
		row_chk();
		col_chk();
		if(!error)
			printf("OK\n");
		else if( chk() && nr<=1 && nc<=1 )
			printf("Change bit (%d,%d)\n", r, c);
		else
			printf("Corrupt\n");

	}
	return 0;
}