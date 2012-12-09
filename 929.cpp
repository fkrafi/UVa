#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;
#define MAX 429496729

typedef pair<int, int> pi;

pi pr;
int wght[1010][1010], cst[1010][1010];
int vst[1010][1010];
int dr[] = {-1, 0, +1, 0};
int dc[] = {0, 1, 0, -1};


class comp{
public:
    bool operator()(const pi &a, const pi &b)const
    {
        return cst[a.first][a.second] > cst[b.first][b.second];
    }
};

priority_queue<pi, vector<pi>, comp> q;

void dijkstra(int m, int n)
{
    pi u, v;
    int i;

    u.first = 1;
    u.second = 1;
    cst[1][1] = wght[u.first][u.second];

    q.push(u);

    while(!q.empty())
    {
        u = q.top();
        q.pop();

        for(i=0; i<4; i++)
        {
            v.first = u.first + dr[i];
            v.second = u.second + dc[i];

            if(v.first<1 || v.first>m || v.second<1 || v.second>n || vst[v.first][u.second]==1 )continue;

            if(cst[v.first][v.second] > cst[u.first][u.second] + wght[v.first][v.second])
            {
                cst[v.first][v.second] = cst[u.first][u.second] + wght[v.first][v.second];
                q.push(v);
            }
        }
        
        vst[v.first][u.second] = 1;
    }
}


int main()
{
    int t, m, n, i, j;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d", &wght[i][j]);
                cst[i][j] = MAX;
                vst[i][j] = 0;
            }
        }
        dijkstra(m, n);
        printf("%d\n", cst[m][n]);
    }
    return 0;
}