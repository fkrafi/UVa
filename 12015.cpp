#include<stdio.h>
#include<string.h>

struct store{
	char add[150];
	int pr;
}url[15];

int main(){
	freopen("12015.txt", "r", stdin);
	int t, cs, i, max;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		printf("Case #%d:\n", cs);
		max = -1;
		for(i=1; i<=10; i++)
		{
			scanf("%s%d", url[i].add, &url[i].pr);
			if( max < url[i].pr )
				max = url[i].pr;
		}
		for(i=1; i<=10; i++)
			if(url[i].pr == max)
				puts(url[i].add);
	}
	return 0;
}