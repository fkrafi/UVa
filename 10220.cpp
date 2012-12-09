#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

string fact[1010];

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

string multiply(string a,string b)
{
	int i,j,carry,x,m,n,y=0,len1=a.length(),len2=b.length();
	string c="0",temp;	

	if(a== "0" || b=="0") len2=-1;

	for(i=len2-1;i>=0;i--)
	{
		m=b[i]-'0';
		temp="";
	
		for(carry=x=0,j=len1-1;j>=0 || carry;j--)
		{
			n=j<0 ? 0:a[j]-'0';
			temp+=(((m*n)+carry)%10)+'0';
			carry= ((m*n)+carry)/10;
			x++;
		}
		reverse(temp.begin(),temp.end());	
		for(j=x;j<x+y;j++) temp+='0';
       	c=add(c,temp);
		y++;
	}
    return c;
}

string convert(int i)
{
	ostringstream os;
	os << i;
	string s = os.str(); 
	return s;
}


void factorial(int n)
{
	string a, b;
	int i;
	fact[1] = "1";
	for(i=2; i<=n; i++)
	{
		a = fact[i-1];
		b = convert(i);
		fact[i] = multiply(a, b);
	}
}

int sum(int n)
{
	int s = 0, i, l;
	l = fact[n].length();
	for(i=0; i<l; i++)
		s += fact[n][i]-48;
	return s;
}

int main()
{
	factorial(1000);
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%d\n", sum(n));
	return 0;
}