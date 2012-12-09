#pragma warning(disable : 4786)
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

struct store{
	int val, cnt;
}uni[11];

int n, sz;
int num[15], f[15];
map<int, int> M;
char s[100];

void fact()
{
	int i;
	f[0] = 1;
	for(i=1; i<=12; i++)
		f[i] = f[i-1] * i;
}

int cal(int val)
{
	int i, p=1;
	for(i=0; i<sz; i++)
	{
		if(uni[i].val == val)
			p *= f[uni[i].cnt-1];
		else
			p *= f[uni[i].cnt];
	}
	return (f[n-1]/p);
}

void lead_zero(int len)
{
	char t[100];
	int i=0, j;
	while(s[i] == '0')i++;
	if(i==0)return;
	if(i==len)
	{
		s[1] = '\0';
		return;
	}
	for(j=0; i<len; i++, j++)
		t[j] = s[i];
	t[j] = '\0';
	strcpy(s, t);
}

int main()
{
	freopen("11076.txt", "r", stdin);
	fact();
	int i, temp, carry, sum, len;
	while(scanf("%d", &n))
	{
		if(!n)break;
		M.clear();
		sz = 0;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &num[i]);
			if(M.find(num[i]) == M.end())
			{
				uni[sz].val = num[i];
				uni[sz].cnt = 0;
				M[num[i]] = sz++;
			}
			uni[M[num[i]]].cnt++;
		}
		sum = 0;
		for(i=0; i<sz; i++)
		{
			temp = cal(uni[i].val);
			sum += temp*uni[i].val;
		}
		carry = 0;
		len = 0;
		for(i=1; i<=n; i++)
		{
			temp = sum + carry;
			s[len++] = (temp%10) + 48;
			carry = temp/10;
		}
		while(carry)
		{
			s[len++] = (carry%10) + 48;
			carry /= 10;
		}
		s[len] = '\0';
		reverse(s, s+len);
		lead_zero(len);
		puts(s);
	}
	return 0;
}