#include<stdio.h>
#include<algorithm>
using namespace std;

double h[6000];
double a[] = {2,3,5, 7};


void suf(int n, int nn)
{
	if(nn==1)printf("th");
	else if(n==1)printf("st");
	else if(n==2)printf("nd");
	else if(n==3)printf("rd");
	else printf("th");
}

int search(int sz, double z)
{
	for(int i=1; i<sz; i++)
		if(h[i] == z)return 0;
	return 1;
}


void gen()
{
	int i, j=2, k;
	double temp;
	h[1] = 1;
	for(i=1; i<j && j<=5843; i++)
	{
		for(k=0; k<4; k++)
		{
			if(j>5843)break;
			temp = h[i] * a[k];
			if(temp <= 2000000000 && search(j, temp))
				h[j++] = temp;
		}
	}
	sort(h, h+5843);
}


int main()
{
	freopen("1005.txt", "r", stdin);
	gen();
	int n;
	while( scanf("%d", &n) )
	{
		if(!n)break;
		printf("The %d", n);
		suf(n%10, (n%100)/10);
		printf(" humble number is %.0lf.\n", h[n]);
	}
	return 0;
}