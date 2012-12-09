#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

char s[1000], temp[110];
string bS[5], eS[4];
string str[110];
void init()
{
	bS[0] = "#include<string.h>";
	bS[1] = "#include<stdio.h>";
	bS[2] = "int main()";
	bS[3] = "{";
	eS[0] = "printf(\"\\n\");";
	eS[1] = "return 0;";
	eS[2] = "}";
}

void print_begin()
{
	int i;
	for(i=0; i<4; i++)
		cout << bS[i] << "\n";
}

void print_end()
{
	int i;
	for(i=0; i<3; i++)
		cout << eS[i] << "\n";
}

int main()
{
	freopen("11483.txt", "r", stdin);
	freopen("11483_out.txt", "w", stdout);
	init();
	int i, n, sz, k, j, l, cs=1;
	while(scanf("%d", &n))
	{
		getchar();
		if(!n)break;
		sz = 0;
		for(i=0; i<n;)
		{
			gets(s);
			l = strlen(s);
			if(l)
			{
				i++;
				str[sz] = "printf(\"";
				k = 0;
				for(j=0; j<l; j++)
				{
					if(s[j]=='\"' || s[j]=='\\' || s[j]==34 || s[j]==-109 || s[j]==-108)
						temp[k++] = '\\';
					if(s[j]==-109 || s[j]==-108)
						temp[k++] = '\"';
					else
						temp[k++] = s[j];
				}
				temp[k] = '\0';
				str[sz] += string(temp) + "\\n\");";
				sz++;
			}
		}
		printf("Case %d:\n", cs++);
		print_begin();
		for(i=0; i<sz; i++)
			cout << str[i] << "\n";
		print_end();
	}
	return 0;
}