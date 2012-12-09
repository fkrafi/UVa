#include<stdio.h>
#include<string.h>

void pri(char c){
	if(c == ']'){
		printf("p");
	}else if(c == '['){
		printf("o");
	}else if(c == 'p' || c == 'P'){
		printf("i");
	}else if(c == 'o' || c == 'O'){
		printf("u");
	}else if(c == 'i' || c == 'I'){
		printf("y");
	}else if(c == 'u' || c == 'U'){
		printf("t");
	}else if(c == 'y' || c == 'Y'){
		printf("r");
	}else if(c == 't' || c == 'T'){
		printf("e");
	}else if(c == 'r' || c == 'R'){
		printf("w");
	}else if(c == 'e' || c == 'E'){
		printf("q");
	}else if(c == '\''){
		printf("l");
	}else if(c == ';'){
		printf("k");
	}else if(c == 'l' || c == 'L'){
		printf("j");
	}else if(c == 'k' || c == 'K'){
		printf("h");
	}else if(c == 'j' || c == 'J'){
		printf("g");
	}else if(c == 'h' || c == 'H'){
		printf("f");
	}else if(c == 'g' || c == 'G'){
		printf("d");
	}else if(c == 'f' || c == 'F'){
		printf("s");
	}else if(c == 'd' || c == 'D'){
		printf("a");
	}else if(c == '.'){
		printf("m");
	}else if(c == ','){
		printf("n");
	}else if(c == 'm' || c == 'M'){
		printf("b");
	}else if(c == 'n' || c == 'N'){
		printf("v");
	}else if(c == 'b' || c == 'B'){
		printf("c");
	}else if(c == 'v' || c == 'V'){
		printf("x");
	}else if(c == 'c' || c == 'C'){
		printf("z");
	}else if(c == 's' || c == 'S'){
		printf("]");
	}else if(c == 'a' || c == 'A'){
		printf("[");
	}else if(c == 'x' || c == 'X'){
		printf("\\");
	}else if(c == 'z' || c == 'Z'){
		printf("\'");
	}
}


char s[10000];

int main(){
	int i, l;
	gets(s);
	l = strlen(s);
	for(i=0; i<l; i++){
		if(s[i] != ' '){
			pri(s[i]);
		}else{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}