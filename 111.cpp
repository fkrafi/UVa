#include<stdio.h>

int a[25], arr[25], b[25];
int lcs[25][25];

int max(int a, int b)
{
	if(a>b)return a;
	return b;
}

int dp(int n)
{
	int i, j;
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=n; j++)
		{
			if(i>0 && j>0)
			{
				if(a[i] == b[j])
					lcs[i][j] = lcs[i-1][j-1] + 1;
				else
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}else{lcs[i][j] = 0;}
		}
	}
	return lcs[n][n];
}

int input(int i, int n)
{
	int j;
	if(!i){
		for(j=1; j<=n; j++){
			scanf("%d", &arr[j]);
			a[arr[j]] = j;
		}
	}else{
		j = 1;
		while(scanf("%d", &arr[j]) != EOF){
			b[arr[j]] = j;
			j++;
			if(j>n)break;
		}
		if(j==1)return 1;
		printf("%d\n", dp(n));
	}
	return 0;
}

int main()
{
	freopen("111.txt", "r", stdin);
	int n, i;
	scanf("%d", &n);
	for(i=0; ; i++)
	{
		if(input(i, n))break;
	}
	return 0;
}