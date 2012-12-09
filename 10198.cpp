#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define SZ 1005

string res[SZ];


string add(string a,string b){
	string c;
	int i,j,k,carry,len1=a.length(),len2=b.length(),maxlen=len2>len1 ? len2 : len1;
	for(carry=i=0;i<maxlen || carry;i++){
		j= i<len1 ? a[len1-i-1]-'0':0;
        k= i<len2 ? b[len2-i-1]-'0':0;
		c+=((j+k+carry)%10)+'0';
		carry=(j+k+carry)/10;
	}
	reverse(c.begin(),c.end());
	return c;
}

void gen(){
	int i;
	res[1] = "2"; res[2] = "5"; res[3] = "13"; res[4] = "33";
	for(i=5; i<=1000; i++){
		res[i] = add( add(res[i-1], res[i-2]), add(res[i-1], res[i-3]) );
	}
}


int main(){
	int N;
	gen();
	while( scanf("%d", &N) != EOF ){
		cout << res[N] << "\n";
	}
	return 0;
}