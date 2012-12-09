#include<stdio.h>
#include<string.h>

char s1[10], s2[10], s3[10], s4[10], s[20];

int d2(int n){
	int ret=0;
	while(n){
		ret += n%10;
		n /= 10;
	}
	return ret;
}

int main(){
	freopen("11743.txt", "r", stdin);
	int t, i, sum;
	scanf("%d", &t);
	while(t--){
		scanf("%s%s%s%s", s1, s2, s3, s4);
		strcpy(s, s1); strcat(s, s2); strcat(s, s3); strcat(s, s4);
		sum = 0;
		for(i=0; i<16; i++){
			if( i%2 )
				sum += s[i]-48;
			else
				sum += d2((s[i]-48)*2);
		}
		if(sum%10)
			puts("Invalid");
		else
			puts("Valid");
	}
	return 0;
}