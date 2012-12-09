#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

string nums[100005];
string last, m, first;

void match(string a, string b){
	int l = a.length(), i, j=0;
	m = "";

	for(i=0; i<l; i++)
		if( a[i] != b[i] )break;
	
	for(; i<l; i++){
		m += b[i];
		j++;
	}
	if(!j)m="A";
}


string sub(string a,string b){
	string c;
	int i,j,k,carry,len1=a.length(),len2=b.length(),maxlen=len2>len1 ? len2 : len1;
	for(carry=i=0;i<maxlen || carry;i++){
		j= i<len1 ? a[len1-i-1]-'0':0;
		k= i<len2 ? b[len2-i-1]-'0':0;
		k+=carry;
		if(j<k) c+= 10+j-k+'0',carry=1;
		else c+=j-k+'0',carry=0;
	}
	for(j=c.length(),i=j-1;i>=0;i--) if(c[i]!='0') break;
	if(i<j-1) j=i+1;
	if(j==0) j++;
	for(k=j/2,i=0;i<k;i++) swap(c[i],c[j-i-1]);
	return c.substr(0,j);
}

int main(){
	freopen("12085.txt", "r", stdin);
	int N, i, cs=1;
	while( scanf("%d", &N) ){
		if( !N )break;
		for(i=0; i<N; i++)cin >> nums[i];
		printf("Case %d:\n", cs++);
		first = last = nums[0];
		cout << last;
		m = "*";
		for(i=1; i<N; i++){
			if( sub(nums[i], last) == "1" ){
				last = nums[i];
				continue;
			}
			match(first, nums[i-1]);
			if( m == "A" )cout << "\n";
			else cout << "-" << m << "\n";
			first = last = nums[i];
			cout << last;
			m = "*";
		}
		if( m == "*" ){
			match(first, nums[i-1]);
			if( m == "A" )cout << "\n";
			else cout << "-" << m << "\n";
		}
		cout << "\n";
	}
	return 0;
}