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
const int N = 1e5 + 10;

struct edge{ int to, pre; } e[N << 1]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

int T, n, m;
int pre[N], dfn = 0, dep[N], fa[N], cx, cy;
void dfs(int x, int f) {
	pre[x] = ++dfn, dep[x] = dep[f] + 1, fa[x] = f;
	reg(i,x) if (v != f) {
		if (!pre[v]) dfs(v, x);
		else if (pre[v] > pre[x]) cx = x, cy = v; 
	}
}

LL ans;

int cal(int x, int f, int f1, int f2) {
	int w = 0;
	if (dep[x] & 1) w = 1; else w = -1;
	reg(i,x) if (v != f1 && v != f2 && v != f) w += cal(v, x, f1, f2);
	ans += ab(w);
	return w;
}

void work() {
	memset(u, 0, sizeof(u)); l = 0;
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		int a, b; scanf("%d%d",&a,&b);
		ins(a, b), ins(b, a);
	}
	if (n & 1) { printf("-1\n"); return; }
	memset(pre, 0, sizeof(pre)); cx = cy = 0;
	dfs(1,0);
	if (!cx && !cy) cx = fa[n], cy = n;
	int ca = 0, cb = 0;
	rep(i,1,n) if (dep[i] & 1) ca++; else cb++;
	if ((dep[cx] ^ dep[cy]) & 1) { if (ca != cb) { printf("-1\n"); return; } }
	static int c[N], cl; cl = 0;
	while (cy != cx) c[++cl] = cy, cy = fa[cy];
	if (c[cl] != cx) c[++cl] = cx;
	static int a[N], s[N]; ans = 0;
	rep(i,1,cl) 
		a[i] = cal(c[i], 0, c[(i == 1 ? cl : i - 1)], c[i % cl + 1]),
		ans -= ab(a[i]);
	s[0] = 0; rep(i,1,cl) s[i] = s[i - 1] + a[i];
	int x;
	if (!(cl & 1)) {
		nth_element(s + 1, s + ((cl + 1) >> 1), s + cl + 1);
		x = s[(cl + 1) >> 1];
	} else x = (ca - cb) / 2;
	rep(i,1,cl) ans = ans + ab(s[i] - x);
	printf("%lld\n",ans);
}

int main() {
	work();
	return 0;
}
