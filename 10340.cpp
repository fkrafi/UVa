#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string s, t;

int main(){
	freopen("10340.txt", "r", stdin);
	int sl, tl, i, j, con;
	while( cin >> s >> t ){
		sl = s.length();
		tl = t.length();
		con = j = 0;
		for(i=0; i<tl; i++){
			if(s[j]==t[i]){
				j++;
				if(j==sl){
					con = 1;
					break;
				}
			}
		}
		if(con)puts("Yes");
		else puts("No");
	}
	return 0;
}