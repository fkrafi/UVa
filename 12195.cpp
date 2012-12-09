#include<stdio.h>
#include<string.h>

double val[10];
char s[205];

int main(){
	freopen("12195.txt", "r", stdin);
	double sum;
	int i, l, cnt;
	val['W'] = 1;
	val['H'] = 0.5;
	val['Q'] = 0.25;
	val['E'] = 0.125;
	val['S'] = 0.0625;
	val['T'] = 0.03125;
	val['X'] = 0.015625;
	while(gets(s)){
		if( s[0] == '*')break;
		char *pch = strtok(s, "/");
		cnt = 0;
		while( pch != NULL ){
			l = strlen(pch);
			sum = 0;
			for(i=0; i<l; i++)sum += val[pch[i]];
			if( sum == 1 )cnt++;
			pch = strtok(NULL, "/");
		}
		printf("%d\n", cnt);
	}
	return 0;
}