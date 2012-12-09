#include<stdio.h>
#include<ctype.h>
#include<string.h>

int cnt[255];
char s[100005];

int main(){
	int t, i, j, max, l;
	scanf("%d", &t);getchar();
	while(t--){
		gets(s);
		max = -1;
		l = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		for(i=0; i<l; i++){
			if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ){
				j = tolower(s[i]);
				cnt[j]++;
				if( max<cnt[j] )max=cnt[j];
			}
		}
		for(i='a'; i<='z'; i++){
			if( max==cnt[i] )
				printf("%c", i);
		}
		printf("\n");
	}
	return 0;
}