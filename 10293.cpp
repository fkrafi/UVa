#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;


char s[1000], temp[1000];
int cnt[50], hip, last;

int isChar(char ch){
	return ( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') );
}

int isDividor(char ch){
	return (ch==' ' || ch=='.' || ch=='?' || ch==',' || ch=='!');
}

void CLEAR(){
	int i;
	for(i=0; i<=35; i++)cnt[i]=0;
}

void solve(){
	int l=strlen(s), i, len=0;
	for(i=0; i<l; i++){
		if(isDividor(s[i]) && hip){
			len += last;
			cnt[len]++;
			hip = 0;
			len = 0;
		}else if(i==l-1 && s[i]=='-'){
			last = len;
			hip = 1;
		}else if(isDividor(s[i]) && len){
			cnt[len]++;
			len = 0;
		}else if(isChar(s[i])){
			len++;
		}
	}
	if(len && !hip){
		cnt[len]++;
		len = 0;
	}
}

void show_output(){
	int i;
	for(i=0; i<=30; i++)
		if(cnt[i])printf("%d %d\n", i, cnt[i]);
	printf("\n");
}

int main(){
	freopen("10293.txt", "r", stdin);
	while(gets(s)){
		if(s[0]=='#'){
			show_output();
			CLEAR();
			continue;
		}
		solve();
	}
	return 0;
}