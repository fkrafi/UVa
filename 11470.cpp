#include<stdio.h>
#include<math.h>

int n[12][12], st[10], et[10], len, sz, pos;
double sum[10];

int position(int i, int j)
{
	for(int k=1; k<=len; k++)
	{
		if(i==st[k] || i==et[k] || j==st[k] || j==et[k])
			return k;
	}
	return 0;
}

void gen()
{
	for(int i=1; i<=len; i++)
	{
		st[i] = i;
		et[i] = sz - i + 1;
		sum[i] = 0;
	}
}

int main()
{
	int i, j, C=1;

	freopen("input.txt","r",stdin);

	while(scanf("%d", &sz))
	{
		if(!sz)break;
		len = int(ceil(double(sz)/2.0));
		gen();
		for(i=1; i<=sz; i++)
		{
			for(j=1; j<=sz; j++)
			{
				scanf("%d", &n[i][j]);
				pos = position(i, j);
				sum[pos] += n[i][j];
			}
		}
		printf("Case %d:", C++);	// you have done a great silly mistake, you wrote this printf("Case 1:",C++);
		for(i=1; i<=len; i++)
			printf(" %.0lf", sum[i]);
		printf("\n");
	}
	return 0;
}