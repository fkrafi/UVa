#include<stdio.h>
#include<string.h>

int bars[25];
int can[1005];

int main(){
	freopen("12455.txt", "r", stdin);
	int t, n, p, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &p);
		for(i=0; i<p; i++)
			scanf("%d", &bars[i]);
		memset(can, 0, sizeof(can));
		can[0] = 1;
		for(i=0; i<p; i++){
			for(j=n; j>0; j--){
				if( j-bars[i]>=0 && can[j-bars[i]] ){
					can[j] = 1;
				}
			}
		}
		if( can[n] )puts("YES");
		else puts("NO");
	}
	return 0;
}