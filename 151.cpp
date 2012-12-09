#include<stdio.h>
#include<queue>
using namespace std;

int a[105];
int n;
queue<int> q, EQ;
void set()
{
	for(int i=1; i<=n; i++)a[i]=1;
}

int main()
{
	freopen("151.txt", "r", stdin);
	int i, cnt, m;
	while(scanf("%d", &n))
	{
		if(!n)break;
		for(m=1; ; m++)
		{
			q = EQ;
			set();
			i = 2;
			cnt = 0;
			a[1] = 0;
			q.push(1);
			while(q.size()<n)
			{
				if(i==13)break;
				for(; i<=n; i++)
				{
					if(a[i])cnt++;
					if(cnt==m)break;
					if(i==n)i=0;
				}
				q.push(i);
				a[i] = 0;
				cnt = 0;
			}
			if(q.size() == n)break;
		}
		printf("%d\n", m);
	}
	return 0;
}