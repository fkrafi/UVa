#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

char s[15];
int len, sz, flag;
string str[15005], temp, str2;


struct node{
	int val;
	node *next[26];
	node(){
		val=0;
		memset(next,NULL,sizeof(next));
	}
};
node *root=new node();

void insert(char *str){
	int i, ch;
	node *curr = root;
	for(i=0; str[i]; i++){
		ch = str[i] - 'a';
		if(curr->next[ch] == NULL){
			curr->next[ch]= new node();
		}
		curr = curr->next[ch];
	}
	curr->val++;
}

int traverse(string str){
	int i, ch;
	node *curr = root;
	for(i=0; str[i]; i++){
		ch = str[i] - 'a';
		if(curr->next[ch] == NULL){
			return 0;
		}
		curr = curr->next[ch];
	}
	if( curr->val>0 && flag )
		curr->val = 0;
	return (curr->val != 0);
}

int main(){
	freopen("10745.txt", "r", stdin);
	int i, j, k, t;
	while( gets(s) ){
		str[sz++] = string(s);
		len = strlen(s);
		sort(s, s+len);
		insert(s);
	}
	sort(str, str+sz);
	flag = 1;
	for(i=0; i<sz; i++){
		temp = str[i];
		sort(temp.begin(), temp.end());
		len = temp.length();
		for(j=1; j<(1<<len)-1; j++){
			t = j;
			str2 = "";
			for(k=0; k<len; k++){
				if( t%2 ){
					str2 += temp[k];
				}
				t /= 2;
			}
			traverse(str2);
		}
	}
	flag = 0;
	for(i=0; i<sz; i++){
		temp = str[i];
		sort(temp.begin(), temp.end());
		if( traverse(temp) ){
			cout << str[i] << "\n";
		}
	}
	return 0;
}