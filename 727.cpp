#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

char in[55], post[55], str[55];

void take_input(){
	int k = 0;
	while(gets(str)){
		if(str[0]=='\0')
			break;
		post[k++] = str[0];
	}
	post[k] = '\0';
}

int precedence(char ch){
	switch(ch){
	case '$':
		return 1;
	case '(':
		return 2;
	case '+':
	case '-':
		return 3;
	case '*':
	case '/':
		return 4;
	}
	return 0;
}

int isOperator(char ch){
	if(ch>=36 && ch<=47)
		return 1;
	return 0;
}

void convert(){
	int j=0, i=-1;
	int l = strlen(in);
	in[l] = '$';
	in[l+1] = '\0';
	char x;
	stack<char> stk;
	stk.push('#');
	while(stk.top() != '$')
	{
		i++;
		if( !isOperator(in[i]) ){
			post[j++] = in[i];
		}else if( in[i] == '(' ){
			stk.push(in[i]);
		}else if( in[i] == ')' ){
			x = stk.top();
			stk.pop();
			while( x != '(' ){
				post[j++] = x;
				x = stk.top();
				stk.pop();
			}
		}else{
			while( precedence(in[i]) <= precedence( stk.top() ) ){
				post[j++] = stk.top();
				stk.pop();
			}
			stk.push(in[i]);
		}
	}
	post[j] = '\0';
}

void clean(){
	int i, j, l=strlen(post);
	strcpy(str, post);
	for(i=0, j=0; i<l; i++){
		post[j++] = str[i];
		if( i<(l-1) && str[i]==')' && (str[i+1]=='(' || !isOperator(str[i+1])) ){
			post[j++] = '*';
		}
	}
	post[j] = '\0';
	strcpy(in, post);
}

int main(){
	freopen("727.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	getchar();getchar();
	while(t--){
		take_input();
		clean();
		convert();
		puts(post);
		if(t>0)
			printf("\n");
	}
	return 0;
}