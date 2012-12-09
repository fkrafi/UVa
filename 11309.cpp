#include<stdio.h>
#include<string.h>

int pal[2500], sz;

int palindrom(int i){
	int n = 0, t=i;
	while(i){
		n = (n*10) + (i%10);
		i /= 10;
	}
	return (n==t);
}

void generate(){
	int i, j, n;
	for(i=0; i<24; i++){
		for(j=0; j<60; j++){
			n = i*100 + j;
			if(palindrom(n))
				pal[sz++] = n;
		}
	}
}

void print_ans(int n){
	char s[10];
	s[4] = (n%10)+48; n /= 10;
	s[3] = (n%10)+48; n /= 10;
	s[2] = ':';
	s[1] = (n%10)+48; n /= 10;
	s[0] = (n%10)+48; n /= 10;
	s[5] = '\0';
	puts(s);
}

void search(int n){
	int i;
	for(i=0; i<sz; i++){
		if(pal[i]>n){
			print_ans(pal[i]);
			return;
		}
	}
	print_ans(0);
}
int main(){
	freopen("11309.txt", "r", stdin);
	generate();
	int t, h, m, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d:%d", &h, &m);
		n = h*100 + m;
		search(n);
	}
	return 0;
}