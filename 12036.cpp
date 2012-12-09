#include<stdio.h>

int cnt[105];

void CLEAR(){
	int i;
	for(i=0; i<=100; i++)cnt[i] = 0;
}

int main(){
	freopen("12036.txt", "r", stdin);
	int t, n, a, con, i, j, cs;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d", &n);
		con = 1;
		CLEAR();
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				scanf("%d", &a);
				cnt[a]++;
				if(cnt[a]>n)con = 0;
			}
		}
		if(con)printf("Case %d: yes\n", cs);
		else printf("Case %d: no\n", cs);
	}
	return 0;
}