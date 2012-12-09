#include<stdio.h>
#include<string.h>
#define SZ 1000002

int I, J, res[SZ];
char s[SZ];

void maxmin(int a, int b)
{
	if(a>b){
		J=a;
		I=b;
	}else{
		J=b;
		I=a;
	}
}


int main()
{
/*	freopen("10324.txt", "r", stdin);*/
	int l, q, i, j, c=1;
	while(gets(s))
	{
		l = strlen(s);
		if(l == 0)break;
		res[0] = 0;
		j = 0;
		for(i=1; i<l; i++)
		{
			if(s[i-1] != s[i])j++;
			res[i] = j;
		}
		scanf("%d", &q);
		printf("Case %d:\n", c++);
		while(q--)
		{
			scanf("%d%d", &i, &j);
			maxmin(i, j);
			j = res[J]-res[I];
			if(!j)
				printf("Yes\n");
			else
				printf("No\n");
		}
		getchar();
	}
	return 0;
}