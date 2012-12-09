#include<stdio.h>
#include<math.h>
/*
int isCarmichaelNumber(int n){
	int s=int(sqrt(n)), t=n, i, cnt=0, noF=0;
	while(n%2==0){
		cnt++;
		n/=2;
		noF++;
	}
	if(cnt>1)return 0;
	for(i=3; i<=s; i+=2){
		cnt=0;
		if(n%i==0){
			noF++;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			if(cnt>1)return 0;
			if( (t-1)%(i-1) != 0 )return 0;
		}
	}
	if(noF<3)return 0;
	return 1;
}
*/
int car[] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};

int bs(int l, int h, int z){
	int mid = (l+h)/2;
	if(l<=h){
		if(z == car[mid])return 1;
		if(z<car[mid])return bs(l, mid-1, z);
		else if(z>car[mid])return bs(mid+1, h, z);
	}
	return 0;
}

int main(){
	int i;
	/*for(i=1; i<=65000; i++){
		if(isCarmichaelNumber(i))
			printf("%d\n", i);
	}*/
	while(scanf("%d", &i)){
		if(!i)break;
		if( bs(0, 14, i) )
			printf("The number %d is a Carmichael number.\n", i);
		else
			printf("%d is normal.\n", i);
	}
	return 0;
}