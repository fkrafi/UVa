#include<stdio.h>
#include<algorithm>
using namespace std;

int a[100000];

int main()
{
	int i=0, pos, sum;
	while(scanf("%d", &a[i++]) != EOF)
	{
		if(i!=1 && a[i-1]<a[i-2])
			sort(a, a+i);
		if(i%2)
		{
			pos = (i+1)/2;
			printf("%d\n", a[pos-1]);
		}else{
			pos = i/2;
			sum = (a[pos-1] + a[pos])/2;
			printf("%d\n", sum);
		}
	}
	return 0;
}