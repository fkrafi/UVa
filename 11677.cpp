#include<stdio.h>

int main(){
	freopen("11677.txt", "r", stdin);
	int curH, curM, setH, setM, curT, setT;
	while( scanf("%d%d%d%d", &curH, &curM, &setH, &setM) ){
		if( !curH && !curM && !setH && !setM )break;
		if(!curH)curH=24;
		if(!setH)setH=24;
		curT = curH*60 + curM;
		setT = setH*60 + setM;
		if( setT < curT )setT += 1440;
		printf("%d\n", (setT-curT));
	}
	return 0;
}