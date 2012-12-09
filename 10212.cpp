#include<stdio.h>
#include<math.h>

void last_digit(long int n, long int m)
{
	long int count2=0, count5=0, last=1, tp, i;
	for(i=n-m+1; i<=n; i++){
		tp = i;
		while(!(tp%10))tp/=10;
		while(!(tp&1))
		{
			tp >>= 1;
			count2++;
		}
		while(!(tp%5))
		{
			tp /= 5;
			count5++;
		}
		tp = tp%10;
		last *= tp;
		last = last%10;
	}

	if(count2 >= count5){
		for (i=count5+1; i<=count2; i++){
			last *=2;
			last = last%10;
		}
	}else{
		for (i=count2+1; i<=count5; i++){
			last*=5;
			last = last%10;
		}
	}
	printf ("%ld\n", last);
}

int main()
{
	long int n, m;
	while(scanf("%ld%ld", &n, &m) != EOF)
		last_digit(n, m);
	return 0;
}