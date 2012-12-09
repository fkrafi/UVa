#include<stdio.h>
#include<string.h>
#define SZ 100005

int best[SZ], arr[SZ], p[SZ], sz, last;
char s[15];

int max(int a, int b){
	return (a>b)?a:b;
}

int lis(int n){
	int ans = 0, i, j;
	for(i=1; i<=n; i++){
		best[i]=1;
		p[i] = -1;
		for(j=1; j<i; j++){
			if(arr[j]<arr[i] && best[j]+1>best[i]){
				best[i] = best[j]+1; 
				p[i] = j;
			}
		}
		if(best[i]>ans){
			ans = best[i];
			last= i;
		}
	}
	return ans;
}

int str2int(int l){
	int n=0, i;
	for(i=0; i<l; i++){
		if( s[i]>='0' && s[i]<='9')
			n = n*10 + s[i]-'0';
	}
	return n;
}

void input(){
	int l;
	sz = 1;
	while( gets(s) ){
		l = strlen(s);
		if( !l )break;
		arr[sz++] = str2int(l);
	}
	sz--;
}


void output(int now){
	if(now<0)return;
	output(p[now]);
	printf("%d\n", arr[now]);
}

int main(){
	freopen("497.txt", "r", stdin);
	int t, cs, res;
	scanf("%d", &t);getchar();getchar();
	for(cs=1; cs<=t; cs++){
		input();
		res = lis(sz);
		printf("Max hits: %d\n", res);
		if(res)
			output(last);
		if(cs!=t)printf("\n");
	}
	return 0;
}