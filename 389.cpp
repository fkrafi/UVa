#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef int llt;

char s[1000];
int baseFrm, baseTo;

int change(char ch){
	if(ch>='0' && ch<='9')
		return (ch-'0');
	return (ch-55);
}

int toString(int dec){
	int cnt=0;
	while(dec){
		dec /= 10;
		cnt++;
	}
	return cnt;
}

void convert(){
	int l = strlen(s), i, neg=0;
	llt p=1, dec = change(s[l-1]);
	for(i=l-2; i>=0; i--){
		if(s[i] == '-'){neg=1; continue;}
		p *= baseFrm;
		dec += change(s[i])*p;
	}
	if(baseTo == 10 || !dec){
		if(neg)dec *= (-1);
		if(toString(dec) > 7 ) puts("  ERROR");
		else printf("%7d\n", dec);
		return;
	}
	i = 0;
	while(dec){
		p = dec%baseTo;
		s[i++] = (p>9) ? ('A'+p%10) : (p+'0');
		dec /= baseTo;
	}
	if(neg)s[i++] = '-';
	if(i>7){
		puts("  ERROR");
		return;
	}
	for(; i<7; i++)
		s[i] = ' ';
	s[i] = '\0';
	reverse(s, s+i);
	puts(s);
}

int main(){
	freopen("389.txt", "r", stdin);
	while( scanf("%s%d%d", s, &baseFrm, &baseTo) != EOF ){
		convert();
	}
	return 0;
}