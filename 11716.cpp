#include<stdio.h>
#include<string.h>
#include<math.h>

char s[10000], str[100][100], ch;

int main(){
	int l, i, j, t, k, r, m;
	scanf("%d%c", &t, &ch);
	for(i=0; i<t; i++){
		gets(s);
		l = strlen(s);
		r = int(sqrt(l));
		if(l != r*r){
			printf("INVALID\n");
		}else{
			m=0;
			for(j=0; j<r; j++){
				for(k=0; k<r; k++){
					str[j][k] = s[m++];
				}
			}
			for(j=0; j<r; j++){
				for(k=0; k<r; k++){
					printf("%c", str[k][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}