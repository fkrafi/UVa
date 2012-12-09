#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

char s1[110][35], s2[110][35], s[35];
int lcs[110][110];
int b[110][110], con;
string str;

void dp(int sz1, int sz2){
	int i, j;
	for(i=0; i<=sz1; i++){
		for(j=0; j<=sz2; j++){
			if(i>0 && j>0){
				if(strcmp(s1[i-1], s2[j-1]) == 0){
					lcs[i][j] = lcs[i-1][j-1] + 1;
					b[i][j] = 1;
				}else if(lcs[i-1][j] > lcs[i][j-1]){
					lcs[i][j] = lcs[i-1][j];
					b[i][j] = 2;
				}else{
					lcs[i][j] = lcs[i][j-1];
					b[i][j] = 3;
				}
			}else{lcs[i][j] = 0;}
		}
	}
}

void print_lcs(int i, int j){
	if(!i || !j)
		return;
	if(b[i][j] == 1){
		print_lcs(i-1, j-1);
		if(con)
			str += " " + string(s1[i-1]);
		else{
			str += string(s1[i-1]);
			con = 1;
		}
	}else if(b[i][j] == 2)
		print_lcs(i-1, j);
	else
		print_lcs(i, j-1);
}

int main(){
	freopen("531.txt", "r", stdin);
	int sz1, sz2;
	while(scanf("%s", s) != EOF){
		sz1=0, sz2=0;
		if(strcmp(s, "#") !=0){
			strcpy(s1[sz1++], s);
			while(scanf("%s", s)){
				if(strcmp(s, "#") == 0)break;
				strcpy(s1[sz1++], s);
			}
		}
		while(scanf("%s", s)){
			if(strcmp(s, "#") == 0)break;
			strcpy(s2[sz2++], s);
		}
		
		dp(sz1, sz2);
		print_lcs(sz1, sz2);
		
		cout << str << endl;
		str.erase();
		con = 0;
	}
	return 0;
}
