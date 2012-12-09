#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

double pay[256];
char str[100010];

void init()
{
	int i;
	for(i=0; i<256; i++)pay[i] = -1.0;
}

int main()
{
	freopen("11340.txt", "r", stdin);
	int t, i, nC, nL, in, l, j;
	char u[3], ch;
	double b, payment;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &nC);getchar();
		init();
		for(i=0; i<nC; i++)
		{
			scanf("%s%lf", u, &b);
			in = u[0];
			pay[in] = b/100;
		}
		scanf("%d", &nL);
		getchar();
		payment = 0;
		for(i=0; i<nL; i++)
		{
			gets(str);
			l = strlen(str);
			for(j=0; j<l; j++)
				if(pay[str[j]] != -1)
					payment += pay[str[j]];
		}
		printf("%.2lf$\n", payment);
	}
	return 0;
}