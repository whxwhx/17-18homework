#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define x first
#define y second
#define pb(a) push_back(a)
const int N = 2e5 + 10;
int n; char s[N];

struct edge{ int to, pre; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int f[N], g[N], high[N], low[N];
void dfs(int x, int fa) {
	if (s[x] == '1') low[x] = 0; else low[x] = n;
	reg(i,x) if (v != fa) {
		dfs(v, x), 
		f[x] = max(f[x], f[v] + 1), 
		low[x] = min(low[x], max(f[v] + 1, low[v] + 1));
	}
}

int a[N];
void dfs2(int x, int fa) {
	int mx = g[x], mxa = 0, mx1 = 0;
	reg(i,x) if (v != fa) {
		if (f[v] + 1 >= mx) mx1 = mx, mx = f[v] + 1, mxa = v;
		else if (f[v] + 1 > mx1) mx1 = f[v] + 1;
	}
	reg(i,x) if (v != fa) {
		if (v == mxa) g[v] = mx1 + 1, low[v] = min(low[v], max(low[x] + 1, mx1 + 1));
		else g[v] = mx + 1, low[v] = min(low[v], max(low[x] + 1, mx + 1));
	}
	high[x] = max(f[x], g[x]) - 1;
	high[x] = min(high[x], mx1 + 1);

	reg(i,x) if (v != fa) dfs2(v, x);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n - 1) {
		int a, b; scanf("%d%d",&a,&b);
		ins(a, b), ins(b, a);
	}
	scanf("%s",s + 1);
	dfs(1,0);
	dfs2(1,0);
	LL ans = 1;
	rep(i,1,n) if (low[i] <= high[i]) ans += high[i] - low[i] + 1;
	printf("%lld\n",ans);
	return 0;
}