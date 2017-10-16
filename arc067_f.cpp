#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i ++)
#define max(a,b) ((a) > (b) ? (a) : (b))
typedef long long LL;
using namespace std;
const int N = 5e3 + 10, M = 210;
int n, m, b[N][M]; 
LL a[N];
inline void read(int &x) {
	char c = getchar(); x = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
}

LL ans[N];

int s[14][N][M], bin[(1 << 15) + 10];
void init() {
	rep(i,1,n) rep(j,1,m) s[0][i][j] = b[i][j];
	rep(k,1,12) {
		rep(i,1,n) if (i + (1 << k) <= n) rep(j,1,m) 
			s[k][i][j] = max(s[k - 1][i][j], s[k - 1][i + (1 << (k - 1))][j]);
	}
	rep(i,0,12) rep(j,(1<<i),(1<<(i+1))) bin[j] = i;
}

inline void prepare(int mx[], int l, int r) {
	if (l > r) return;
	int len = r - l + 1; int k = bin[len];
	rep(i,1,m) mx[i] = max(s[k][l][i], s[k][r - (1 << k) + 1][i]);
}

int calc(int x, int l, int r) {
	l = max(l, x);
	static int mx[M]; memset(mx, 0, sizeof(mx));
	ans[x] = 0; int mxa = 0;
	prepare(mx, x, l - 1);
	rep(i,l,r) {
		LL s = 0;
		rep(j,1,m) mx[j] = max(mx[j], b[i][j]), s += mx[j];
		s -= a[i] - a[x];
		if (s > ans[x]) ans[x] = s, mxa = i;
	}
	return mxa;
}

void solve(int l, int r, int a, int b) {
	int mid = (l + r) >> 1;
	int t = calc(mid, a, b);
	if (l < mid) solve(l, mid - 1, a, t);
	if (mid < r) solve(mid + 1, r, t, b);
}

int main() {
	read(n), read(m);
	rep(i,2,n) scanf("%lld",a + i), a[i] += a[i - 1];
	rep(i,1,n) rep(j,1,m) read(b[i][j]);
	init();
	solve(1, n, 1, n);
	LL mx = 0; rep(i,1,n) mx = max(mx, ans[i]);
	printf("%lld\n",mx);
	return 0;
}