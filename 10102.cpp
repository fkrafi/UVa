#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;


int M;
vector<int> dis;
vector<pii> ones, threes;

int ABS(int n){
	return (n<0)?-n:n;
}

void input(){
	char ch;
	int i, j;
	ones.clear();
	threes.clear();
	for(i=1; i<=M; i++){
		for(j=1; j<=M; j++){
			scanf("%c", &ch);
			if( ch=='1' ){
				ones.push_back(pii(i, j));
			}else if( ch=='3' ){
				threes.push_back(pii(i, j));
			}else if( ch!='2' ){
				j--;
			}
		}
	}
}

int solve(){
	pii u, v;
	int i, j, ret=-1, temp;
	dis.clear();
	for(i=0; i<ones.size(); i++){
		ret = 99999999;
		for(j=0; j<threes.size(); j++){
			u = ones[i];
			v = threes[j];
			temp = ABS(u.first - v.first) + ABS(u.second - v.second);
			if( temp<ret )ret =temp;
		}
		dis.push_back(ret);
	}
	ret = -1;
	for(i=0; i<dis.size(); i++){
		if( ret<dis[i] )
			ret = dis[i];
	}
	return ret;
}

int main(){
	freopen("10102.txt", "r", stdin);
	while( scanf("%d", &M) != EOF ){
		input();
		printf("%d\n", solve());
	}
	return 0;
}