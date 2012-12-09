#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;


char s[2001], ch, temp[2001], ans[2001];
int p[2001];

int prime(int n){
	int i, s;
	if(n==1)return 0;
	if(n==2)return 1;
	s = int(sqrt(n));
	for(i=2; i<=s; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int t, i, a, b,c, l, j, k, count, con;
	scanf("%d%c", &t, &ch);
	for(i=1; i<=t; i++){
		gets(s);
		a=0; b=0;
		l = strlen(s);
		for(j=0; j<l; j++){
			c = 1; count=1;
			for(k=0; k<a; k++){
				if(temp[k] == s[j]){
					c = 0;
					break;
				}
			}
			if(c==1){
				temp[a] = s[j];
				for(k=j+1; k<l; k++){
					if(s[k] == temp[a])count++;
				}
				if(prime(count) == 1){
					ans[b++] = temp[a];
				}
				a++;
			}
		}
		ans[b] = '\0';
		printf("Case %d: ", i);
		l = strlen(ans);
		sort(ans, ans+l);
		if(l==0){
			printf("empty\n", i);
		}else{
			puts(ans);
		}
	}
	return 0;
}