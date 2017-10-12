#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a, _b = b; i <= _b; i++)
#define dep(i,a,b) for(int i = a, _b = b; i >= _b; i--)
#define Rep(i,a) for(int i = 0; i < a; i ++)
using namespace std;

const int M = 30 + 5, N = 1e6 + 10, mod = 998244353;

int n, m, a[M][M], inv[M], I;

bool check() {
	rep(i,1,m) rep(j,1,m) rep(k,1,m) 
		if (a[i][a[j][k]] != a[a[i][j]][k]) return false;
	I = 0;
	rep(i,1,m) {
		bool tmp = true;
		rep(j,1,m) if (a[i][j] != j || a[j][i] != j) tmp = false;
		if (tmp) I = i;
	}
	if (!I) return false;
	rep(i,1,m) {
		inv[i] = 0;
		rep(j,1,m) if (a[i][j] == I && a[j][i] == I) inv[i] = j;
		if (!inv[i]) return false;
	}
	return true;
}

set<int> sg, nsg;
typedef set<int>::iterator sit;

int conjugacy(int vis, int x) {
	int t = 0;
	rep(i,1,m) if (vis >> (i - 1) & 1) t |= 1 << (a[a[x][i]][inv[x]] - 1);
	return t;
}

bool check_normal(int vis) {
	rep(i,1,m) {
		int t = conjugacy(vis, i);
		if (t != vis) return false;
	}
	return true;
}

void dfs(int x, int vis) {
	if (x > m) { 
		sg.insert(vis);
		if (check_normal(vis)) nsg.insert(vis);
	} else if (vis >> (x - 1) & 1) dfs(x + 1, vis);
	else {
		dfs(x + 1, vis);
		static int q[N]; int l = 0, r = 1; q[l] = x;
		vis |= 1 << (x - 1);
		while (l < r) {
			int u = q[l++];
			rep(i,1,m) if (vis >> (i - 1) & 1) {
				int v = a[u][i];
				if (!(vis >> (v - 1) & 1)) {
					if (v < x) return;
					else vis |= 1 << (v - 1), q[r++] = v;
				}
			}
			rep(i,1,m) if (vis >> (i - 1) & 1) {
				int v = a[i][u];
				if (!(vis >> (v - 1) & 1)) {
					if (v < x) return;
					else vis |= 1 << (v - 1), q[r++] = v;
				}
			}
		}
		dfs(x + 1, vis);
	}
}

int C[1010][1010], fac[1010];

void work() {
	sg.clear(); nsg.clear();
	scanf("%d%d",&n,&m);
	rep(i,1,m) rep(j,1,m) scanf("%d",&a[i][j]);
	if (!check()) printf("0\n");
	else {
		dfs(1,1 << (I - 1)); int l = 0; static int s[N], ans[N];
		for(sit it = nsg.begin(); it != nsg.end(); it++) {
			int i = *it;
			static int cnt[M]; memset(cnt, 0, sizeof(cnt));
			for(sit t = sg.begin(); t != sg.end(); t++) {
				int j = *t;
				if ((i & j) == i) {
					int s = 0; rep(k,1,m) if (j >> (k - 1) & 1) s++;
					cnt[m / s]++;
				}
			}

			static int f[1010]; f[0] = 1;
			rep(i,1,n) {
				f[i] = 0;
				rep(j,1,min(i, m)) 
					f[i] = (f[i] + f[i - j] * 1LL * C[i - 1][j - 1] % mod * cnt[j] % mod * fac[j - 1]) % mod;
			}

			l++, s[l] = i, ans[l] = f[n];
		}
		
		dep(i,l,1) rep(j,i + 1,l) if ((s[i] & s[j]) == s[i]) (ans[i] -= ans[j]) %= mod;
		if (ans[1] < 0) ans[1] += mod;
		printf("%d\n",ans[1]);
	}
}

int main() {
	fac[0] = 1; rep(i,1,1001) fac[i] = 1LL * i * fac[i - 1] % mod;
	rep(i,0,1001) {
		C[i][0] = C[i][i] = 1;
		rep(j,1,i - 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	int T; scanf("%d",&T);
	while (T--) work();
	return 0;
}