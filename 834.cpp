#include<stdio.h>

int main()
{
	int a, b, r, d, con;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		con = 1;
		d = a/b;
		r = a%b;
		printf("[%d;", d);
		a = b;
		b = r;
		while(r)
		{
			con = 0;
			d = a/b;
			r = a%b;
			if(r)
				printf("%d,", d);
			else
				printf("%d]\n", d);
			a = b;
			b = r;
		}
		if(con)
			printf("1]\n");
	}
	return 0;
}