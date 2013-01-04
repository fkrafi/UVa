#include<stdio.h>
#include<string.h>

char s[205];
int grid[5][5];
int x[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
int y[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
int dr[] = {0, -1, 0, 1, 0};
int dc[] = {0, 0, 1, 0, -1};

int main(){
	freopen("12398.txt", "r", stdin);
	int len, i, j, ui, uj, vi, vj, cs=1;
	while(gets(s)){
		len = strlen(s);
		memset(grid, 0, sizeof(grid));
		for(i=0; i<len; i++){
			ui = x[s[i]-'a'];
			uj = y[s[i]-'a'];
			for(j=0; j<5; j++){
				vi = ui + dr[j];
				vj = uj + dc[j];
				if( vi<1 || vi>3 || vj<1 || vj>3 )continue;
				grid[vi][vj] = (grid[vi][vj]+1)%10;
			}
		}
		printf("Case #%d:\n", cs++);
		for(i=1; i<=3; i++){
			printf("%d", grid[i][1]);
			for(j=2; j<=3; j++){
				printf(" %d", grid[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}