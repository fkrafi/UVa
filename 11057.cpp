#include<stdio.h>

int cost[10005];
int seen[10000010];

void CLEAR(){
     for(int i=0; i<=1000001; i++)seen[i]=0;
}

int MIN(int a, int b){
    return (a<b)?a:b;
}

int ab(int a){
    return (a<0)?-a:a;
}

int main(){
    freopen("11057.txt", "r",stdin);
    int i, I, J, dis, t, n, m;
    while(scanf("%d", &n) != EOF){
		CLEAR();
		dis=99999999;
		for(i=0; i<n; i++){
			scanf("%d", &cost[i]);
			seen[ cost[i] ]++;
		}
		scanf("%d", &m);
		for(i=0; i<n; i++){
			t = m-cost[i];
			if(t>0){
				if(t==cost[i] && seen[t]>1){
					dis = 0;
					I = t;
					J = t;
				}else if( t!=cost[i] && seen[t] ){
					if( dis > ab(cost[i]-t) ){
						dis = ab(cost[i]-t);
						I = (t<cost[i])?t:cost[i];
						J = (t>cost[i])?t:cost[i];
					}
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", I, J);
    }
    return 0;
}
