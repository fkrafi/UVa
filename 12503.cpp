#include<stdio.h>
#include<string.h>

char ins[105];
int p[105];

int main(){
	freopen("12503.txt", "r", stdin);
	int T, N, x, i, j;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d", &N);
		for(i=1, x=0; i<=N; i++){
			scanf("%s", ins);
			if( !strcmp(ins, "LEFT") ){
				x--;
				p[i] = -1;
			}else if( !strcmp(ins, "RIGHT") ){
				x++;
				p[i] = 1;
			}else{
				scanf("%s%d", ins, &j);
				x += p[j];
				p[i] = p[j];
			}
		}
		printf("%d\n", x);
	}
	return 0;
}