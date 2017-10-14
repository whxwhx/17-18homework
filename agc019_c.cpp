 #include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
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
const int N = 2e5 + 10, M = 1e8;
pii a[N];
int s[N];
const double pi = acos(-1.0);


int main() {
	static int n, x1, y1, x2, y2, f[N];
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d", &a[i].x, &a[i].y);
	
	if (x1 > x2) swap(x1, x2), swap(y1, y2);
	if (y1 > y2) {
		y1 = M - y1, y2 = M - y2;
		rep(i,1,n) a[i].y = M - a[i].y;
	}
	sort(a + 1, a + n + 1);

	int ans = 0;
	s[0] = 0; rep(i,1,n) s[i] = M + 1; 
	rep(i,1,n) if (a[i].x >= x1 && a[i].y >= y1) {
		int l = 0, r = i;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (s[mid] <= a[i].y) l = mid; else r = mid;
		}
		f[i] = max(f[i], l + 1);
		s[l + 1] = a[i].y;
		if (a[i].x <= x2 && a[i].y <= y2) ans = max(ans, f[i]);
	}
	if (ans == min(x2 - x1, y2 - y1) + 1) 
		printf("%.20lf\n", (x2 - x1 + y2 - y1) * 100LL - 20 * (ans - 1) * (1 - pi / 4) + 20 * (pi / 2 - 1));
	else
		printf("%.20lf\n",(x2 - x1 + y2 - y1) * 100LL - 20 * ans * (1 - pi / 4));
	return 0;
}
