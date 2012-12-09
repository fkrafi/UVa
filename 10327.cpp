#include<stdio.h>

int a[1010];

int bubble_sort(int n)
{
	int cnt=0, k=n, j, t;
	while(k)
	{
		t = 0;
		for(j=1; j<k; j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				t = j;
				cnt++;
			}
		}
		k = t;
	}
	return cnt;
}

int main()
{
	int i, n;
	while(scanf("%d", &n) != EOF)
	{
		for(i=1; i<=n; i++)
			scanf("%d", &a[i]);
		printf("Minimum exchange operations : %d\n", bubble_sort(n));
	}
	return 0;
}