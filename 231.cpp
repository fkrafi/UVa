#include<stdio.h>

int a[10010], best[10010];

int lis(int a[], int N)
{
	int i, j, ans=0;
	for(i=0; i<N; i++)
		best[i] = 1;
	for(i=1; i< N; i++){
		for(j=0; j<i; j++ ){
			if(a[i]<=a[j] && best[i]<best[j]+1){
				best[i] = best[j] + 1;
				if(ans<best[i])ans = best[i];
			}
		}
	}
	return ans;
}

int main()
{
	freopen("231.txt", "r", stdin);
	int prev, cur, cnt, test=1, i;
	while(1)
	{
		prev = 32775;
		cnt = 0;
		i = 0;
		while(scanf("%d", &cur))
		{
			if(cur < 0)break;
			a[i++] = cur;
			prev = cur;
		}
		if(prev == 32775)break;
		if(test!=1)printf("\n");
		cnt = lis(a, i);
		printf("Test #%d:\n  maximum possible interceptions: %d\n", test++, cnt);
	}
	return 0;
}