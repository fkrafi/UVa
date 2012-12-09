#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
typedef pair<string, int> psi;


map<string, int> M;
psi store[1000];
string str;
char s[1000], temp[1000];

bool comp(psi a, psi b){
	return a.first < b.first;
}

int main(){
	freopen("10420.txt", "r", stdin);
	int i, n, pos;
	while(scanf("%d", &n) != EOF){
		pos = 0;
		for(i=0; i<n; i++){
			scanf("%s", s);gets(temp);
			str = string(s);
			if(M.find(str) == M.end()){
				store[pos].first = str;
				store[pos].second = 0;
				M[str] = pos++;
			}
			store[M[str]].second++;
		}
		sort(store, store+pos, comp);
		for(i=0; i<pos; i++)
			cout << store[i].first << " " << store[i].second << "\n";
		M.clear();
	}
	return 0;
}