#include<stdio.h>

int MIN(int a, int b){
	return (a<b)?a:b;
}

int main(){
	int C1, C2, cnt1, cnt2, i;
	while(scanf("%d%d", &C1, &C2)){
		if( C1<0 && C2<0 )break;
		for(i=C1, cnt1=0; i!=C2; cnt1++){
			i--;
			if(i<0)i=99;
		}
		for(i=C1, cnt2=0; i!=C2; cnt2++){
			i++;
			if(i>99)i=0;
		}
		printf("%d\n", MIN(cnt1, cnt2));
	}
	return 0;
}