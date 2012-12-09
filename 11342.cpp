#include<stdio.h>
#include<math.h>


struct store{
	int a, b, c;
}res[50005];

void CLEAR(){
	for(int i=0; i<=50000; i++)
		res[i].a = res[i].b = res[i].c = -1;
}

void ans(int n){
	int s=int(sqrt(n))+5, a, b, c, t;
	for(a=0; a<=s; a++){
		for(b=0; b<=s; b++){
			for(c=0; c<=s; c++){
				t = a*a + b*b + c*c;
				if( t>50000 )continue;
				if( res[t].a==-1 ){
					res[t].a = a;
					res[t].b = b;
					res[t].c = c;
				}
			}
		}
	}
}


int main(){
	int t, n;
	CLEAR();
	ans(50000);
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if( res[n].a == -1 )puts("-1");
		else printf("%d %d %d\n", res[n].a, res[n].b, res[n].c);
	}
	return 0;
}