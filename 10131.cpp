#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 1005
typedef pair<int, int> pii;

struct elephants{
	int pos, weight, iq;
}ele[SZ];

int p[SZ], best[SZ];

bool comp(elephants a, elephants b){
	if( a.weight == b.weight )
		return a.iq>b.iq;
	return a.weight<b.weight;
}


pii lis(int n){
	int ans = 0, last, i, j;
	for(i=1; i<=n; i++){
		best[i]=1;
		p[i] = -1;
		for(j=1; j<i; j++){
			if(ele[j].weight<ele[i].weight && ele[j].iq>ele[i].iq && best[j]+1>best[i]){
				best[i] = best[j]+1; 
				p[i] = j;
			}
		}
		if(best[i]>ans){
			ans = best[i];
			last= i;
		}
	}
	return pii(ans, last);
}

void print(int now){
	if(now<0)return;
	print(p[now]);
	printf("%d\n",ele[now].pos);
}


int main(){
	freopen("10131.txt", "r", stdin);
	int w, i, nE=1;
	pii res;
	while( scanf("%d%d", &w, &i) != EOF ){
		ele[nE].pos = nE;
		ele[nE].weight = w;
		ele[nE++].iq = i;
	}
	sort(ele+1, ele+nE, comp);
	res = lis(nE-1);
	printf("%d\n", res.first);
	print(res.second);
	return 0;
}