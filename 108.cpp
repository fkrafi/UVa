#include<stdio.h>
#define SZ 110

int N;
int arr[SZ][SZ];

int diff(int i, int j, int k){
	return (arr[i+k][j] - arr[i][j]);
}


int dp(){
    int i, j, k, t, ret;
    for(i = 1; i<=N; i++){
		for(j = 0; j<N; j++)
			arr[i][j] =  arr[i][j] + arr[i-1][j];
	}
	
	ret = arr[1][0];
	for(k=1; k<=N; k++){
		for(i=0; i<=N-k; i++){
			for(t=0, j=0; j<N; j++){
				if(t>=0)
					t+= diff(i,j,k);
				else
					t = diff(i,j,k);
				if(t>ret)
					ret = t;
			}
		}
	}
	return ret;
}


void input(int n){
	int i, j;
	for(i = 1; i<=N; i++)
		for(j  = 0; j<N; j++)
			scanf("%d",&arr[i][j]);
}

int main(){
	while( scanf("%d", &N) != EOF ){
		input(N);
		printf("%d\n", dp());
	}
	return 0;
}