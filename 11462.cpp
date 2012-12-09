#include<stdio.h>
#include<algorithm>
using namespace std;

int age[2000001];

int main(){
	int n, i;
	while(scanf("%d", &n)){
		if(n==0)break;
		for(i=0; i<n; i++){
			scanf("%d", &age[i]);
		}
		sort(age, age+n);
		for(i=0; i<n; i++){
			if(i<n-1){
				printf("%d ", age[i]);
			}else{
				printf("%d\n", age[i]);
			}
		}
	}
	return 0;
}