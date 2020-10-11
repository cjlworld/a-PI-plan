#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//Mystery_Sky
//
#define M 5000
int f[M][M];
int n, m, ans;
int c[M][M];

void print(int i, int j)
{
	if(!i) return;
	for(int k = 0; k <= j; k++) {
		if(ans == f[i-1][k] + c[i][j-k]) {
			ans = f[i-1][k];
			print(i-1, k);
			printf("%d %d\n", i, j-k);
			break;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) scanf("%d", &c[i][j]);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) {
			int maxx = 0;
			for(int k = 0; k <= j; k++) {
				maxx = max(f[i-1][k] + c[i][j-k], maxx);
			}
			f[i][j] = maxx;
		}
	printf("%d\n", f[n][m]);
	ans = f[n][m];
	print(n, m);
	return 0;
}
