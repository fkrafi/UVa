#include<stdio.h>
#define SZ 25


int nV, step;
int pi[SZ][SZ][SZ];
double wght[SZ][SZ][SZ];

double MAX(double a, double b){
	return (a>b)?a:b;
}


void init(){
	int i, j, s;
	for(s=1; s<=nV; s++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[s][i][j] = 0;
}

void floyd_warshall(){
	int i, j, k, s;
	double temp;
	for(s=2; s<=nV; s++){
		for(k=1; k<=nV; k++){
			for(i=1; i<=nV; i++){
				for(j=1; j<=nV; j++){
					temp = wght[s-1][i][k] * wght[1][k][j];
					if( temp > wght[s][i][j] ){
						wght[s][i][j] = temp;
						pi[s][i][j] = k;
					}
				}
			}
		}
	}
}

void input(){
	int i, j;
	for(i=1; i<=nV; i++){
		for(j=1; j<=nV; j++){
			if( i==j ) wght[1][i][j] = 1;
			else{ scanf("%lf", &wght[1][i][j]); }
			pi[1][i][j] = i;
		}
	}
}

int chk_ans(){
	int i, s, ret=-1;
	for(s=2; s<=nV; s++){
		for(i=1; i<=nV; i++){
			if( wght[s][i][i] > 1.01 ){
				ret = i;
				step = s;
				break;
			}
		}
		if(ret!=-1)break;
	}
	return ret;
}


void print_path(int i, int j, int s){
	if(s==0)
		printf("%d", j);
	else{
		print_path(i, pi[s][i][j], s-1);
		printf(" %d", j);
	}
}

int main(){
	freopen("104.txt", "r", stdin);
	int res;
	while( scanf("%d", &nV) != EOF ){
		init();
		input();
		floyd_warshall();
		res = chk_ans();
		if( res<0 )
			printf("no arbitrage sequence exists");
		else
			print_path(res, res, step);
		printf("\n");
	}
	return 0;
}