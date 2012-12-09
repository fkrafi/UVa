#include<stdio.h>
#include<algorithm>
using namespace std;

int a[1500];

int main(){
	freopen("11850.txt", "r", stdin);
	int N, i;
	while( scanf("%d", &N) ){
		if( !N )break;
		for(i=0; i<N; i++){
			scanf("%d", &a[i]);
		}
		sort(a, a+N);
		for(i=1; i<N; i++){
			if( a[i]-a[i-1] > 200 )break;
		}
		if (2*(1422-a[N-1])>200)i=0;
		if( i>=N ){
			puts("POSSIBLE");
		}else{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}