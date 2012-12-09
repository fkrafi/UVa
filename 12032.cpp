#include<stdio.h>

int r[100005];


int main(){
	freopen("12032.txt", "r", stdin);
	int cs, t, n, i, prev, d, con, j, k, MAX;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d", &n);
		MAX = -1;
		prev = 0;
		for(i=0; i<n; i++){
			scanf("%d", &r[i]);
			d = r[i] - prev;
			if(MAX < d)MAX = d;
			prev = r[i];
		}
		con = 0;
		prev = 0;
		for(; ; MAX++){
			k = MAX;
			con = 1;
			prev = 0;
			for(j=0; j<n; j++){
				d = r[j] - prev;
				if( k < d ){
					con = 0;
					break;
				}
				if( k == d )k--;
				prev = r[j];
			}
			if(con){
				printf("Case %d: %d\n", cs, MAX);
				break;
			}
		}
	}
	return 0;
}