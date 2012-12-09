#include<stdio.h>
#include<string.h>
#define SZ 30
#define INF 99999999

int N;
int arr[SZ][SZ];
char s[SZ];

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


void input(){
	int i, l;
	N = 0;
	while( gets(s) ){
		l = strlen(s);
		if( !l )break;
		N++;
		for(i=0; i<l; i++){
			if( s[i]=='1' )
				arr[N][i] = 1;
			else
				arr[N][i] = -INF;
		}
	}
}


int main(){
	freopen("836.txt", "r", stdin);
	int t, flag=0, res;
	scanf("%d", &t);getchar();getchar();
	while(t--){
		if( flag )printf("\n");
		flag = 1;
		input();
		res = dp();
		if( res>=0 )
			printf("%d\n", res);
		else
			printf("0\n");
	}
	return 0;
}