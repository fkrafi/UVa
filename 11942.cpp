#include<stdio.h>

int a[15];

void less(){
	int i, con=1;
	for(i=3; i<=10; i++){
		scanf("%d", &a[i]);
		if( a[i-1] > a[i] )
			con = 0;
	}
	if(con)puts("Ordered");
	else puts("Unordered");
}

void great(){
	int i, con=1;
	for(i=3; i<=10; i++){
		scanf("%d", &a[i]);
		if( a[i-1] < a[i] )
			con = 0;
	}
	if(con)puts("Ordered");
	else puts("Unordered");
}

int main(){
	freopen("11942.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	puts("Lumberjacks:");
	while(t--){
		scanf("%d%d", &a[1], &a[2]);
		if(a[1] < a[2])
			less();
		else
			great();
	}
	return 0;
}