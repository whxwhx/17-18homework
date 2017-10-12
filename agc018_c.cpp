#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const int N = 1e5 + 10;
const LL inf = (1LL << 59);
int x, y, z;
LL ans = 0, ans1[N], ans2[N], mx = 0;
pii t[N];
#define mp(a,b) make_pair(a,b)
priority_queue<LL> q;
int main() {
	scanf("%d%d%d",&x,&y,&z); int n = x + y + z;
	rep(i,1,n) {
		LL a, b, c; scanf("%lld%lld%lld",&a,&b,&c);
		ans += c, a -= c, b -= c;
		t[i] = mp(a - b, b);
	}
	sort(t + 1, t + n + 1);
	LL s = 0; ans1[0] = ans2[0] = ans1[n + 1] = ans2[n + 1] = -inf;
	dep(i,n,1) {
		LL w = t[i].first + t[i].second; 
		q.push(-w); s += w; if (q.size() > x) s += q.top(), q.pop();
		ans1[i] = q.size() == x ? s : -inf;
	}
	s = 0; while (!q.empty()) q.pop();
	rep(i,1,n) {
		LL w = t[i].second;
		q.push(-w); s += w; if (q.size() > y) s += q.top(), q.pop();
		ans2[i] = q.size() == y ? s : -inf;
	}
	rep(i,0,n) mx = max(mx, ans + ans1[i + 1] + ans2[i]);
	printf("%lld\n",mx);
	return 0;
}