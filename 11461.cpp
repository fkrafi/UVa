#include<stdio.h>
#include<math.h>

int res[100001];

void generate()
{
	int i, s, c=0;
	for(i=1; i<=100000; i++)
	{
		s = int(sqrt(i));
		if(s*s == i)
		{
			c++;
		}
		res[i] = c;
	}
}

int main()
{
	generate();
	int a, b;
	while(scanf("%d%d", &a, &b))
	{
		if(a==0 && b==0)
		{
			break;
		}
		if(a==0)
		{
			printf("%d\n", (res[b]-res[a]));
		}else{
			printf("%d\n", (res[b]-res[a-1]));
		}
	}
	return 0;
}