#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

int cnt[1000005];
int prime[1000005];
vector<int> Prime;
map<int, int> Map;

void sieve(int n){
	prime[0]=1;
	prime[1]=1;
	int m = int(sqrt(n)), i=2, k;
	for(k=i*i; k<=n; k+=i)
		prime[k]=1;
	for (i=3; i<=m; i+=2){
		if(!prime[i]){
			for (k=i*i; k<=n; k+=i)
				prime[k]=1;
		}
	}
	for(i=2; i<=n; i++){
		if( !prime[i] )
			Prime.push_back(i);
	}
}

void solve(int L, int U){
	int i, len=Prime.size(), prev=-1, maxCount=-1, maxI=-1, diff, flag=0, cnt=0;
	Map.clear();
	for(i=0; i<len && Prime[i]<=U; i++){
		if( Prime[i]>=L ){
			cnt++;
			if( prev==-1 ){
				prev = Prime[i];
			}else{
				diff = Prime[i]-prev;
				Map[diff]++;
				if( maxCount<Map[diff] ){
					maxCount = Map[diff];
					maxI = diff;
					flag = 1;
				}else if(maxCount==Map[diff]){
					flag = 0;
				}
				prev = Prime[i];
			}
		}
	}
	if( maxI==-1 || !flag || cnt<2 ){
		puts("No jumping champion");
	}else{
		printf("The jumping champion is %d\n", maxI);
	}
}


int main(){
	sieve(1000000);
	int L, U, T;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &L, &U);
		solve(L, U);
	}
	return 0;
}
