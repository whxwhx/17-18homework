#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 510;
int n, m;
char s[N][N], a[N][N], b[N][N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i] + 1);
	rep(i,1,n) rep(j,1,m) a[i][j] = b[i][j] = '.';
	rep(i,1,n) a[i][1] = b[i][m] = '#';
	rep(i,1,n) if (i & 1) {
		rep(j,1,m - 1) a[i][j] = '#';
	} else {
		rep(j,2,m - 1) b[i][j] = '#';
	}
	rep(i,1,n) rep(j,1,m) if (s[i][j] == '#') a[i][j] = b[i][j] = '#';
	rep(i,1,n) printf("%s\n",a[i] + 1);
	printf("\n");
	rep(i,1,n) printf("%s\n",b[i] + 1);
	return 0;
}