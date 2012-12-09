#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[10000];

int main()
{
	int t, l;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", s);
		l = strlen(s);
		sort(s, s+l);
		do{
			printf("%s\n", s);
		}while(next_permutation(s, s+l));
		printf("\n");
	}
	return 0;
}