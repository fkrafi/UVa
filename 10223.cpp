#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
using namespace std;
typedef long long int lld;

lld C[25];
map<lld, int> M;

int main(){
	int n;
	C[0] = 1; M[1] = 0;
	for(n=1; n<20; n++){
		C[n] = (2*(2*n+1)*C[n-1])/(n+2);
		M[C[n]] = n;
	}
	while( scanf("%d", &n) != EOF ){
		printf("%d\n", M[n]+1);
	}
	return 0;
}