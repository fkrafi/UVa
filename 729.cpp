#include<stdio.h>
#include<string.h>

int pw[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};


void generate(int n, int h){
	int t, s=pw[n], i, j, c, cnt;
	char str[100];
	for(i=1; i<s; i++){
		t = i;
		c = 1;
		cnt = 0;
		for(j=n; j>=1; j--){
			if(t & c){
				cnt++;
				str[j-1] = '1';
			}else str[j-1]='0';
			c = c<<1;
		}
		if(cnt == h){
			str[n] = '\0';
			puts(str);
		}
	}
}

int main(){
	int t, n, h, flag=0;
	scanf("%d", &t);
	while( t-- ){
		if(flag)printf("\n");
		flag = 1;
		scanf("%d%d", &n, &h);
		generate(n, h);
	}
	return 0;
}