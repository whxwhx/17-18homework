#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 2010;
int n, m, q;
char s[N][N];
int a[N][N], b[N][N], c[N][N];

void sumup(int a[][N]) {
	rep(i,1,n) rep(j,1,m) a[i][j] += a[i][j - 1];
	rep(i,1,n) rep(j,1,m) a[i][j] += a[i - 1][j];
}

int sum(int a[][N], int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n) scanf("%s", s[i] + 1);
	rep(i,1,n) rep(j,1,m) a[i][j] = (s[i][j] == '1');
	sumup(a);
	rep(i,1,n) rep(j,1,m) {
		if (i - 1 && s[i - 1][j] == s[i][j] && s[i][j] == '1') 
			b[i][j]++;
		if (j - 1 && s[i][j - 1] == s[i][j] && s[i][j] == '1') 
			c[i][j]++;
	}
	sumup(b), sumup(c);
	rep(i,1,q) {
		int x1, y1, x2, y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans = sum(a, x1, y1, x2, y2);
		ans -= sum(b, x1 + 1, y1, x2, y2);
		ans -= sum(c, x1, y1 + 1, x2, y2);
		printf("%d\n",ans);
	}
	return 0;
}
