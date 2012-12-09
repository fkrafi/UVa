#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[1000], temp[1000];
int len, Star, Plus;
double Max, Min;

int isNum(char ch){
	return (ch>='0' && ch<='9');
}

void calMax(){
	int i, pos=0, sum, n;
	char str[10];
	temp[0] = '\0';
	Star = Plus = 0;
	for(i=0; i<len; i++){
		if(s[i]=='*')Star = 1;
		if(s[i]=='+')Plus = 1;
		if( isNum(s[i]) ){
			sum = 0;
			n = 0;
			while( i<len && s[i]!='*' ){
				if(s[i]=='*')Star = 1;
				if(s[i]=='+')Plus = 1;
				if( isNum(s[i]) )
					n = n*10 + (s[i]-48);
				else{
					sum += n;
					n = 0;
				}
				i++;
			}
			if(n)sum += n;
			n = 0;
			while(sum){
				str[n++] = (sum%10) + 48;
				sum /= 10;
			}
			while(n)
				temp[pos++] = str[--n];
		}
		temp[pos++] = s[i];
	}
	Max = 1;
	for(i=0; i<pos; i++){
		if(isNum(temp[i])){
			n = 0;
			while( i<pos && isNum(temp[i]) ){
				n = n*10 + (temp[i]-48);
				i++;
			}
			if(n)Max *= n;
		}
	}
}

void calMin(){
	int i, pos=0, j;
	long long int sum, n;
	char str[10];
	temp[0] = '\0';
	for(i=0; i<len; i++){
		if( isNum(s[i]) ){
			sum = 1;
			n = 0;
			while( i<len && s[i]!='+' ){
				if( isNum(s[i]) )
					n = n*10 + (s[i]-48);
				else{
					sum *= n;
					n = 0;
				}
				i++;
			}
			if(n)sum *= n;
			j = 0;
			while(sum){
				str[j++] = (sum%10) + 48;
				sum /= 10;
			}
			while(j)
				temp[pos++] = str[--j];
		}
		temp[pos++] = s[i];
	}
	Min = 0;
	for(i=0; i<pos; i++){
		if(isNum(temp[i])){
			n = 0;
			while( i<pos && isNum(temp[i]) ){
				n = n*10 + (temp[i]-48);
				i++;
			}
			if(n)Min += n;
		}
	}
}

int main(){
	freopen("10700.txt", "r", stdin);
	int t;
	scanf("%d", &t);getchar();
	while(t--){
		gets(s);
		len = strlen(s);
		calMax();
		calMin();
		printf("The maximum and minimum are %.0lf and %.0lf.\n", Max, Min);
	}
	return 0;
}
