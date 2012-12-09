#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


char s[100];
string a, b, c, store[1000];

bool comp(char a, char b)
{
	return a>b;
}

string subtract(string a,string b)
{
	string c;
	int i,j,k,carry,len1=a.length(),len2=b.length(),maxlen=len2>len1 ? len2 : len1;
    for(carry=i=0;i<maxlen || carry;i++)
	{
		j= i<len1 ? a[len1-i-1]-'0':0;
        k= i<len2 ? b[len2-i-1]-'0':0;
		k+=carry;
		
		if(j<k) c+= 10+j-k+'0',carry=1;
		else c+=j-k+'0',carry=0;
	}
	for(j=c.length(),i=j-1;i>=0;i--) if(c[i]!='0') break;
	if(i<j-1) j=i+1;  
	if(j==0) j++;
	for(k=j/2,i=0;i<k;i++) swap(c[i],c[j-i-1]);
	return c.substr(0,j);
}

int chk(int sz)
{
	for(int i=0; i<sz; i++)
		if(store[i] == c)return 1;
		return 0;
}

void lead_zero(string temp)
{
	if(temp[0] != '0')return;
	int l=temp.length(), i=1, j=0;
	char t[1000];
	while(i<l && temp[i] == '0')i++;
	if(i>=l)return;
	for(; i<l; i++)
		t[j++] = temp[i];
	t[j] = '\0';
	a = string(t);
}


int main()
{
	freopen("263.txt", "r", stdin);
	int sz;
	while(gets(s))
	{
		if(s[0] == '0')break;
		a = b = string(s);
		sz = 0;
		store[sz++] = a;
		printf("Original number was %s\n", s);
		while(1)
		{
			sort(a.begin(), a.end());
			sort(b.begin(), b.end(), comp);
			lead_zero(a);
			c = subtract(b, a);
			cout << b << " - " << a << " = " << c << "\n";
			if(chk(sz))break;
			store[sz++] = c;
			a = b = c;
		}
		printf("Chain length %d\n\n", sz);
	}
	return 0;
}