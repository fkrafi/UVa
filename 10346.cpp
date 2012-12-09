#include<stdio.h>


int main()
{
	freopen("10346.txt", "r", stdin);
	int n, k, no;
	while(scanf("%d%d", &n, &k) != EOF)
	{
		no = n;
		while(n>=k)
		{
			no += n/k;
			n = n/k + n%k;
		}
		printf("%d\n", no);
	}
	return 0;
}