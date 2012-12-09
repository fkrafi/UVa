#include<stdio.h>
#include<string.h>

char s[100], str[105][100];
char M[300];

void MAP(){
	int i;
	for(i=0; i<300; i++)M[i] = i;
	M['0'] = 'O'; M['1'] = 'I'; M['2'] = 'Z'; M['3'] = 'E'; M['4'] = 'A'; 
	M['5'] = 'S'; M['6'] = 'G'; M['7'] = 'T'; M['8'] = 'B'; M['9'] = 'P';
}

int main(){
	freopen("11946.txt", "r", stdin);
	MAP();
	int t, l, i, flag=0, pos;
	scanf("%d", &t);getchar();
	while(t--){
		if(flag)printf("\n");
		flag=1;
		pos = 0;
		while(gets(s)){
			l = strlen(s);
			if(!l || s[0]=='\n' || s[0]=='\0')break;
			for(i=0; i<l; i++)
				str[pos][i] = M[s[i]];
			str[pos][i] = '\0';
			pos++;
		}
		for(i=0; i<pos; i++)
			puts(str[i]);
	}
	return 0;
}