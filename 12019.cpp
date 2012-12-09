#include<stdio.h>

char day[][100] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int nDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int res[100][100];

void solve(){
	int w=5, m, d;
	for(m=1; m<=12; m++){
		for(d=1; d<=nDay[m-1]; d++){
			if(w>6)w=0;
			res[m][d] = w++;
		}
	}
}

int main(){
	freopen("12019.txt", "r", stdin);
	int m, d, t;
	solve();
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &d);
		printf("%s\n", day[res[m][d]]);
	}
	return 0;
}