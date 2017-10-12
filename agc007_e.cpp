#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
const int N = 200010;
typedef long long LL;
int n, fa[N], w[N], ch[N][2], d[N];
typedef pair<LL, LL> node;
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define x first
#define y second
vector<node> f[N], a, b;
void merge(vector<node> &c, vector<node> &a, vector<node> &b) {
	int l = a.size(), i = 0, j = 0;
	while (i < l || j < l) {
		if (i == l) c.pb(b[j++]);
		else if (j == l) c.pb(a[i++]);
		else if (a[i] <= b[j]) c.pb(a[i++]);
		else c.pb(b[j++]);
	}
}
bool check(LL mx) {
	rep(i,1,n) { vector<node>().swap(f[i]); f[i].clear(); }
	dep(i,n,1) if (!d[i]) f[i].pb(mp(LL(w[i]), LL(w[i])));
	else {
		if (f[ch[i][0]].size() > f[ch[i][1]].size()) swap(ch[i][0], ch[i][1]);
		int l = f[ch[i][0]].size(), r = f[ch[i][1]].size(), j = 0, lc = ch[i][0], rc = ch[i][1];
		if (!l || !r) return false;
		a.clear(), b.clear();
		Rep(k,l) {
			while (j + 1 < r && f[lc][k].y + f[rc][j + 1].x <= mx) j++;
			if (f[lc][k].y + f[rc][j].x <= mx) a.pb(mp(f[lc][k].x + w[i], f[rc][j].y + w[i]));
		}
		int len = a.size(); dep(k,len - 1, 0) b.pb(mp(a[k].y, a[k].x));
		merge(f[i], a, b);
        len = f[i].size(); rep(k,1,len - 1) f[i][k].y = min(f[i][k].y, f[i][k - 1].y);
	}
	return f[1].size() > 0;
}
int main() {
	scanf("%d",&n);
	rep(i,2,n) scanf("%d%d",&fa[i],&w[i]);
	rep(i,2,n) ch[fa[i]][d[fa[i]]++] = i;
	LL l = -1, r = 1LL * N * N;
	while (l + 1 < r) {
		LL mid = (l + r) >> 1;
		if (check(mid)) r = mid; else l = mid;
	}
	printf("%lld\n",r);
	return 0;
}