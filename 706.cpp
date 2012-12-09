#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char str[1000], num[100], temp[100][100];
string res[100];
int s, sz;

void zero()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(i==0 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)
				temp[i][j] = '-';
		}
		else if(i == s+1)
		{
			for(j=0; j<s+2; j++)temp[i][j] = ' ';
		}
		else
		{
			temp[i][0] = temp[i][s+1] = '|';
			for(j=1; j<=s; j++)
				temp[i][j] = ' ';
		}
		temp[i][s+2] = '\0';
	}
}

void one()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		for(j=0; j<s+1; j++)temp[i][j] = ' ';
		if(i==0 || i==2*s+2 || i==s+1)temp[i][j] = ' ';
		else temp[i][j] = '|';
		temp[i][j+1] = '\0';
	}
}

void two()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(!i || i==s+1 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)temp[i][j] = '-';
		}
		else if(i<s+1)
		{
			for(j=0; j<s+1; j++)temp[i][j] = ' ';
			temp[i][j] = '|';
		}
		else
		{
			temp[i][0] = '|';
			for(j=1; j<=s+1; j++)temp[i][j] = ' ';
		}
		temp[i][s+2] = '\0';
	}
}

void three()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(!i || i==s+1 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)temp[i][j] = '-';
		}
		else
		{
			for(j=0; j<s+1; j++)temp[i][j] = ' ';
			temp[i][j] = '|';
		}
		temp[i][s+2] = '\0';
	}
}

void four()
{
	int i, j;
	for(i=0; i<=2*s+2; i++)
	{
		if(!i || i==2*s+2)
			for(j=0; j<s+2; j++)temp[i][j]=' ';
		else if(i==s+1)
		{
			temp[s+1][0] = temp[s+1][s+1] = ' ';
			for(j=1; j<s+1; j++)temp[i][j]='-';
		}
		else if(i<s+1)
		{
			temp[i][0]='|';
			for(j=1; j<s+1; j++)temp[i][j]=' ';
			temp[i][j]='|';
		}
		else
		{
			for(j=0; j<s+1; j++)temp[i][j]=' ';
			temp[i][j]='|';
		}
		temp[i][s+2] = '\0';
	}
}

void five()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(!i || i==s+1 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)temp[i][j] = '-';
		}
		else if(i<s+1)
		{
			temp[i][0] = '|';
			for(j=1; j<=s+1; j++)temp[i][j] = ' ';
		}
		else
		{
			for(j=0; j<s+1; j++)temp[i][j] = ' ';
			temp[i][j] = '|';
		}
		temp[i][s+2] = '\0';
	}
}

void six()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(!i || i==s+1 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)temp[i][j] = '-';
		}
		else if(i<s+1)
		{
			temp[i][0] = '|';
			for(j=1; j<=s+1; j++)temp[i][j] = ' ';
		}
		else
		{
			temp[i][0] = '|';
			for(j=1; j<s+1; j++)temp[i][j] = ' ';
			temp[i][j] = '|';
		}
		temp[i][s+2] = '\0';
	}
}

void seven()
{
	int i, j;
	temp[0][0] = temp[0][s+1] = ' ';
	for(i=1; i<s+1; i++)temp[0][i] = '-';
	temp[0][s+2] = '\0';
	for(i=1; i<2*s+3; i++)
	{
		for(j=0; j<s+1; j++)temp[i][j] = ' ';
		if(i==0 || i==2*s+2 || i==s+1)temp[i][j] = ' ';
		else temp[i][j] = '|';
		temp[i][j+1] = '\0';
	}
}

void eight()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(i==0 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)
				temp[i][j] = '-';
		}
		else if(i == s+1)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<s+1; j++)temp[i][j] = '-';
		}
		else
		{
			temp[i][0] = temp[i][s+1] = '|';
			for(j=1; j<=s; j++)
				temp[i][j] = ' ';
		}
		temp[i][s+2] = '\0';
	}
}

void nine()
{
	int i, j;
	for(i=0; i<2*s+3; i++)
	{
		if(!i || i==s+1 || i==2*s+2)
		{
			temp[i][0] = temp[i][s+1] = ' ';
			for(j=1; j<=s; j++)temp[i][j] = '-';
		}
		else
		{
			if(i<s+1)
				temp[i][0] = '|';
			else
				temp[i][0] = ' ';
			for(j=1; j<s+1; j++)temp[i][j] = ' ';
			temp[i][j] = '|';
		}
		temp[i][s+2] = '\0';
	}
}

void choose(char c)
{
	if(c=='0')zero();
	else if(c=='1')one();
	else if(c=='2')two();
	else if(c=='3')three();
	else if(c=='4')four();
	else if(c=='5')five();
	else if(c=='6')six();
	else if(c=='7')seven();
	else if(c=='8')eight();
	else if(c=='9')nine();
}

void join()
{
	int i;
	for(i=0; i<2*s+3; i++)
		res[i] += ' ' + string(temp[i]);
}

void generate()
{
	int l=strlen(num), i;
	sz = 0;
	choose(num[0]);
	for(i=0; i<2*s+3; i++)
		res[i] = string(temp[i]);
	for(i=1; i<l; i++)
	{
		choose(num[i]);
		join();
	}
}

int main()
{
	//freopen("706.txt", "r", stdin);
	//freopen("706_out.txt", "w", stdout);
	int i;
	while(scanf("%d %s", &s, num))
	{
		if(!s && num[0]=='0')break;
		generate();
		for(i=0; i<2*s+3; i++)
			cout << res[i] << "\n";
		printf("\n");
	}
	return 0;
}