#include<stdio.h>

struct store{
	int i, v, x, l, c;
}res[101];
int t;

int I(int n)
{
	if(n && n<4)
		return n;
	if(n==4 || n==9)return 1;
	if(n>=6 && n<=8)return n-5;
	return 0;
}

int V(int n)
{
	if(n<=3 || n>=9)return 0;
	return 1;
}

int X(int n)
{
	if( (t>=50 && t<60))return 0;
	if(t>=90 && t<100)return 1;
	if(t>=60)return (n-5);
	if(t<40)
		return n;
	return 1;
}

int L()
{
	if(t<40 || t>=90)return 0;
	return 1;
}

int C()
{
	if(t<90)return 0;
	return 1;
}

void generate()
{
	int i;
	for(i=1; i<100; i++)
	{
		t = i;
		res[i].i = res[i-1].i + I(i%10);
		res[i].v = res[i-1].v + V(i%10);
		if(i%10==9)
		{
			res[i].x = res[i-1].x + X((i/10)%10);
			res[i].x++;
		}
		else
			res[i].x = res[i-1].x + X((i/10)%10);
		res[i].l = res[i-1].l + L();
		res[i].c = res[i-1].c + C();
	}
	res[i].i = res[i-1].i;
	res[i].v = res[i-1].v;
	res[i].x = res[i-1].x;
	res[i].l = res[i-1].l;
	res[i].c = res[i-1].c + 1;
}

int main()
{
	freopen("344.txt", "r", stdin);
	freopen("344_out.txt", "w", stdout);
	int n;
	generate();
	while(scanf("%d", &n))
	{
		if(!n)break;
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, res[n].i, res[n].v, res[n].x, res[n].l, res[n].c);
	}
	return 0;
}