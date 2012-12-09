#include<stdio.h>

int k;
int arr[15];
int ans[8];

void output(){
	int i;
	printf("%d", ans[6]);
	for(i=5; i>=1; i--)
		printf(" %d", ans[i]);
	printf("\n");
}

void BtKt(int pos, int n){
	if( pos>k )return;
	if(!n){
		output();
		return;
	}
	int i;
	for(i=pos+1; i<=k-n+1; i++){
		ans[n] = arr[i];
		BtKt(i, n-1);
	}
}


int main(){
	freopen("441.txt", "r", stdin);
	int i, flag=0;
	while( scanf("%d", &k) ){
		if( !k )break;
		if(flag)printf("\n");
		flag = 1;
		for(i=1; i<=k; i++)
			scanf("%d", &arr[i]);
		BtKt(0, 6);
	}
	return 0;
}