#include<stdio.h>

int chk[3005];

int abs(int n)
{
	if(n<0)return -n;
	return n;
}

int main()
{
	freopen("10038.txt", "r", stdin);
	freopen("10038_out.txt", "w", stdout);
	int cs=1, prev, in, a, n, i, con;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &prev);
		con = 1;
		for(i=1; i<n; i++)
		{
			scanf("%d", &a);
			in = abs( prev - a );
			if(chk[in] != cs && in<n)
				chk[in] = cs;
			else
				con = 0;
			prev = a;
		}
		if(con)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
		cs++;
	}
	return 0;
}