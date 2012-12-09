#include<stdio.h>
#include<string>
using namespace std;
#define MAX 2147483647

char s[5], str[5];
long long int sumB, sumG, sumC;
long long int B[3], G[3], C[3];
long long int res, temp;

void find()
{
	res = MAX;
	temp = sumB-B[0] + sumC-C[1]+ sumG-G[2];
	if(temp < res)
	{
		res = temp;
		strcpy(s, "BCG");
	}
	
	temp = sumB-B[0] + sumG-G[1] + sumC-C[2];
	if(temp < res)
	{
		res = temp;
		strcpy(s, "BGC");
	}

	temp = sumC-C[0] + sumB-B[1] + sumG-G[2];
	if(temp < res)
	{
		res = temp;
		strcpy(s, "CBG");
	}
	
	temp = sumC-C[0] + sumG-G[1] + sumB-B[2];
	if(temp < res)
	{
		res = temp;
		strcpy(s, "CGB");
	}
	
	temp = sumG-G[0] + sumB-B[1] + sumC-C[2];
	if(temp < res)
	{
		res = temp;
		strcpy(s, "GBC");
	}
	
	temp = sumG-G[0] + sumC-C[1] + sumB-B[2];
	if(temp < res)
	{
		res = temp;
		strcpy(s, "GCB");
	}
}

int main()
{
	freopen("102.txt", "r", stdin);
	long long int i;
	while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &B[0], &G[0], &C[0], &B[1], &G[1], &C[1], &B[2], &G[2], &C[2]) != EOF)
	{
		sumB = sumG = sumC = 0;
		for(i=0; i<3; i++)
		{
			sumB += B[i];
			sumG += G[i];
			sumC += C[i];
		}
		find();
		printf("%s %lld\n", s, res);
	}
	return 0;
}