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
typedef set<int ,int>::iterator sit;
const int N = 300010;
 
int n, a[N]; 
 
LL wi[N], wo[N], f[N], g[N], s[N];
 
typedef pair<LL, LL> point;
#define x first
#define y second
point operator - (const point &a, const point &b) { return mp(a.x - b.x, a.y - b.y); }
LL operator * (const point a, const point b) { return a.x * b.y - a.y * b.x; }
 
point st[N]; int top;
 
void qry(int k) { while (top >= 2 && st[top].y - k * st[top].x < st[top - 1].y - k * st[top - 1].x) top--; }
 
void dp() {
	st[ top = 1 ] = mp(0LL, 0LL);
	rep(i,1,n) {
		//calc
		int k = 2 * i; qry(k);
		f[i] = max(f[i - 1], st[top].y - k * st[top].x - s[i] + 1LL * i * i + i);
		//add
		point x = mp((LL)i, f[i] + 1LL * i * i + s[i] - i);
		while (top >= 2 && (x - st[top]) * (st[top] - st[top - 1]) <= 0) top--;
		st[++top] = x;	
	}
}
 
void init() {
	rep(i,1,n / 2) swap(a[i], a[n - i + 1]);
	rep(i,1,n) s[i] = s[i - 1] + a[i];
	dp(); rep(i,1,n) g[i] = f[i];
	rep(i,1,n / 2) swap(a[i], a[n - i + 1]), swap(g[i], g[n - i + 1]);
	rep(i,1,n) s[i] = s[i - 1] + a[i];
	dp(); rep(i,1,n) wo[i] = f[i - 1] + g[i + 1];
}
 
LL t[N];
void build(int l, int r) {
	top = 0;
	rep(i,l,r) {
		point x = mp((LL)i, t[i]);
		while (top >= 2 && (x - st[top]) * (st[top] - st[top - 1]) <= 0) top--;
		st[++top] = x;
	}
}
 
LL tmp[N];
void work(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	//left part
	rep(i,l,mid) t[i] = f[i] + 1LL * i * i + s[i] + 2 * i - i;
	build(l, mid);
	rep(i,mid + 1,r) {
		int k = 2 * i; qry(k);
		tmp[i] = st[top].y - k * st[top].x - s[i - 1] + 1LL * (i - 1) * (i - 1) + g[i] + (i - 1);
	}
	dep(i,r - 1,mid + 1) tmp[i] = max(tmp[i], tmp[i + 1]);
	rep(i,mid + 1,r - 1) wi[i] = max(wi[i], tmp[i + 1]);
	//right part
	rep(i,mid + 1,r) t[i] = g[i] + 1LL * (i - 1) * (i - 1) - s[i - 1] + (i - 1);
	build(mid + 1, r);
	rep(i,l,mid) {
		int k = 2 * i; qry(k);
		tmp[i] = st[top].y - k * st[top].x + s[i] + 1LL * i * i + f[i] + 2 * i - i;
	}
	rep(i,l + 1,mid) tmp[i] = max(tmp[i], tmp[i - 1]);
	rep(i,l + 1,mid) wi[i] = max(wi[i], tmp[i - 1]);
	work(l,mid), work(mid + 1, r);
}
 
const LL inf = 1LL << 60;
 
int main() {
	scanf("%d",&n);	rep(i,1,n) wi[i] = -inf;
	rep(i,1,n) scanf("%d",&a[i]), a[i] = a[i] * 2, s[i] = s[i - 1] + a[i];
	init(); work(0, n + 1);
	int m; scanf("%d",&m);
	rep(i,1,m) {
		int p, x; scanf("%d%d",&p,&x);
		printf("%lld\n",max(wo[p], wi[p] + a[p] - x * 2) / 2);
	}
	return 0;
}