#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
#define Rep(i,a) for(int i = 0; i < a; i++)
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10;

struct node{ int x, w, id; } b[N];
inline bool operator < (const node &a, const node &b) {
	return (a.x < b.x) || (a.x == b.x && a.w < b.w) || (a.x == b.x && a.w == b.w && a.id < b.id);
}
int a[N];
int main() {
	int n, l, t; scanf("%d%d%d",&n,&l,&t);
	int x0, w0, ans = 1;
	rep(i,1,n) {
		scanf("%d",a + i); 
		int w; scanf("%d",&w);
		if (w == 1) b[i].x = ((a[i] + t) % l + l) % l;
		else b[i].x = ((a[i] - t) % l + l) % l;

		b[i].w = -w; b[i].id = i;

		if (i == 1) x0 = a[i], w0 = w;
		else if (w != w0) {
			if (w0 == 1) {
				int dis = (a[i] - x0 + l) % l;
				if (t * 2 >= dis) ans = (ans + (t * 2 - dis) / l + 1) % n;
			} else {
				int dis = (x0 - a[i] + l) % l;
				if (t * 2 >= dis) ans = (ans - (t * 2 - dis) / l - 1 + n) % n;
			}
		}
	}
	sort(b + 1, b + n + 1);
	int delta = 0;
	rep(i,1,n) if (b[i].id == 1) {
		delta = (i - ans + n) % n;
		break;
	}
	rotate(b + 1, b + 1 + delta, b + n + 1);
	rep(i,1,n) printf("%d\n",b[i].x);
	return 0;
}
