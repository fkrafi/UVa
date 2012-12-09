#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

#define MAXN 1005
#define MAXLG 17

char A[MAXN], s[MAXN];

struct entry {
	int nr[2], p;
}L[MAXN];

int P[MAXLG][MAXN], len, stp, temp[MAXN];

int cmp(struct entry a, struct entry b){
	return (a.nr[0] == b.nr[0])?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

void build_suffix_array(){
	int i, cnt;
	for(len=strlen(A), i=0; i<len; i++)
		P[0][i] = A[i] - '$';
	for(stp=1, cnt=1; cnt>>1<len; stp++, cnt<<=1){
		for (i=0; i<len; i++){
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + (cnt<len)?P[stp-1][i+cnt]:-1;
			L[i].p = i;
		}
		sort(L, L+len, cmp);
		for (i=0; i<len; i++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
	}
	stp--;
}

int lcp(int x, int y){
	int k, ret = 0;
	if(x == y) return (len-x);
	for(k=stp; k>=0 && x<len && y<len; k--){
		if(P[k][x]==P[k][y]){
			x += 1<<k;
			y += 1<<k;
			ret += 1<<k;
		}
	}
	return ret;
}

int main(){
	freopen("K.txt", "r", stdin);
	int T, i, Max, maxI, cnt;
	scanf("%d", &T); getchar();
	while( T-- ){
		gets(A);
		strcat(A, "$");
		build_suffix_array();
		Max = maxI = 0;
		for(i=1; i<len; i++){
			temp[i] = lcp(L[i-1].p, L[i].p);
			if( Max < temp[i] ){
				Max = temp[i];
				maxI = i;
			}
		}
		if( Max==0 ){
			puts("No repetitions found!");
			continue;
		}
		cnt = 1;
		for(i=maxI; i>=0; i--){
			if( temp[i] != Max )break;
			cnt++;
		}
		for(i=maxI+1; i<len; i++){
			if( temp[i] != Max )break;
			cnt++;
		}
		for(i=L[maxI].p; i<(L[maxI].p+Max); i++){
			printf("%c", A[i]);
		}
		printf(" %d\n", cnt);
	}
	return 0;
}