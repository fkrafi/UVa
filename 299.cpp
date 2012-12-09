#include<stdio.h>

int no_swap;
int l[100];
void sort(int sz)
{
	int k=sz, t, i;
	while(k)
	{
		t = 0;
		for(i=1; i<k; i++)
		{
			if(l[i] > l[i+1])
			{
				t = l[i];
				l[i] = l[i+1];
				l[i+1] = t;
				no_swap++;
				t = i;
			}
		}
		k = t;
	}
}


int main()
{
	int t, sz, i;
	scanf("%d", &t);
	while(t--)
	{
		no_swap = 0;
		scanf("%d", &sz);
		for(i=1; i<=sz; i++)
			scanf("%d", &l[i]);
		sort(sz);
		printf("Optimal train swapping takes %d swaps.\n", no_swap);
	}
	return 0;
}