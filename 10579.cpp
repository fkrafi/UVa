#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string fib[100000];

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

void generate_fibb()
{
	int i;
	string a, b;
	fib[0] = "0";
	fib[1] = "1";
	fib[2] = "1";
	for(i=3; ; i++)
	{
		a = fib[i-1];
		b = fib[i-2];
		fib[i] = add(a, b);
		if(fib[i].length() >= 1000)break;
	}
}

int main()
{
	int n;
	generate_fibb();
	while(scanf("%d", &n) != EOF)
		cout << fib[n] << "\n";
	return 0;
}