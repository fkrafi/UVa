#include<stdio.h>


int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		n *= 63;
		n += 7492;
		n *= 5;
		n = n-498;
		n = (n%100)/10;
		if(n<0)n*=-1;
		printf("%d\n", n);
	}
	return 0;
}