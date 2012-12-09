#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<string>
#include<map>

using namespace std;

string store[100005];
map <string, int> s;

int main()
{
	int i, j, k, p, len;
	char str1[100], str2[100];

	s.clear();

	freopen("input.txt","r",stdin);
	for(i=1; ;i++)
	{
		gets(str1);
		
		if(str1[0]==0)
			break;
		len  = strlen(str1);

		for(j=0; str1[j]!=' '; j++);
		
		for(k = 0,p=j+1; p<=len; k++,p++)
			str2[k] = str1[p];

		str1[j] = '\0';

		store[i] = str1;
		s[str2] = i;
	}

	while(gets(str2))
	{
		if(s[str2]!=0)
			printf("%s\n",store[s[str2]].c_str());
		else
			printf("eh\n");
	}
	return 0;
}