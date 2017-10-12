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
const int N = 10010, B = N * 16, M = B + N * 2;
int n, x[N], y[N];
 
struct edge{ int to, pre; }e[(N * 2 * 4 + N * 2 * 16 * 2) * 2 * 2]; int u[M], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
void add(int a, int b) { ins(a, b), ins(b^1, a^1); }
 
pair<int, int> nd[N * 2];
#define mid ((l + r) >> 1)
#define lc (x << 1)
#define rc (lc | 1)
#define lcq lc, l, mid
#define rcq rc, mid + 1, r
void build(int x, int l, int r) {
	if (l == r) 
		add(x << 1, nd[l].second ^ 1); 
	else 
		build(lcq), build(rcq), 
		add(x << 1, lc << 1), add(x << 1, rc << 1);
}
 
int a, b, c;
 
void modi(int x, int l, int r) {
	if (a <= l && r <= b) add(c, x << 1);
	else {
		if (a <= mid) modi(lcq); 
		if (b >  mid) modi(rcq);
	}
}
 
int pre[M], low[M], dfn = 0; 
int st[M], top = 0, cnt = 0, scc[M];
void dfs(int x) {
	pre[x] = low[x] = ++dfn; st[top++] = x;
	reg(i,x) if (!pre[v]) dfs(v), low[x] = min(low[x], low[v]);
	else if (!scc[v]) low[x] = min(low[x], pre[v]);
	if (pre[x] == low[x]) {
		cnt++; st[top] = 0;
		while (st[top] != x) top--, scc[st[top]] = cnt;
	}
}
 
void tarjan() {
	memset(pre, 0, sizeof(pre)), memset(scc,0,sizeof(scc));dfn = 0;
	rep(i,1,n * 2) if (!pre[nd[i].second]) dfs(nd[i].second);
}
 
bool check(int m) {
	memset(u, 0, sizeof(u)); l = 0;
	rep(i,1,n) 
		nd[i*2-1] = mp(x[i], B + (i << 1)), 
		nd[i*2] = mp(y[i],B + ((i << 1) | 1));
	sort(nd + 1, nd + 2 * n + 1);
	build(1, 1, n * 2);
	rep(i,1,n * 2) {
		int t = lower_bound(nd + 1, nd + n * 2 + 1, mp(nd[i].first - m + 1, 0)) - nd;
		a = t, b = i - 1, c = nd[i].second; if (a <= b) modi(1, 1, n * 2);
		t = lower_bound(nd + 1, nd + n * 2 + 1, mp(nd[i].first + m - 1, int(1e9))) - nd;
		a = i + 1, b = t - 1, c = nd[i].second; if (a <= b) modi(1, 1, n * 2);
	}
	tarjan();
	rep(i,1,2 * n) if (scc[nd[i].second] == scc[nd[i].second ^ 1]) return false;
	return true;
}
 
int main() {
	scanf("%d",&n); rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
	int l = 0, r = 1e9 + 1;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (check(m)) l = m; else r = m;
	}
	printf("%d\n",l);
	return 0;
}