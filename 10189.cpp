#include<stdio.h>
#include<string.h>

char str[1000][1000], ch;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(int n, int m)
{
	int i, j;
	i=j=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			while(1)
			{
				scanf("%c", &str[i][j]);
				if(str[i][j] == '.' || str[i][j] == '*')
					break;
			}
		}
	}
}

int main()
{
	int i, j, n, m, count, c=0, u, v, k;
	while(scanf("%d%d", &n, &m))
	{
		if(n==0 && m==0)break;
		input(n, m);
		if(c>0)printf("\n");
		c++;
		printf("Field #%d:\n", c);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(str[i][j]=='*')
				{
					printf("*");
				}else{
					count = 0;
					for(k=0; k<8; k++)
					{
						u = i + dr[k];
						v = j + dc[k];
						if(u<0 || u>=n || v<0 || v>=m)continue;
						if(str[u][v] == '*')
							count++;
					}
					printf("%d", count);
				}
			}
			printf("\n");
		}
	}
	return 0;
}