#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

char s[2000];
char temp[2000];
char res[2000];
map<int, char> M;

void mapping(){
	int i;
	for(i='a'; i<='z'; i++)M[i] = char(i);
	for(i='A'; i<='Z'; i++)M[i] = char(i);
	M['!'] = '!'; M[','] = ','; M['.'] = '.'; 
	M[':'] = ':'; M[';'] = ';'; M['?'] = '?'; M[' '] = ' ';
}

void encode(){
	int l = strlen(s), n, i, k;
	res[0] = '\0';
	for(i=0; i<l; i++){
		n = s[i];
		k = 0;
		while( n ){
			temp[k++] = n%10 + 48;
			n /= 10;
		}
		temp[k] = '\0';
		reverse(temp, temp+k);
		strcat(res, temp);
	}
	l = strlen(res);
	reverse(res, res+l);
	puts(res);
}

void decode(){
	int l=strlen(s), i, n=0, j=0;
	reverse(s, s+l);
	for(i=0; i<l; i++){
		n = n*10 + (s[i]-48);
		if( M.find(n) != M.end() ){
			res[j++] = M[n];
			n = 0;
		}
	}
	res[j] = '\0';
	puts(res);
}



int main(){
	freopen("444.txt", "r", stdin);
	mapping();
	while( gets(s) ){
		if( s[0]>='0' && s[0]<='9' ){
			decode();
		}else{
			encode();
		}
	}
	return 0;
}