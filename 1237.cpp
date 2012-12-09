#include<stdio.h>

struct companyDetails{
	char name[25];
	int L, H;
}com[10005];



int ser( int p, int d){
	int i, pos=-1, cnt=0;
	for(i=0; i<d; i++){
		//if( com[i].L<=p && com[i].H<=p )break;
		if( com[i].L<=p && com[i].H>=p ){
			pos = i;
			cnt++;
		}
		if( cnt>1 )return -1;
	}
	return pos;
}

int main(){
	freopen("1237.txt", "r", stdin);
	int t, q, d, i, p, pos, flag=0;
	scanf("%d", &t);
	while( t-- ){
		if( flag )printf("\n");
		flag = 1;
		scanf("%d", &d);
		for(i=0; i<d; i++)
			scanf("%s%d%d", com[i].name, &com[i].L, &com[i].H);
		scanf("%d", &q);
		for( i=0; i<q; i++ ){
			scanf("%d", &p);
			pos = ser(p, d) ;
			if( pos == -1 ){
				puts("UNDETERMINED");
			}else{
				puts(com[pos].name);
			}
		}
	}
	return 0;
}