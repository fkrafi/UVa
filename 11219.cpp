#include<stdio.h>

int dd1, mm1, yy1;
int dd2, mm2, yy2;

int isLeap(int y){
	return ( (y%4==0 && y%100!=0) || (y%400==0) );
}


int isValid(){
	int day[] = {
		31, 28, 31, 30, 
		31, 30, 31, 31, 
		30, 31, 30, 31
	};
	if( mm1>12 || mm2>12 || mm1<0 || mm2<0)return 0;
	if( mm1==2 ){
		if( isLeap(yy1) ){
			if( dd1>29 )return 0;
		}else{
			if( dd1>day[mm1-1] )return 0;
		}
	}
	if( mm2==2 ){
		if( isLeap(yy2) ){
			if( dd2>29 )return 0;
		}else{
			if( dd2>day[mm2-1] )return 0;
		}
	}
	
	if( yy1==yy2 ){
		if( mm1==mm2 ){
			if( dd2>dd1 )return 0;
		}
		if( mm2>mm1 )return 0;
	}
	if( yy2>yy1 )return 0;
	return 1;
}

int cal(){
	int age=yy1-yy2;
	if( mm1<mm2 && age ){
		age--;
	}else if( mm1<=mm2 ){
		if( dd1<dd2 && age )age--;
	}
	return age;
}

int main(){
	freopen("11219.txt", "r", stdin);
	int cs, t, age;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d/%d/%d", &dd1, &mm1, &yy1);
		scanf("%d/%d/%d", &dd2, &mm2, &yy2);
		if( !isValid() ){
			printf("Case #%d: Invalid birth date\n", cs);
		}else{
			age = cal();
			if( age>130 ){
				printf("Case #%d: Check birth date\n", cs);
			}else{
				printf("Case #%d: %d\n", cs, age);
			}
		}
	}
	return 0;
}