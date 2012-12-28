#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
using namespace std;

string str;
char s[260];
int prime[100005];

void sieve(int n){
   prime[0]=1;
   prime[1]=1;
   int m = int(sqrt(n)), i=2, k;
   for(k=i*i; k<=n; k+=i)
      prime[k]=1;
   for (i=3; i<=m; i+=2)
      if(!prime[i])
         for (k=i*i; k<=n; k+=i)
            prime[k]=1;
}

int intVal(string s){
	int i, n=0, l=s.length();
	for(i=0; i<l; i++){
		n = n*10+(s[i]-'0');
	}
	return n;
}

int main(){
	freopen("12542.txt", "r", stdin);
	int i, j, len, res, n;
	sieve(100000);
	while( gets(s) ){
		if( !strcmp(s, "0") )break;
		res = 0;
		len = strlen(s);
		for(i=0; i<len; i++){
			str = "";
			for(j=0; j<7 && i+j<len; j++){
				str += s[i+j];
				n = intVal(str);
				if( n<=100000 && !prime[n] && n>res ){
					res = n;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
