#include<stdio.h>
#include<string.h>

char str[10];

int ABS(int n){
	return (n<0)?-n:n;
}

int main(){
	freopen("12602.txt", "r", stdin);
	int d, T, a, b;
	scanf("%d", &T);
	while( T-- ){
		scanf("%s", str);
		char *s = strtok(str, "-");
		a = (s[0]-'A')*26*26 + (s[1]-'A')*26 + (s[2]-'A');
		s = strtok(NULL, "-");
		b = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
		d = ABS(a-b);
		if(d<=100){ puts("nice"); }
		else{ puts("not nice"); }
	}
	return 0;
}