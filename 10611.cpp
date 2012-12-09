#include<stdio.h>

int h[50010];

void binary_search(int cp, int n)
{
	int m, flag=0, l=1, e=n, con=0;
	while(l<=e && !flag)
	{
		m = (l+e)/2;
		if(h[m]==cp){
			while(h[m-1]==cp && m>=0)m--;
			if(h[m-1]==cp || h[m-1]<0)
				printf("X ");
			else
				printf("%d ", h[m-1]);
			
			while(h[m+1]==cp && m>=0)m++;
			if(h[m+1]==cp || h[m+1]<0)
				printf("X\n");
			else
				printf("%d\n", h[m+1]);

			flag = 1;
		}else if(h[m]<cp)
			l = m + 1;
		else
			e = m - 1;
	}
	if(!flag)
	{
		if(h[m]>cp)
		{
			if(h[m-1]>0)
				printf("%d ", h[m-1]);
			else
				printf("X ");

			if(h[m]>0)
				printf("%d\n", h[m]);
			else
				printf("X\n");
		}else{
			if(h[m]>0)
				printf("%d ", h[m]);
			else
				printf("X ");
			if(h[m+1]>0)
				printf("%d\n", h[m+1]);
			else
				printf("X\n");
		}
	}
}

int main()
{
	int n, q, i, cp;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%d", &h[i]);
	h[0] = h[n+1] = -1;
	scanf("%d", &q);
	for(i=0; i<q; i++)
	{
		scanf("%d", &cp);
		binary_search(cp, n);
	}
	return 0;
}