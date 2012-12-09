#include<stdio.h>
#include<math.h>

int sz;
int prime[1000005], p[1000005];

void sieve(int n){
   prime[0]=1;
   prime[1]=1;
   int m = int(sqrt(n)), i=2, k;
   for(k=i*i; k<=n; k+=i)
      prime[k]=1;
   for (i=3; i<=m; i+=2)
      if(!prime[i])
         for (k=i*i; k<=n; k+=i)
            prime[k]=1;
}

void init(){
	int i;
	for(i=0; i<=10000; i++){
		if( !prime[i] )
			p[sz++] = i;
	}
}

int main(){
	//freopen("1210.txt", "r", stdin);
	int n, i, j, res, sum;
	sieve(10000);
	init();
	while( scanf("%d", &n) ){
		if( !n )break;
		res = 0;
		for(i=0; i<sz; i++){
			sum = 0;
			for(j=i; j<sz; j++){
				sum += p[j];
				if( sum==n )res++;
				else if(sum>n)break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}