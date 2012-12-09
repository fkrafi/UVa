#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int bm[1048578][20];
int tks[25];
int N, S;

void generate(){
	int i, j, t;
	for(i=0; i<=1048576; i++){
		t = i;
		for(j=0; j<20; j++){
			bm[i][j] = t%2;
			t /= 2;
		}
	}
}


pii chk(){
	int s=int(pow(2, N));
	pii res = pii(-1, S);
	pii nrRes = pii(-1, -1);
	int i, j, nr=-1, sum , cnt, maxCnt=-1, nrCnt=-1;
	for(i=0; i<s; i++){
		sum = 0;
		cnt = 0;
		for(j=0; j<N; j++){
			if( bm[i][j] ){
				sum += tks[j];
				cnt++;
			}
		}
		if( sum == S && maxCnt<cnt ){
			res.first = i;
			maxCnt = cnt;
		}			
		if( nrRes.second<sum && sum<S ){
			nrRes.first = i;
			nrRes.second = sum;
		}
	}
	if( maxCnt > 0 )
		return res;
	return nrRes;
}





int main(){
	generate();
	freopen("624.txt", "r", stdin);
	int i;
	pii pos;
	while( scanf("%d", &S) != EOF ){
		scanf("%d", &N);
		for(i=0; i<N; i++)scanf("%d", &tks[i]);
		pos = chk();
		for(i=0; i<N; i++){
			if( bm[pos.first][i] )
				printf("%d ", tks[i]);
		}
		printf("sum:%d\n", pos.second);
	}
	return 0;
}