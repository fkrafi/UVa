#include<stdio.h>


void solve(int n){
	int i, temp, con=1;
	for(i=0; ;i++){
		temp = n + i*i*i;
		if( temp>216000 )continue;
		if( (temp - cubes[i]) < 0 )break;
		if( isCube[temp] ){
			con = 0;
			printf("%d %d\n", isCube[temp], isCube[cubes[i]]);
			break;
		}
	}
	if(con)
		printf("No solution\n");
}

int main(){
	freopen("11428.txt", "r", stdin);
	//freopen("my.txt", "w", stdout);
	int n;
	generate();
	while(scanf("%d", &n)){
		if(!n)break;
		solve(n);
	}
	return 0;
}