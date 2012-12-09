#pragma warning( disable : 4786 )
#include<stdio.h>
#include<map>
using namespace std;

int a[10005], b[10005];
int N, M;
map<int, int> Mp;


struct storage{
	int label, cnt;
}store[10005];

int ab(int n){
	return (n<0)?-n:n;
}

int main(){
	freopen("J.txt", "r", stdin);
	int t, i, pos, res;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &N, &M);
		pos = 0;
		for(i=1; i<=N; i++){
			scanf("%d", &a[i]);
			if( Mp.find(a[i]) == Mp.end() ){
				Mp[a[i]] = pos;
				store[pos].label = a[i];
				store[pos++].cnt = 0;
			}
			store[ Mp[a[i]] ].cnt++;
		}
		for(i=1; i<=M; i++){
			scanf("%d", &b[i]);
			if( Mp.find(b[i]) == Mp.end() ){
				Mp[b[i]] = pos;
				store[pos].label = b[i];
				store[pos++].cnt = 0;
			}
			store[ Mp[b[i]] ].cnt--;
		}
		res = 0;
		for(i=0; i<pos; i++){
			res += ab(store[i].cnt);
		}
		printf("%d\n", res);
		Mp.clear();
	}
	return 0;
}