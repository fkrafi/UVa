#include<stdio.h>


void search(int m1, int n1, int m2, int n2, int m, int n){
	double mid = (double)(m1+m2)/(double)(n1+n2);
	double z = (double)m/(double)n;
	if( z==mid ){
		printf("\n");
		return;
	}else if( z<mid ){
		printf("L");
		search(m1, n1, m1+m2, n1+n2, m, n);
	}else{
		printf("R");
		search(m1+m2, n1+n2, m2, n2, m, n);
	}
}

int main(){
	freopen("10077.txt", "r", stdin);
	int m, n;
	while( scanf("%d%d", &m, &n) ){
		if( m==1 && n==1 )break;
		search(0, 1, 1, 0, m, n);
	}
	return 0;
}