#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 300010, inf = 1000000000;
int d[N], dl = 0;
namespace seg{
	#define mid ((l + r) >> 1)
	#define lc (x << 1)
	#define rc (lc | 1)
	#define lcq lc, l, mid
	#define rcq rc, mid + 1, r
	int mx[N << 2], t[N << 2], a, b, c;
	void build(int x, int l, int r) {
		t[x] = 0;
		if (l == r) mx[x] = -d[l] * 2; else build(lcq), build(rcq), mx[x] = max(mx[lc], mx[rc]);
	}
	void push(int x, int l, int r) {
		mx[x] += t[x]; if (l < r) t[lc] += t[x], t[rc] += t[x]; t[x] = 0;
	}
	void add(int x, int l, int r) {
		if (a <= l && r <= b) t[x] += c, push(x, l, r); else 
		push(x, l, r), (a <= mid ? add(lcq) : push(lcq)), (b > mid ? add(rcq) : push(rcq)),
		mx[x] = max(mx[lc], mx[rc]);
	}
	int qry(int x, int l, int r) {
		push(x, l, r);
		if (a <= l && r <= b) return mx[x];
		else return max((a <= mid ? qry(lcq) : -inf), (b > mid ? qry(rcq) : -inf));
	}
}
 
int W, H, n, ans = 0;
int x[N], y[N];
 
typedef pair<int, int> node;
#define mp(a,b) make_pair(a,b)
node a[N], b[N]; int al = 0, bl = 0;
 
struct stack{
	int st[N], a[N], top;
	void clear(int h) {
		st[top = 0] = 1, a[0] = h;
		seg::a = 1, seg::b = dl, seg::c = h; seg::add(1, 1, dl);
	}
	void add(int x, int h) {
		while (top && a[top] >= h) {
			seg::a = st[top - 1], seg::b = st[top] - 1, seg::c = a[0] - a[top], seg::add(1, 1, dl);
			top--;
		}
		seg::a = st[top], seg::b = x - 1, seg::c = h - a[0], seg::add(1, 1, dl);
		top++, a[top] = h, st[top] = x;
	}
}A, B;
 
void work(int m) {
	d[1] = 0; al = bl = dl = 0;
	rep(i,1,n) {
		if (x[i] <= m) a[++al] = mp(y[i], (m - x[i]) * 2 + 1);
		if (x[i] >  m) b[++bl] = mp(y[i], (x[i] - m) * 2 - 1);
		d[i + 1] = y[i];
	}
	d[n + 2] = H;
	sort(d + 1, d + n + 2 + 1); dl = unique(d + 1, d + n + 2 + 1) - d - 1;
	sort(a + 1, a + al + 1); sort(b + 1, b + bl + 1);
	seg::build(1, 1, dl); A.clear(m * 2 + 1), B.clear((W - m) * 2 - 1);
	int i = 1, j = 1;
	rep(t,1,dl) {
		int y = d[t]; 
		//calc
		seg::a = 1, seg::b = t - 1;
		if (seg::a <= seg::b) { int mx = seg::qry(1, 1, dl); ans = max(ans, y * 2 + mx); }
		//add
		if (i <= al && a[i].first == y) { if (y > 0) A.add(t, a[i].second); i++; }
		if (j <= bl && b[j].first == y) { if (y > 0) B.add(t, b[j].second); j++; }
 
		seg::a = seg::b = 1;
	}
}
 
int main() {
	scanf("%d%d%d",&W,&H,&n);
	rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
	work(W >> 1);
	swap(W, H); rep(i,1,n) swap(x[i], y[i]);
	work(W >> 1);
	printf("%d\n",ans);
	return 0;
}