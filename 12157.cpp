#include<stdio.h>

int main(){
	int t, cs=1, N, a, i, j;
	scanf("%d", &t);
	while( t--){
		scanf("%d", &N);
		int Mile=0, Juice=0;
		for(i=0; i<N; i++){
			scanf("%d", &a);
			Mile += a/30;
			if( a%30>=0 )Mile++;
			Juice += a/60;
			if( a%60>=0 )Juice++;
		}
		Mile *= 10;
		Juice *= 15;
		if( Mile == Juice ){
			printf("Case %d: Mile Juice %d\n", cs++, Mile);
		}else if( Mile<Juice ){
			printf("Case %d: Mile %d\n", cs++, Mile);
		}else{
			printf("Case %d: Juice %d\n", cs++, Juice);
		}
	}
	return 0;
}