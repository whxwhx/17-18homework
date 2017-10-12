#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iostream>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define mp make_pair
typedef long long LL;
using namespace std;
const int N = 90, mod = 1e9 + 7;
typedef pair<LL, LL> pii;
LL f[N];
int cnt = 0;
vector<pii> g[N];
void dfs(int t, LL a, LL b) {
	if (a > 2LL * f[t] || b > LL(1e18)) return;
	if (f[t] <= a && a < f[t + 2] && f[t + 1] <= b && b < f[t + 2]) g[t].pb(mp(a, b));
	rep(i,1,4) dfs(t + 1, b, a + b * i);
}
 
LL read() {
	char c = getchar(); LL x = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}
 
 
int main() {
	f[0] = f[1] = 1; rep(i,2,87) f[i] = f[i - 1] + f[i - 2];
	dfs(0, 1, 1);
	int Q; scanf("%d",&Q);
	while (Q--) {
		LL a, b; a = read(), b = read();
		if (a > b) swap(a, b); int mx = 1;
		dep(i,86,1) if (f[i] <= a && f[i + 1] <= b) { mx = i; break; }
		if (mx == 1) printf("%d %d\n",mx, 1LL * a * b % mod);
		else {
			int len = g[mx].size(); int ans = 0;
			Rep(j,len) {
				LL x = g[mx][j].first, y = g[mx][j].second;
				if (x <= a && y <= b) ans++;
				if (y <= a && x <= b) ans++;
			}
			len = g[mx - 1].size();
			Rep(j,len) {
				LL x = g[mx - 1][j].first, y = g[mx - 1][j].second;
				if (y <= a && b >= f[mx + 2]) 
					ans = (ans + (b - x) / y - (f[mx + 2] - 1 - x) / y) % mod;
			}
			if (ans < 0) ans += mod;
			printf("%d %d\n",mx, ans);
		}
	}
	return 0;
}