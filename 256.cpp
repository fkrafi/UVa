#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int dNo;
int arr[10];

/*
int chk(){
int L=arr[1], H=arr[dNo/2+1], i, N=arr[1];
for(i=2; i<=dNo; i++){
N = N*10 + arr[i];
if( i<=dNo/2 )
L = L*10 + arr[i];
else if(i>dNo/2+1)
H = H*10 + arr[i];
}
return N==((L+H)*(L+H));
}

  void output(){
  int i;
  for(i=1; i<=dNo; i++)
		printf("%d", arr[i]);
		printf("\n");
		}
		
		  
			void BtKt(int pos){
			if( pos>dNo ){
			if( chk() )
			output();
			return;
			}
			int i;
			for(i=0; i<=9; i++){
			arr[pos] = i;
			BtKt(pos+1);
			}
			}
*/


int lm[10];
string res[10][15];

void generate(){
	lm[2] = 3;
	res[2][1] = "00";
	res[2][2] = "01";
	res[2][3] = "81";
	
	lm[4] = 5;
	res[4][1] = "0000";
	res[4][2] = "0001";
	res[4][3] = "2025";
	res[4][4] = "3025";
	res[4][5] = "9801";
	
	lm[6] = 5;
	res[6][1] = "000000";
	res[6][2] = "000001";
	res[6][3] = "088209";
	res[6][4] = "494209";
	res[6][5] = "998001";

	lm[8] = 9;
	res[8][1] = "00000000";
	res[8][2] = "00000001";
	res[8][3] = "04941729";
	res[8][4] = "07441984";
	res[8][5] = "24502500";
	res[8][6] = "25502500";
	res[8][7] = "52881984";
	res[8][8] = "60481729";
	res[8][9] = "99980001";
	
}


int main(){
	int i;
	generate();
	while(scanf("%d", &dNo) != EOF){
		for(i=1; i<=lm[dNo]; i++)
			cout << res[dNo][i] << "\n";
	}
	return 0;
}