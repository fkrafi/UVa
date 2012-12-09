#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define SZ 105
#define INF 2147483647

int nV;
char str[1000];
int cost[SZ], wght[SZ][SZ], seen[SZ][SZ], pi[SZ], cs=1;

class comp{
public:
	bool operator()(const int &a, const int &b)const{
		return cost[a] > cost[b];
	}
};

priority_queue<int, vector<int>, comp> q;
vector<int> edge[SZ];

void dijkstra(int S){
	int u, v, i;
	cost[S] = 0;
	pi[S] = -1;
	q.push(S);
	while(!q.empty()){
		u = q.top();
		for(i=0; i<edge[u].size(); i++){
			v = edge[u][i];
			if(seen[u][v] == cs)continue;
			if(cost[v] > wght[u][v] + cost[u]){
				cost[v] = wght[u][v] + cost[u];
				pi[v] = u;
				q.push(v);
			}
		}
		q.pop();
	}
}

void init(){
	int i;
	for(i=1; i<=nV; i++){
		cost[i] = INF;
		edge[i].clear();
	}
	cs++;
}


int strToNum( char s[] ){
	int i, l=strlen(s), ret=0;
	for(i=0; i<l; i++){
		if(s[i] == ' '){
			return -1;
		}
		ret = ret*10 + s[i]-48;
	}
	return ret;
}

void input(){
	int i, j, temp;
	getchar();
	for(i=2; i<=nV; i++){
		j = 1;
		gets(str);
		char *pch = strtok(str, " ");
		while( pch != NULL ){
			temp = strToNum(pch);
			if( temp > 0 ){
				edge[i].push_back(j);
				edge[j].push_back(i);
				wght[j][i] = wght[i][j++] = temp;
			}
			pch = strtok(NULL, " ");
		}
	}
}

int getMin(){
	int i, ret=-1;
	for(i=2; i<=nV; i++)
		if(ret < cost[i])ret=cost[i];
	return ret;
}

int main(){
	freopen("423.txt", "r", stdin);
	while( scanf("%d", &nV) != EOF ){
		init();
		input();
		dijkstra(1);
		printf("%d\n", getMin());
	}
	return 0;
}