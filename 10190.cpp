#include<stdio.h>
#include<math.h>

int num[10000000];

int check(int n, int d)
{
	if(n<=1 || d<=1)return -1;
	int sz=0;
	while(n%d==0)
	{
		n /= d;
		num[sz++] = n;
	}
	if(n!=1)return -1;
	return sz;
}

int main()
{
	int n, d, i,sz;
	while(scanf("%d%d", &n, &d) != EOF)
	{
		sz = check(n, d);
		if(sz<0)
			printf("Boring!");
		else{
			printf("%d", n);
			for(i=0; i<sz; i++)
				printf(" %d", num[i]);
		}
		printf("\n");
	}
	return 0;
}