#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

char s1[1005];
char s2[1005];
int cnt1[150], cnt2[150];

void init(){
	for(int i='a'; i<='z'; i++)
		cnt1[i] = cnt2[i] = 0;
}

int MIN(int a, int b){
	return (a<b)?a:b;
}

int main(){
	int i, j, l;
	while( gets(s1) ){
		gets(s2);
		init();
		l = strlen(s1);
		for(i=0; i<l; i++)
			cnt1[s1[i]]++;
		l = strlen(s2);
		for(i=0; i<l; i++)
			cnt2[s2[i]]++;
		for(i='a'; i<='z'; i++){
			l = MIN(cnt1[i], cnt2[i]);
			for(j=1; j<=l; j++)
				printf("%c", i);
		}
		printf("\n");
	}
	return 0;
}