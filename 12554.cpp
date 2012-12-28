#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;


string rel[105];
string song[] = {
	"Happy", "birthday", "to", "you", 
	"Happy", "birthday", "to", "you", 
	"Happy", "birthday", "to", "Rujia", 
	"Happy", "birthday", "to", "you"
};

int main(){
	freopen("12554.txt", "r", stdin);
	int N, i, j;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		cin >> rel[i];
	}
	for(i=0, j=0; i<N; i++, j=(j+1)%16){
		cout << rel[i] << ": " << song[j] << "\n";
	}
	if( j!=0 ){
		for(i=0; j<16; j++, i=(i+1)%N){
			cout << rel[i] << ": " << song[j] << "\n";
		}
	}
	return 0;
}