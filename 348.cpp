#include<stdio.h>
#define SZ 25
#define INF 1<<30

int p[SZ];
int m[SZ][SZ], s[SZ][SZ];

void print_opt_parens(int i, int j){
    if(i==j)
		printf("A%d", i);
    else{
        printf("(");
		print_opt_parens(i, s[i][j]);
		printf(" x ");
		print_opt_parens(s[i][j]+1, j);
		printf(")");
	}
}

void matrix_chain_order(int length){
    int n = length-1;
    int i, j, k, l, q;
    for(i=0; i<=n; i++)
		m[i][i]=0;
    for(l=2; l<=n; l++){
        for(i=1; i<=n-l+1; i++){
            j = i+l-1;
            m[i][j] = INF;
            for(k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }        
        }
    }
    print_opt_parens(1, n);
    return;
}

int main(){
	int i, j, n, t[25], cs=1;
	while( scanf("%d", &n) && n ){
		for(i=0; i<n; i++){
			scanf("%d%d", &t[2*i], &t[2*i+1]);
		}
		j = 0;
		p[j++] = t[0];
		for(i=1; i<2*n; i+=2){
			p[j++] = t[i];
		}
		printf("Case %d: ", cs++);
		matrix_chain_order(j);
		printf("\n");
	}
	return 0;
}