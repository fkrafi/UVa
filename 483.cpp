#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char str[10000000], s[100000000];

void end_space(int len)
{
	int i=len-1;
	while(!i && (str[i]==' ' || str[i]=='\t'))i--;
	str[i+1]='\0';
}

int main()
{
	freopen("483.txt", "r", stdin);
	freopen("483_out.txt", "w", stdout);
	int i, l, j;
	while(gets(str))
	{
		l = strlen(str);
		//end_space(l);
		for(i=0; i<l; i++)
		{
			if(str[i] != ' ')
			{
				j=0;
				do{
					s[j++] = str[i++];
				}while(i!=l && str[i]!=' ' && str[i]!='\t');
				s[j] = '\0';
				reverse(s, s+j);
				printf("%s", s);
				if(i<l)printf("%c", str[i]);
			}else{
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}