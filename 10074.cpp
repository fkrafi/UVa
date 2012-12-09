#include<iostream>
#include<stdio.h>
using namespace std;
#define INF 100000

int M, N;
int mem[101][101];


void input(){
	int t, i, j;
	for(i=1; i<=M; i++){
        for(j=1; j<=N; j++){
            scanf("%d", &t);
			if( t==0 )t=1;
			else t = -INF;
            mem[i][j] = t + mem[i][j-1] + mem[i-1][j] - mem[i-1][j-1];
        }
    }
}


int max_sum(){
	int x1, y1, x2, y2, t;
	int ret=mem[1][1];
    for(x1=1; x1<=M; x1++){
        for(y1=1; y1<=N; y1++){
            for(x2=x1; x2<=M; x2++){
                for(y2=y1; y2<=N; y2++){
                    t = mem[x2][y2] - mem[x2][y1-1] - mem[x1-1][y2] + mem[x1-1][y1-1];
                    if(t>ret)ret=t;
                }
            }
        }
    }
	return ret;
}

int main(){
	freopen("10074.txt", "r", stdin);
	int ans;
	while( scanf("%d%d", &M, &N) ){
		if( !M && !N )break;
		input();
		ans = max_sum();
		if( ans<0 )puts("0");
		else printf("%d\n", ans);
	}
	return 0;
}