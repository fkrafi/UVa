#include<stdio.h>
#include<time.h>

int h[100000][3], s[10000];

int search(int s[], int sz, int z)
{
	for(int i=0; i<sz; i++)
		if(s[i]==z)return 1;
	return 0;
}

int check(int n)
{
	int sz=0, sum, a;
	if(n==1)return 1;
	while(n!=1)
	{
		sum = 0;
		while(n)
		{
			a = n%10;
			sum += (a*a);
			n /= 10;
		}
		if(search(s, sz, sum))return -1;
		s[sz++] = sum;
		n = sum;
	}
	return (sz+1);
}

void generate()
{
	int i, cnt;
	for(i=1; i<=99999; i++)
	{
		cnt = check(i);
		if(cnt>=0)
		{
			h[i][0] = 1;
			h[i][1] = cnt;
		}
	}
}

int main()
{
	generate();
	int L, H, flag=0;
	while(scanf("%d%d", &L, &H) != EOF)
	{
		if(flag)printf("\n");
		flag = 1;
		for(int i=L; i<=H; i++)
			if(h[i][0])
				printf("%d %d\n", i, h[i][1]);
	}
	return 0;
}