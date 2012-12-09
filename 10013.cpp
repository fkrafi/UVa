#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string a, b, c;
char s1[1000010], s2[1000010];

string add(string a,string b)
{
	string c;
	int i,j,k,carry,len1=a.length(),len2=b.length(),maxlen=len2>len1 ? len2 : len1;

	for(carry=i=0;i<maxlen || carry;i++)
	{
		j= i<len1 ? a[len1-i-1]-'0':0;
        k= i<len2 ? b[len2-i-1]-'0':0;
		c+=((j+k+carry)%10)+'0';
	    carry=(j+k+carry)/10;
	}
	reverse(c.begin(),c.end());
	return c;
}

int main()
{
	freopen("10013.txt", "r", stdin);
	int t, i, n, len, n1, n2;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &n1, &n2);
			s1[i] = n1+48;
			s2[i] = n2+48;
		}
		s1[i] = '\0';
		s2[i] = '\0';
		a = string(s1);
		b = string(s2);
		c = add(a, b);
		len = c.length();
		if(len>n){
			for(i=len-n; i<len; i++)
				cout << c[i];
			printf("\n");
		}else{
			cout << c << "\n";
		}
		if(t)printf("\n");
	}
	return 0;
}