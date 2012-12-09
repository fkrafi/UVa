#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char R[100], N[100], dash[100], temp[100];
int neg;

int gcd( int m, int n ){
	if( !m )return n;
	return gcd(n%m, m);
}

void ITOS(int res, int n){
	int i=0, j=0, k=0, div=0, t=0;
	dash[0] = '\0';
	if( res%n !=0 )div = res/n;
	if(div)res %= n;
	while( res ){
		R[i++] = res%10 + 48;
		res /= 10;
	}
	while( n ){
		N[j++] = n%10 + 48;
		n /= 10;
	}
	while( i < j ){
		R[i++] = ' ';
	}
	if(neg){
		dash[k++] = '-';
		dash[k++] = ' ';
		R[i++] = ' '; R[i++] = ' ';
		N[j++] = ' '; N[j++] = ' ';
		dash[k] = '\0';
	}
	if( div ){
		while( div ){
			temp[t++] = div%10 + 48;
			div /= 10;
			R[i++] = ' ';
			N[j++] = ' '; 
		}
		temp[t] = '\0';
		reverse(temp, temp+t);
		strcat(dash, temp);
		k += t;
	}
	R[i] = N[j] = '\0';
	reverse(R, R+i);
	reverse(N, N+j);
	for(; k<j; k++)dash[k] = '-';
	dash[k] = '\0';
}

int main(){
	freopen("12060.txt", "r", stdin);
	int n, res, a, i, cs=1;
	while( scanf("%d", &n) ){
		if( !n )break;
		neg = res = 0;
		for(i=0; i<n; i++){
			scanf("%d", &a);
			res += a;
		}
		if( res < 0){
			neg = 1;
			res *= -1;
		}
		printf("Case %d:\n", cs++);
		if( res%n == 0 ){
			if(neg)printf("- ");
			printf("%d\n", res/n);
		}else{
			a = gcd(res, n);
			if( a != 1 ){
				res /= a;
				n /= a;
			}
			ITOS(res, n);
			puts(R);
			puts(dash);
			puts(N);
		}
	}
	return 0;
}