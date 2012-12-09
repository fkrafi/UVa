#include<stdio.h>

int ab(int n){
	return (n<0)?-n:n;
}

int main(){
	freopen("11958.txt", "r", stdin);
	int t, cs, sh, sm, hh, mm, k, i, du, res, temp, cur;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d%d:%d", &k, &sh, &sm);
		cur = sh*60+sm;
		res = 999999999;
		for(i=0; i<k; i++){
			scanf("%d:%d %d", &hh, &mm, &du);
			temp = hh*60+mm;
			if(temp < cur)temp += (24*60);
			temp += du;
			temp = ab(temp-cur);
			if(res > temp)res = temp;
		}
		printf("Case %d: %d\n", cs, res);
	}
	return 0;
}