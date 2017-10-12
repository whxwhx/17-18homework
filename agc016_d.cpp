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
const int N = 1e5 + 10;
int n, a[N], b[N], c[N], d[N], p[N], l;
map<int, int> val;
int f[N];
inline int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) f[a] = b;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a + i);
	rep(i,1,n) scanf("%d",b + i);
	a[n + 1] = 0; rep(i,1,n) a[n + 1] ^= a[i];
	b[n + 1] = 0; rep(i,1,n) b[n + 1] ^= b[i];
	n++;
	memcpy(c + 1, a + 1, n * sizeof(a[0]));
	memcpy(d + 1, b + 1, n * sizeof(b[0]));
	sort(c + 1, c + n + 1); sort(d + 1, d + n + 1);
	rep(i,1,n) if (c[i] != d[i]) { printf("-1\n"); return 0; }
	l = unique(c + 1, c + n + 1) - c - 1;
	rep(i,1,l) val[c[i]] = i;
	rep(i,1,n) a[i] = val[a[i]], b[i] = val[b[i]];
	static vector<int> pos[N];
	rep(i,1,n) pos[b[i]].pb(i);
	static bool vs[N];
	rep(i,1,n) if (a[i] == b[i]) p[i] = i, vs[i] = true;
	rep(i,1,n) if (!vs[i]) {
		while (vs[*pos[a[i]].rbegin()]) pos[a[i]].pop_back();
		p[i] = *pos[a[i]].rbegin();
		pos[a[i]].pop_back();
	}
	rep(i,1,n) f[i] = i; static bool vis[N];
 
	rep(i,1,n) if (!vis[i]) {
		vis[i] = true;
		for(int j = p[i]; j != i; j = p[j]) vis[j] = true, merge(j, i);
	}
	rep(i,1,n) pos[a[i]].pb(i);
	rep(i,1,n) if (pos[i].size()) {
		int len = pos[i].size(), t = 0;
		rep(j,0,len - 1) {
			int x = pos[i][j];
			if (p[x] != x || x == n) {
				if (!t) t = x; else merge(t, x);
			}
		}
	}
	static int cnt[N];
	rep(i,1,n) cnt[find(i)]++;
	int ans = 0;
	rep(i,1,n) if (f[i] == i) {
		if (i == find(n)) ans += cnt[i] - 1;
		else if (cnt[i] > 1) ans += cnt[i] + 1;
	}
	printf("%d\n",ans);
	return 0;
}