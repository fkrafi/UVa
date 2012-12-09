#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


struct storage{
	string str;
	int len;
}s[105];

bool comp(struct storage a, struct storage b)
{
	return a.str<b.str;
}

void space(int n){
	if(n<=0)return;
	for(int i=0; i<n; i++)printf(" ");
}

int main()
{
	freopen("400.txt", "r", stdin);
	int n, i, j, ncol, max, nrow;
	while(scanf("%d", &n) != EOF)
	{
		getchar();
		max = -1;
		for(i=0; i<n; i++)
		{
			cin >> s[i].str;
			s[i].len = s[i].str.length();
			if(s[i].len>max)max = s[i].len;
		}
		ncol = 1 + (60-max)/(max+2);
		nrow = int(ceil(double(n)/double(ncol)));
		sort(s, s+n, comp);
		cout << "------------------------------------------------------------\n";
		for(i=0; i<nrow ; i++){
			for(j=i; j<n; j+=nrow){
				cout << s[j].str;
				space(max-s[j].len+2);
			}
			printf("\n");
		}
	}
	return 0;
}