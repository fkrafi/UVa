#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int s[3], t, i, j;
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		for(j=0; j<3; j++)
			scanf("%d", &s[j]);
		sort(s, s+3);
		printf("Case %d: %d\n", i, s[1]);
	}
	return 0;
}