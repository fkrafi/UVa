#include<string.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

string s="", res;

int isValid(char ch){
	return ( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || ch=='-' );
}

string lower(string s){
	int i, l=s.length();
	for(i=0; i<l; i++){
		s[i] = tolower(s[i]);
	}
	return s;
}

int main(){
	char ch;
	int len = 0;
	freopen("12543.txt", "r", stdin);
	while( scanf("%c", &ch) != EOF ){
		if( !isValid(ch) ){
			if( s.length()>len ){
				len = s.length();
				res = s;
			}
			s = "";
		}else{
			s += ch;
			if( lower(s)=="e-n-d" )break;
		}
	}
	cout << lower(res) << "\n";
	return 0;
}