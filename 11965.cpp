#include<stdio.h>
#include<string.h>

char s[505], str[55][505];

int main(){
	freopen("11965.txt", "r", stdin);
	int t, i, n, cs, sz, pos, j, l, flag=0;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		if(flag)printf("\n");
		flag = 1;
		scanf("%d", &n); getchar();
		pos = 0;
		for(i=0; i<n; i++){
			gets(s);
			l = strlen(s);
			sz = 0;
			for(j=0; j<l; j++){
				if(s[j] == ' '){
					while(s[j] == ' ')j++;
					str[pos][sz++] = ' ';
				}
				str[pos][sz++] = s[j];
			}
			str[pos][sz] = '\0';
			pos++;
		}
		printf("Case %d:\n", cs);
		for(i=0; i<pos; i++)
			puts(str[i]);
	}
	return 0;
}