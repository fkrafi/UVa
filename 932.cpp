#include<stdio.h>

int n;
int x[35];

int ABS(int n){
	return (n<0)?-n:n;
}

int Place(int k, int i){
	int j;
	for(j=1; j<=k-1; j++){
		if((x[j]==i) || (ABS(x[j]-i) == ABS(j-k)))
			return 0;
	}
	return 1;
}

int chk_validation(){
	int i;
	for(i=1; i<=n; i++){
		if( !Place(i, x[i]) )
			return 0;
	}
	return 1;
}

void input(){
	int i, j;
	char ch;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%c", &ch);
			if( ch=='0')continue;
			else if( ch=='X' ) x[i] = j;
			else j--;
		}
	}
}

int correct(){
	int i, j, t;
	for(i=1; i<=n; i++){
		t = x[i];
		for(j=1; j<=n; j++){
			x[i] = j;
			if(chk_validation())
				return 1;
		}
		x[i] = t;
	}
	return 0;
}


void output(){
	puts("YES");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if( j==x[i] )printf("X");
			else printf("0");
		}
		printf("\n");
	}
}

int main(){
	freopen("932.txt", "r", stdin);
	while( scanf("%d", &n) != EOF ){
		input();
		if( chk_validation() )puts("YES");
		else{
			puts("NO");
			if(correct()) output();
			else puts("NO");
		}
	}
	return 0;
}
