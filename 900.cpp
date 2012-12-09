#include<stdio.h>

double way[60];

void generate_wat(int n)
{
	int i;
	way[1] = 1;
	way[2] = 2;
	for(i=3; i<=n; i++)
		way[i] = way[i-1] + way[i-2];
}

int main()
{
	generate_wat(50);
	int n;
	while(scanf("%d", &n))
	{
		if(!n)break;
		printf("%.0lf\n", way[n]);
	}
	return 0;
}