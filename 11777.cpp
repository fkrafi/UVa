#include<stdio.h>
#include<algorithm>
using namespace std;

void grade(int n)
{
	if(n>=90)printf("A\n");
	else if(n>=80)printf("B\n");
	else if(n>=70)printf("C\n");
	else if(n>=60)printf("D\n");
	else printf("F\n");
}

int main()
{
	int i, j, t;
	double num[10], test, total;
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		for(j=0; j<7; j++)
			scanf("%lf", &num[j]);
		sort(num+4, num+7);
		test = num[5] + num[6];
		total = 0;
		for(j=0; j<4; j++)
			total += num[j];
		total += (test/2);
		printf("Case %d: ", i);
		grade(total);
	}
	return 0;
}