#include<stdio.h>
#include<algorithm>
using namespace std;

int a[10];

int main()
{
	int t, i;
	scanf("%d", &t);
	while(t--)
	{
		for(i=0; i<4; i++)scanf("%d", &a[i]);
		sort(a, a+4);
		if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
			printf("square\n");
		else if(a[0]==a[1] && a[2]==a[3])
			printf("rectangle\n");
		else if(a[0]+a[1]+a[2] > a[3])
			printf("quadrangle\n");
		else
			printf("banana\n");
	}
	return 0;
}