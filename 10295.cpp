#pragma warning( disable : 4786 )
#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;


map<string, int> M;
char s[1000005];


int main(){
	freopen("10295.txt", "r", stdin);
	int n, m, l;
	long long int cst;
	while( scanf("%d%d", &n, &m) != EOF ){
		M.clear();
		while(n--){
			scanf("%s%d", s, &l);
			M[string(s)] = l;
		}
		while(m--){
			cst = 0;
			while(gets(s)){
				if( s[0]=='.' )break;
				char *pch = strtok(s, " 1234567890");
				while( pch != NULL ){
					cst += M[string(pch)];
					pch = strtok(NULL, " 1234567890");
				}
			}
			printf("%lld\n", cst);
		}
	}
	return 0;
}