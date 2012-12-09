#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[10000];

int main(){
	int n, t, i, c, l;
	while(scanf("%d", &n)){
		if(n==0)break;
		t=n;
		i=0; c=0;
		while(t){
			s[i] = t%2+48;
			t /= 2;
			if(s[i]=='1')c++;
			i++;
		}
		s[i] = '\0';
		l = strlen(s);
		reverse(s, s+l);
		printf("The parity of %s is %d (mod 2).\n", s, c);
	}
	return 0;
}