#include<stdio.h>
#define SZ 100050
//#define SZ 100

int seq[SZ], res[SZ][10], temp[10];

void init(int i){
	for(int j=0; j<10; j++){
		res[i][j] = res[i-1][j];
	}
}

void calculate(){
	int i, j=1, n, t, pos;
	for(i=1; i<=10000; i++){
		n = i;
		pos = 0;
		while(n){
			temp[pos++] = n%10;
			n /= 10;
		}
		init(j);
		for(t=pos-1; t>=0; t--){
			res[j][temp[t]]++;
		}
		j++;
	}
}

int main(){
	calculate();
	int t, n, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d", res[n][0]);
		for(i=1; i<10; i++)
			printf(" %d", res[n][i]);
		printf("\n");
	}
	return 0;
}