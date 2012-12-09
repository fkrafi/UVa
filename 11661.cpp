#include<stdio.h>
#include<string.h>

int con, D, R;

int isValid(char ch){
	return (ch=='.' || ch=='R' || ch=='D' || ch=='Z');
}

int ab(int n){
	return (n<0)?-n:n;
}

int solve(int L){
	int i, ret=999999999, dis;
	char ch;
	con = R = D = 0;
	for(i=1; i<=L; i++){
		scanf("%c", &ch);
		if(con)continue;
		if( isValid(ch) ){
			if(ch=='Z')con = 1;
			else if(ch=='D')D=i;
			else if(ch=='R')R=i;

			if(D && R){
				dis = ab(D-R);
				ret = (ret>dis)?dis:ret;
			}
		}else i--;
	}
	if(con)return 0;
	return ret;
}

int main(){
	freopen("11661.txt", "r", stdin);
	int res, L;
	while( scanf("%d", &L) ){
		if( !L )break;
		res = solve(L);
		printf("%d\n", res);
	}
	return 0;
}