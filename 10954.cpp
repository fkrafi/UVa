#include<stdio.h>
#include<queue>
using namespace std;

class comp{
public:
	bool operator()(const int &a, const int &b)const
	{
		return a>b;
	}
};

priority_queue<int, vector<int>, comp> q;

int main()
{
	freopen("10954.txt", "r", stdin);
	int n, a, res, i, ans, b;
	while(scanf("%d", &n))
	{
		if(!n)break;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			q.push(a);
		}
		ans = 0;
		while(!q.empty())
		{
			a = q.top();
			ans += a;
			q.pop();
			if(q.empty())break;
			b = q.top();
			ans += b;
			q.pop();
			if(q.empty())break;
			q.push(a + b);
		}
		printf("%d\n", ans);
	}
	return 0;
}