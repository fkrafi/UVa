#include<stdio.h>
#include<string.h>


char mask[][100] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
int len[] ={3, 5, 5, 3, 5, 4, 3, 4, 3};
char s[105][85], map[25];
int cs=1;

int isChar(char ch){
	return (ch>='a' && ch<='z');
}

void CLEAR(){
	int i;
	for(i=0; i<=25; i++)
		map[i] = '0';
}

int match(int pos){
	CLEAR();
	char *pch;
	char temp[100];
	int j=0, l, i;
	strcpy(temp, s[pos]);
	pch = strtok(temp, " ");
	while(pch != NULL)
	{
		l = strlen(pch);
		if( l == len[j] ){
			for(i=0; i<len[j]; i++){
				if( map[pch[i]-'a'] != '0' && map[pch[i]-'a']!=mask[j][i] )return 0;
				else if( map[pch[i]-'a'] == '0' )map[pch[i]-'a'] = mask[j][i];
			}
		}else return 0;
		pch = strtok(NULL, " ");
		j++;
	}
	return 1;
}


int main(){
	freopen("850.txt", "r", stdin);
	int t, i, con, l, j, flag=0;
	scanf("%d", &t);getchar();
	gets(s[0]);
	while(t--){
		if(flag)printf("\n");
		flag = 1;
		i = 0;
		con = 0;
		while(gets(s[++i])){
			if(s[i][0]=='\n' || s[i][0]=='\0' || strlen(s[i])==0)break;
			if(con)continue;
			
			if( match(i) )con = 1;
		}
		if(con){
			for(l=1; l<i; l++){
				con = strlen(s[l]);
				for(j=0; j<con; j++){
					if(s[l][j] == ' ')printf(" ");
					else printf("%c", map[s[l][j]-'a']);
				}
				printf("\n");
			}
		}else{
			puts("No solution.");
		}
	}
	return 0;
}