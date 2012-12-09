#include<stdio.h>
#include<string.h>

int dis;
char t[105];
int flag[11];

void CLEAR(){
	for(int i=0; i<=10; i++)
		flag[i] = 0;
}


int main(){
	freopen("10530.txt", "r", stdin);
	int n, i;
	CLEAR();
	while( scanf("%d", &n) ){
		if( !n )break;
		getchar(); gets(t);
		if( !strcmp(t, "right on") ){
			if( !flag[n] ){
				puts("Stan may be honest");
			}else{
				puts("Stan is dishonest");
			}
			CLEAR();
		}else if( !strcmp(t, "too high") ){
			for(i=n; i<=10; i++)flag[i]=1;
		}else if( !strcmp(t, "too low") ){
			for(i=n; i>0; i--)flag[i]=1;
		}
	}
	return 0;
}