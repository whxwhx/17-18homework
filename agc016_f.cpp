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
const int N = 20, M = N * N, mod = 1e9 + 7;
 
int d[N];
struct edge{ int to, pre; } e[M]; int u[N], l = 0;
void ins(int a, int b) { e[++l] = (edge){b, u[a]}, u[a] = l; d[a]++; }
#define v e[i].to
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
 
int n, m, level[N], ans = 0;
int Cnt[N][N], Pre[N][N], Suf[N][N];
void dfs(int x, int l, int t) {
	if (x == 2) {
		ans = (ans + 1LL * t * (1 << (d[1] + d[2]))) % mod;
		static int c1[N], c2[N];
		rep(i,0,l) c1[i] = c2[i] = 0;
		reg(i,1) if (v != 2) c1[level[v]]++;
		reg(i,2) c2[level[v]]++;
		int *pre = Pre[2], *suf = Suf[2];
		pre[0] = ((1 << c1[0]) - 1) * ((1 << c2[0]) - 1);
		rep(i,1,l) pre[i] = 1LL * pre[i - 1] * ((1 << c1[i]) - 1) * ((1 << c2[i]) - 1) % mod;
		suf[l + 1] = 1;
		dep(i,l,0) suf[i] = 1LL * suf[i + 1] * (1 << (c1[i] + c2[i])) % mod;
		rep(i,0,l) {
			int tmp = 1LL * (i ? pre[i - 1] : 1) * suf[i + 1] % mod;
			ans = (ans - 1LL * t * tmp) % mod;
		}
	} else {
		int *cnt = Cnt[x], *pre = Pre[x], *suf = Suf[x];
		rep(i,0,l) cnt[i] = 0;
		reg(i,x) cnt[level[v]]++;
		pre[0] = (1 << cnt[0]) - 1; 
		rep(i,1,l) pre[i] = 1LL * pre[i - 1] * ((1 << cnt[i]) - 1) % mod;
		suf[l + 1] = 1;
		dep(i,l,0) suf[i] = 1LL * suf[i + 1] * (1 << cnt[i]) % mod;
		rep(i,0,l) {
			level[x] = i;
			int tmp = 1LL * (i ? pre[i - 1] : 1) * suf[i + 1] % mod;
			if (tmp) dfs(x - 1, (i == l) ? l + 1 : l, 1LL * t * tmp % mod);
		}
	}
}
 
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		int a, b; scanf("%d%d",&a,&b);
		ins(a, b);
	}
	dfs(n, 0, 1);
	if (ans < 0) ans += mod;
	printf("%d\n",ans);
	return 0;
}