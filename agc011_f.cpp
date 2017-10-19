#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long LL;
const LL inf = 1LL << 60;
const int N = 1e6 + 10;
int n, k, a[N], b[N], nd[N], t = 0;
map<int, int> val;

void init() {
	int delta = 0;
	t = 2; nd[1] = 1, nd[2] = k;
	rep(i,1,n) {
		if (b[i] == 1) {
			int l = 1, r = 2 * a[i] - 1;
			l = (l - delta + k) % k, r = (r - delta + k) % k;
			int r1 = (r + 1) % k, l1 = (l - 1 + k) % k;
			if (l == 0) l = k; if (r == 0) r = k;
			if (r1 == 0) r1 = k; if (l1 == 0) l1 = k;
			nd[++t] = l, nd[++t] = r, nd[++t] = r1, nd[++t] = l1, nd[++t] = k - delta;
		}
		delta = ((delta - 2LL * a[i]) % k + k) % k;
	}
	sort(nd + 1, nd + t + 1); t = unique(nd + 1, nd + t + 1) - nd - 1;
	rep(i,1,t) val[nd[i]] = i;
}

LL ans = 0;
namespace seg{
	int a, b; LL s[N << 2], c; bool tag[N << 2];
	#define lc (x << 1)
	#define rc (lc | 1)
	#define mid ((l + r) >> 1)
	#define lcq lc, l, mid
	#define rcq rc, mid + 1, r
	void build(int x, int l, int r) {
		s[x] = nd[l]; tag[x] = false;
		if (l < r) build(lcq), build(rcq);
	}

	inline void push(int x, int l, int r) {
		if (tag[x]) {
			s[x] = inf; if (l < r) tag[lc] = tag[rc] = true;
			tag[x] = false;
		}
	}

	LL qry(int x, int l, int r) {
		push(x, l, r);
		if (a <= l && r <= b) return s[x];
		else {
			LL ans = inf;
			if (a <= mid) ans = min(ans, qry(lcq));
			if (b >  mid) ans = min(ans, qry(rcq));
			return ans; 
		}
	}

	void upd(int x) { s[x] = min(s[lc], s[rc]); }

	void clear(int x, int l, int r) {
		if (a <= l && r <= b) tag[x] = true, push(x, l, r);
		else {
			push(x, l, r);
			if (a <= mid) clear(lcq); else push(lcq);
			if (b >  mid) clear(rcq); else push(rcq);
			upd(x);
		}
	}

	void upd(int x, int l, int r) {
		push(x, l, r);
		if (l == r) s[x] = min(s[x], c);
		else (a <= mid ? upd(lcq), push(rcq) : upd(rcq), push(lcq)), upd(x);
	}

	void calc(int x, int l, int r) {
		push(x, l, r);
		if (l == r) ans = min(ans, s[x] - nd[l]);
		else calc(lcq), calc(rcq);
	}
}

int delta = 0;
LL ask(int l, int r) {
	int d = val[k - delta]; LL ans = inf;
	if (l <= d && d < r) {
		seg::a = l, seg::b = d; ans = seg::qry(1, 1, t) + delta;
		seg::a = d + 1, seg::b = r; ans = min(ans, seg::qry(1, 1, t) + delta - k);
	} else {
		seg::a = l, seg::b = r; ans = seg::qry(1, 1, t) + delta;
		if (d < l) ans -= k;
	}

	seg::a = l, seg::b = r, seg::clear(1, 1, t);
	return ans;
}

void work() {
	seg::build(1, 1, t);
	rep(i,1,n) {
		if (b[i] == 1) {
			int l = 1, r = 2 * a[i] - 1;
			l = (l - delta + k) % k, r = (r - delta + k) % k;
			if (l == 0) l = k; if (r == 0) r = k;
			LL mn = inf;
			if (l <= r) mn = ask(val[l], val[r]);
			else mn = min(ask(val[l], t), ask(1, val[r]));

			seg::a = val[k - delta], seg::c = mn + k - delta;
			seg::upd(1, 1, t);
		}
		delta = ((delta - 2LL * a[i]) % k + k) % k;
	}
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		scanf("%d%d",a + i, b + i);
		if (a[i] * 2 > k && b[i] == 1) { printf("-1\n"); return 0; }
	}
	init();
	work();
	LL sum = 0; rep(i,1,n) sum += a[i];
	ans = inf;
	seg::calc(1, 1, t);
	printf("%lld\n",ans + sum * 2);
	return 0;
}