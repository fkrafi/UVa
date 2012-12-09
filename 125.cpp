#include<stdio.h>
#include<string.h>
#define SZ 105

int nE, nV, cs;
int cst[SZ][SZ];


int MAX(int a, int b){
	return (a>b)?a:b;
}


void input(){
	int i, u, v;
	nV = 0;
	memset(cst, 0, sizeof(cst));
	for(i=0; i<nE; i++){
		scanf("%d%d", &u, &v);
		nV = MAX(nV, MAX(u, v));
		cst[u][v] = 1;
	}
}


void floyd_warshall(){
	int i, j, k;
	for(k=0; k<=nV; k++){
		for(i=0; i<=nV; i++){
			for(j=0; j<=nV; j++){
				if( cst[i][k] && cst[k][j] )
					cst[i][j] += cst[i][k]*cst[k][j];
			}
		}
	}
	for(k=0; k<=nV; k++){
		if( cst[k][k] ){
			for(i=0; i<=nV; i++){
				for(j=0; j<=nV; j++){
					if( cst[i][k] && cst[k][j] )
						cst[i][j] = -1;
				}
			}
		}
	}
}

void output(){
	int i, j;
	printf("matrix for city %d\n", cs++);
	for(i=0; i<=nV; i++){
		for(j=0; j<=nV; j++){
			if( !j )printf("%d", cst[i][j]);
			else printf(" %d", cst[i][j]);
		}
		printf("\n");
	}
}

int main(){
	freopen("125.txt", "r", stdin);
	while( scanf("%d", &nE) != EOF ){
		input();
		floyd_warshall();
		output();
	}
	return 0;
}