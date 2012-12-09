#include<stdio.h>

char l[] = {'A', 'B', 'C', 'D', 'E'};

int main(){
	freopen("11839.txt", "r", stdin);
	char ans;
	int N, i, j, m;
	while(scanf("%d", &N)){
		if( !N )break;
		for(i=0; i<N; i++){
			ans = 'F';
			for(j=0; j<5; j++){
				scanf("%d", &m);
				if( m<=127 ){
					if( ans != 'F' )ans = '*';
					else ans = l[j];
				}
			}
			if( ans == 'F' )ans = '*';
			printf("%c\n", ans);
		}
	}
	return 0;
}