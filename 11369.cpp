#include<stdio.h>
#include<algorithm>
using namespace std;

bool comp(int a, int b)
{
	return a>b;
}

int arr[20005];

int main()
{
	int t, n, i;
	double max;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n, comp);
		max = 0;
		for(i=2; i<n; i+=3)
			max += arr[i];
		printf("%.0lf\n", max);
	}
	return 0;
}