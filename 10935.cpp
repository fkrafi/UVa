#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;

int main()
{
	int n, i, u;
	while(scanf("%d", &n))
	{
		if(!n)break;
		if(n==1)
			printf("Discarded cards:\nRemaining card: 1\n");
		else if(n==2)
			printf("Discarded cards: 1\nRemaining card: 2\n");
		else{
			for(i=1; i<=n; i++)
				q.push(i);
			printf("Discarded cards: %d", q.front());
			q.pop();
			u = q.front();
			q.push(u);
			q.pop();
			while(q.size() > 2)
			{
				printf(", %d", q.front());
				q.pop();
				u = q.front();
				q.push(u);
				q.pop();
			}
			printf(", %d", q.front());
			q.pop();
			printf("\nRemaining card: %d\n", q.front());
			q.pop();
		}
	}
	return 0;
}