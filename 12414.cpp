#include<stdio.h>
#include<string.h>

char str[120];
char s[100000];

void convert(int ST){
	char temp[10];
	int l=strlen(str), i, j, k=0, t;
	for(i=0; i<l; i++){
		t = ST + str[i] - 'A';
		j = 0;
		while(t){
			temp[j++] = t%10+48;
			t /= 10;
		}
		j--;
		while(j>=0)
			s[k++] = temp[j--];
	}
	s[k] = '\0';
}

int check(){
	int l=strlen(s), i;
	while( l>=3 ){
		for(i=0; i<l-1; i++){
			s[i] = ( (s[i]-48) + (s[i+1]-48) )%10 + 48;
		}
		if( i==3 && s[0]=='1' && s[1]=='0' && s[2]=='0' )return 1;
		l = i;
	}
	return 0;
}


int main(){
	freopen("12414.txt", "r", stdin);
	int i;
	while(gets(str)){
		for(i=1; i<=10000; i++){
			convert(i);
			if( check() )break;
		}
		if( i<=10000 ){ printf("%d\n", i);}
		else{ puts(":("); }
	}
	return 0;
}