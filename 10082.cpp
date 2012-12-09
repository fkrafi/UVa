#include<stdio.h>
#include<string.h>

char s[10000];

char change(char ch){
	if(ch=='W'){
		return 'Q';
	}else if(ch=='E'){
		return 'W';
	}else if(ch=='R'){
		return 'E';
	}else if(ch=='T'){
		return 'R';
	}else if(ch=='Y'){
		return 'T';
	}else if(ch=='U'){
		return 'Y';
	}else if(ch=='I'){
		return 'U';
	}else if(ch=='O'){
		return 'I';
	}else if(ch=='P'){
		return 'O';
	}else if(ch=='['){
		return 'P';
	}else if(ch==']'){
		return '[';
	}else if(ch=='\\'){
		return ']';
	}else if(ch=='S'){
		return 'A';
	}else if(ch=='D'){
		return 'S';
	}else if(ch=='F'){
		return 'D';
	}else if(ch=='G'){
		return 'F';
	}else if(ch=='H'){
		return 'G';
	}else if(ch=='J'){
		return 'H';
	}else if(ch=='K'){
		return 'J';
	}else if(ch=='L'){
		return 'K';
	}else if(ch==';'){
		return 'L';
	}else if(ch=='\''){
		return ';';
	}else if(ch=='X'){
		return 'Z';
	}else if(ch=='C'){
		return 'X';
	}else if(ch=='V'){
		return 'C';
	}else if(ch=='B'){
		return 'V';
	}else if(ch=='N'){
		return 'B';
	}else if(ch=='M'){
		return 'N';
	}else if(ch==','){
		return 'M';
	}else if(ch=='.'){
		return ',';
	}else if(ch=='/'){
		return '.';
	}else if(ch=='1'){
		return '`';
	}else if(ch=='2'){
		return '1';
	}else if(ch=='3'){
		return '2';
	}else if(ch=='4'){
		return '3';
	}else if(ch=='5'){
		return '4';
	}else if(ch=='6'){
		return '5';
	}else if(ch=='7'){
		return '6';
	}else if(ch=='8'){
		return '7';
	}else if(ch=='9'){
		return '8';
	}else if(ch=='0'){
		return '9';
	}else if(ch=='-'){
		return '0';
	}else if(ch=='='){
		return '-';
	}else{
		return ch;
	}
}

int main(){
	int i, l;
	while(gets(s)){
		l = strlen(s);
		for(i=0; i<l; i++){
			printf("%c", change(s[i]));
		}
		printf("\n");
	}
	return 0;
}