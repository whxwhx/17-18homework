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
typedef pair<LL, LL> pii;
#define x first
#define y second
const int N = 2e5 + 10, mod = 1e9 + 7;
map<LL, int> val;
int n;
pii a[N], range[N];
LL b[N];
int s[N];
 
void add(int x, int d) { for(;x < N; x += (-x) & x) (s[x] += d) %= mod; }
int sum(int x) { int ans = 0; for(;x; x -= (-x) & x) (ans += s[x]) %= mod; return ans; }
 
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld%lld",&a[i].x,&a[i].y), b[i] = a[i].y;
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	rep(i,1,n) val[b[i]] = i; rep(i,1,n) a[i].y = val[a[i].y];
	LL mx = 0;
	rep(i,1,n) mx = max(mx, a[i].y), range[i].y = mx;
	LL mn = n;
	dep(i,n,1) mn = min(mn, a[i].y), range[i].x = mn;
	sort(range + 1, range + n + 1);
	add(1, 1); int ans = 0;
	rep(i,1,n) {
		int F = (sum(N - 1) - sum(range[i].x - 1)) % mod;
		add(range[i].y + 1, F);
		if (range[i].y == n) (ans += F) %= mod;
	}
	if (ans < 0) ans += mod;
	printf("%d\n",ans);
	return 0;
}