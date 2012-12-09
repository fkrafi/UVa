#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long int lld;


lld prime[10000005];
vector<lld> pmlist;

void sieve(int n){
   prime[0]=1;
   prime[1]=1;
   int m = int(sqrt(n)), i=2, k;
   for(k=i*i; k<=n; k+=i)
      prime[k]=1;
   for (i=3; i<=m; i+=2){
      if(!prime[i])
         for (k=i*i; k<=n; k+=i)
            prime[k]=1;		 
   }
   for(i=2; i<=n; i++){
	   if( !prime[i] )
		   pmlist.push_back(i);
   }
}

int main(){
	freopen("11466.txt", "r", stdin);
	sieve(10000000);
	lld n, res, t, i, cnt, s=pmlist.size();
	while( scanf("%lld", &n) ){
		if( !n )break;
		if( n<0 ){ n *= -1; }
		res = -1;
		for(i=0, t=n, cnt=0; pmlist[i]<=t && t>1 && i<s; i++){
			if( t%pmlist[i]==0 ){
				cnt++;
				while( t%pmlist[i]==0 ){
					t /= pmlist[i];
				}
				res = pmlist[i];
			}
		}
		if( t!= 1 ){
			res = t;
			cnt++;
		}
		if( cnt>1 ){
			printf("%lld\n", res);
		}else{
			puts("-1");
		}
	}
	return 0;
}