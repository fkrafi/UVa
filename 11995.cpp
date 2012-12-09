#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


class comp{
public:
    bool operator()(const int &a, const int &b)const
    {
        return a<b;
    }
};

stack<int> S, ES;
queue<int> Q, EQ;
priority_queue<int, vector<int>, comp> PQ, EPQ;
int con;

void pushOp(int val){
	S.push(val);
	Q.push(val);
	PQ.push(val);
}

void popOp(int val){
	int chk = 0;
	if( !S.empty() && val == S.top() ){
		S.pop();
		chk = 1;
	}
	if( !Q.empty() && val == Q.front() ){
		Q.pop();
		chk = 1;
	}
	if( !PQ.empty() && val == PQ.top() ){
		PQ.pop();
		chk = 1;
	}
	if( !chk )con=1;
}

void solve(){
	if(con){
		puts("impossible");
		return;
	}
	int res, sz[4], cnt=0, ret, i;
	sz[0] = S.size();
	res = sz[0];
	sz[1] = Q.size();
	if(res > sz[1])res = sz[1];
	sz[2] = PQ.size();
	if(res > sz[2])res = sz[2];
	for(i=0; i<3; i++){
		if(res == sz[i]){
			ret = i;
			cnt++;
		}
	}
	if(cnt>1)puts("not sure");
	else if(ret == 0)puts("stack");
	else if(ret == 1)puts("queue");
	else if(ret == 2)puts("priority queue");
}

int main(){
	freopen("11995.txt", "r", stdin);
	int n, val, i, op;
	while( scanf("%d", &n) != EOF ){
		con = 0;
		for(i=0; i<n; i++){
			scanf("%d%d", &op, &val);
			if(op == 1)pushOp(val);
			else popOp(val);
		}
		solve();
		S = ES;
		Q = EQ;
		PQ = EPQ;
	}
	return 0;
}