#include<stdio.h>
#include<string.h>


int num[110];
char s[100000];

long int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int s2i(char pch[]){
	int n=0, i, l=strlen(pch);
	for(i=0; i<l; i++)
		n = n*10 + (pch[i]-48);
	return n;
}

int split(){
	int i=0, l=strlen(s);
	char *pch;
	pch = strtok(s, " ");
	while(pch != NULL){
		num[i++] = s2i(pch);
		pch = strtok(NULL, " ");
	}
	return i;
}

int main()
{
	freopen("11827.txt", "r", stdin);
	int i, j, max, k, t, g;
	scanf("%d", &t);getchar();
	while(t--)
	{
		gets(s);
		i = split();
		max = -1;
		for(j=0; j<i; j++)
		{
			for(k=j+1; k<i; k++)
			{
				g = gcd(num[j], num[k]);
				if(g > max)max = g;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}