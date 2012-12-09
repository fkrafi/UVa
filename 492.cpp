#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<iostream>
using namespace std;

string s, r, t;
char str[1000005];

int isChar(char ch){
	return ( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') );
}

int isVowel(char ch){
	return ( (ch=='a') || (ch=='e') || (ch=='i') || (ch=='o') || (ch=='u') );
}

int main(){
	int i, len;
	while( gets(str) ){
		s = string(str);
		len = s.length();
		t = "";
		for(i=0; i<len; i++){
			if( isChar(s[i]) ){
				t += s[i];
			}else{
				if( t.length() ){
					if( isVowel(tolower(t[0])) ){
						t += "ay";
					}else{
						t = t.substr(1, t.length()) + t[0] + "ay";
					}
					cout << t;
					t = "";
				}
				cout << s[i];
			}
		}
		cout << "\n";
	}
	return 0;
}