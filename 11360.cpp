#include<stdio.h>
#include<string.h>

int a[15][15], temp[15][15], n;
char s[100];

int isNum(char n){
	return (n>='0' && n<='9');
}

void input(){
	int i, j;
	char ch;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%c", &ch);
			if( isNum(ch) ) a[i][j] = ch - 48;
			else j--;
		}
	}
}

void row(){
	int c, r, i, t;
	scanf("%d%d", &r, &c);
	for(i=1; i<=n; i++){
		t = a[c][i];
		a[c][i] = a[r][i];
		a[r][i] = t;
	}
}

void col(){
	int c, r, i, t;
	scanf("%d%d", &r, &c);
	for(i=1; i<=n; i++){
		t = a[i][c];
		a[i][c] = a[i][r];
		a[i][r] = t;
	}
}

void inc(){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			a[i][j] = (a[i][j]+1)%10;
}

void dec(){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(a[i][j] == 0) a[i][j] = 9;
			else a[i][j]--;
		}
	}
}

void transpose(){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			temp[j][i] = a[i][j];
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			a[i][j] = temp[i][j];
}

void call_function(){
	scanf("%s", s);
	if( !strcmp(s, "row") )
		row();
	else if( !strcmp(s, "col") )
		col();
	else if( !strcmp(s, "inc") )
		inc();
	else if( !strcmp(s, "dec") )
		dec();
	else if( !strcmp(s, "transpose") )
		transpose();
}

void output_ans(){
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main(){
	freopen("11360.txt", "r", stdin);
	int t, i, cs, m;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d", &n);
		input();
		scanf("%d", &m);
		for(i=0; i<m; i++)
			call_function();
		printf("Case #%d\n", cs);
		output_ans();
	}
	return 0;
}