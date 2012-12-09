#include<stdio.h>
#define SZ 100000007

int ne[SZ], de[SZ];

void init()
{
	int i, n=1, d=1, hn=1, hd=2, conN=1, conD=1;
	for(i=1; i<=10000000; i++)
	{
		if(!n){n=1; conN=1; hn+=2;}
		if(!d){d=1; conD=1; hd+=2;}
		ne[i] = n;
		de[i] = d;

		if(n>=hn)conN = 0;
		if(conN)n++;
		else n--;

		if(d>=hd)conD = 0;
		if(conD)d++;
		else d--;
	}
}

int main()
{
	int n;
	init();
	while(scanf("%d", &n) != EOF)
	{
		printf("TERM %d IS %d/%d\n", n, ne[n], de[n]);
	}
	return 0;
}