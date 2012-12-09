#include<stdio.h>
#include<string.h>
#define SZ 105

int a[SZ], p;
char s[100005];

int main(){
	freopen("11956.txt", "r", stdin);
	int T, cs, i, len;
	scanf("%d", &T); getchar();
	for(cs=1; cs<=T; cs++){
		gets(s);
		len = strlen(s);
		p = 0;
		memset(a, 0, sizeof(a));
		for(i=0; i<len; i++){
			if( s[i]=='>' ){
				p = (p+1)%100;
				if(p>99)p=0;
			}else if( s[i]=='<' ){
				p = p-1;
				if(p<0)p=99;
			}else if( s[i]=='+' ){
				a[p] = a[p]+1;
				if( a[p]>255 )a[p]=0;
			}else if( s[i]=='-' ){
				a[p] = a[p]-1;
				if( a[p]<0 )a[p]=255;
			}
		}
		printf("Case %d:", cs);
		for(i=0; i<100; i++){
			printf(" %02X", a[i]);
		}
		printf("\n");
	}
	return 0;
}