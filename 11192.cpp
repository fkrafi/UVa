#include<stdio.h>
#include<string.h>

char s[100], ans[100], ch;

int main(){
	int i, j, k, l, m, n, g, a;
	for(i=0; i<101; i++){
		scanf("%d%c", &n, &ch);
		if(n==0)break;
		gets(s);
		l = strlen(s);
		g = l/n;
		if(l%n==0){
			j=0;
			for(k=0; k<l; k++){
				for(m=k+g-1; m>=k; m--)ans[j++]=s[m];
				k += g-1;
			}
		}else{
			j=0;
			a = l-(l%g);
			for(k=0; k<a; k++){
				for(m=k+g; m>=k; m--)ans[j++]=s[m];
				k += g;
			}
			for(m=l-1; m>=k; m--)ans[j++]=s[m];
		}
		ans[j]='\0';
		puts(ans);

	}
	return 0;
}