#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;

#define MAXN 1005
#define MAXLG 21

char A[100*MAXN], s[MAXN];

struct entry {
	int nr[2], p;
}L[100*MAXN];

string cur, prev;
vector<PII> Store;
int P[MAXLG][100*MAXN], len, stp, N, taken[MAXN], Pos[MAXN];

int cmp(struct entry a, struct entry b){
	return (a.nr[0] == b.nr[0])?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

void build_suffix_array(){
	int i, cnt, K=1;
	for(len=strlen(A), i=0; i<len; i++){
		if( A[i]>='a' && A[i]<='z' ){
			P[0][i] = A[i] - 'a' + 105;
		}else{
			P[0][i] = K++;
		}
	}
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

void input(){
	int i;
	gets(A); strcat(A, "$");
	for(i=2; i<=N; i++){
		Pos[i] = strlen(A);
		gets(s); strcat(A, s); strcat(A, "$");
	}
}

int index(int i){
	int j;
	for(j=2; j<=N; j++){
		if( i<Pos[j] )
			return j-1;
	}
	return N;
}

int isValid(){
	int i, j=0;
	for(i=1; i<=N; i++){
		j += (taken[i]!=0);
	}
	return (j>N/2);
}

int main(){
	freopen("J.txt", "r", stdin);
	int res, t, x, y, flag=0;
	while(scanf("%d", &N)){
		if( !N )break; getchar(); 
		if( flag )printf("\n");
		if( N==1 ){
			gets(A);
			puts(A);
			continue;
		}
		input();
		build_suffix_array();
		res = 0;
		memset(taken, 0, sizeof(taken));
		taken[index(L[0].p)]++;
		Store.clear();
		for(x=0, y=0; ; ){
			if( isValid() && x<y && x<len ){
				t = lcp(L[x].p, L[y].p);
				if( res<=t ){
					res = t;
					Store.push_back(PII(L[x].p, t));
				}
				taken[index(L[x].p)]--;
				x++;
			}else if( y<len ){
				y++;
				taken[index(L[y].p)]++;
			}else{break;}
		}
		cur = prev = "";
		for(x=0, y=0; res && x<Store.size(); x++){
			if( res==Store[x].second ){
				for(t=Store[x].first; t<(Store[x].first+res); t++){
					cur += A[t];
				}
				if( cur!=prev )
					cout << cur << "\n";
				prev = cur;
				cur = "";
				y = 1;
			}
		}
		if( !y )puts("?");
		flag = 1;
	}
	return 0;
}