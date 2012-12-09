#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 105

int a[SZ];

int ABS(int n){
	return (n<0)?-n:n;
}

int main(){
	int t, i, N, res;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		for(i=0; i<N; i++)scanf("%d", &a[i]);
		sort(a, a+N);
		res = 0;
		for(i=0; i<N-1; i++){
			res += ABS(a[i]-a[i+1]);
		}
		printf("%d\n", res*2);
	}
	return 0;
}