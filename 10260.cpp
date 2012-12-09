#include<stdio.h>
#include<string.h>
#include<ctype.h>

int a1[] = {66, 70, 80, 86};
int a2[] = {67, 71, 74, 75, 81, 83, 88, 90};

int main(){
	char s[80], c;
	int i, l;
	while(gets(s)){
		l=strlen(s);
		for(i=0; i<l; i++){
			s[i] = toupper(s[i]);
			if(s[i] == s[i+1]){
				s[i]='O';
			}else if( (s[i]=='M' && s[i+1]=='N') || (s[i]=='N' && s[i+1]=='M') ){
				s[i]='O';
			}else if( (s[i]=='D' && s[i+1]=='T') || (s[i]=='T' && s[i+1]=='D') ){
				s[i]='O';
			}else if( (s[i]=='B' && s[i+1]=='F') ||(s[i]=='B' && s[i+1]=='P') || (s[i]=='B' && s[i+1]=='V') || (s[i]=='F' && s[i+1]=='P') || (s[i]=='F' && s[i+1]=='V') ||  (s[i]=='P' && s[i+1]=='V') || (s[i+1]=='B' && s[i]=='F') ||(s[i+1]=='B' && s[i]=='P') || (s[i+1]=='B' && s[i]=='V') || (s[i+1]=='F' && s[i]=='P') || (s[i+1]=='F' && s[i]=='V') ||  (s[i+1]=='P' && s[i]=='V') ){
				s[i]='O';
			}else if( (s[i]=='C' && s[i+1]=='G') || (s[i]=='C' && s[i+1]=='J') || (s[i]=='C' && s[i+1]=='K') || (s[i]=='C' && s[i+1]=='Q') || (s[i]=='C' && s[i+1]=='S') || (s[i]=='C' && s[i+1]=='X') || (s[i]=='C' && s[i+1]=='Z') || (s[i]=='G' && s[i+1]=='J') || (s[i]=='G' && s[i+1]=='K') || (s[i]=='G' && s[i+1]=='Q') || (s[i]=='G' && s[i+1]=='S') || (s[i]=='G' && s[i+1]=='X') || (s[i]=='G' && s[i+1]=='Z') || (s[i]=='J' && s[i+1]=='K') || (s[i]=='J' && s[i+1]=='Q') || (s[i]=='J' && s[i+1]=='S') || (s[i]=='J' && s[i+1]=='X') || (s[i]=='J' && s[i+1]=='Z') || (s[i]=='K' && s[i+1]=='Q') || (s[i]=='K' && s[i+1]=='S') || (s[i]=='K' && s[i+1]=='X') || (s[i]=='K' && s[i+1]=='Z') || (s[i]=='Q' && s[i+1]=='S') || (s[i]=='Q' && s[i+1]=='X') || (s[i]=='Q' && s[i+1]=='Z') || (s[i]=='S' && s[i+1]=='X') || (s[i]=='S' && s[i+1]=='Z') || (s[i]=='X' && s[i+1]=='Z') || (s[i+1]=='C' && s[i]=='G') || (s[i+1]=='C' && s[i]=='J') || (s[i+1]=='C' && s[i]=='K') || (s[i+1]=='C' && s[i]=='Q') || (s[i+1]=='C' && s[i]=='S') || (s[i+1]=='C' && s[i]=='X') || (s[i+1]=='C' && s[i]=='Z') || (s[i+1]=='G' && s[i]=='J') || (s[i+1]=='G' && s[i]=='K') || (s[i+1]=='G' && s[i]=='Q') || (s[i+1]=='G' && s[i]=='S') || (s[i+1]=='G' && s[i]=='X') || (s[i+1]=='G' && s[i]=='Z') || (s[i+1]=='J' && s[i]=='K') || (s[i+1]=='J' && s[i]=='Q') || (s[i+1]=='J' && s[i]=='S') || (s[i+1]=='J' && s[i]=='X') || (s[i+1]=='J' && s[i]=='Z') || (s[i+1]=='K' && s[i]=='Q') || (s[i+1]=='K' && s[i]=='S') || (s[i+1]=='K' && s[i]=='X') || (s[i+1]=='K' && s[i]=='Z') || (s[i+1]=='Q' && s[i]=='S') || (s[i+1]=='Q' && s[i]=='X') || (s[i+1]=='Q' && s[i]=='Z') || (s[i+1]=='S' && s[i]=='X') || (s[i+1]=='S' && s[i]=='Z') || (s[i+1]=='X' && s[i]=='Z') ){
				s[i]='O';
			}
			c=s[i];
			switch(c){
				case 'B':
				case 'F':
				case 'P':
				case 'V':
					printf("1");
					break;
				case 'C':
				case 'G':
				case 'J':
				case 'K':
				case 'Q':
				case 'S':
				case 'X':
				case 'Z':
					printf("2");
					break;
				case 'D':
				case 'T':
					printf("3");
					break;
				case 'L':
					printf("4");
					break;
				case 'M':
				case 'N':
					printf("5");
					break;
				case 'R':
					printf("6");
					break;
			}
		}
		printf("\n");
	}
	return 0;
}