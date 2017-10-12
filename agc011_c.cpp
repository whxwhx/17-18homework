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
const int N = 1e5 + 10;
int n, m, f[N], r[N], c0, c1, c2, sz[N], szsum = 0;
bool mark[N];
void find(int x) {
	if (f[x] == x) return;
	else {
		find(f[x]);
		r[x] ^= r[f[x]];
		f[x] = f[f[x]];
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) f[i] = i, r[i] = 0, sz[i] = 1;
	rep(i,1,m) {
		int a, b; scanf("%d%d",&a,&b);
		find(a), find(b);
		int fa = f[a], fb = f[b];
		if (fa != fb) f[fa] = fb, r[fa] = r[a] ^ r[b] ^ 1, sz[fb] += sz[fa];
		else if (r[a] ^ r[b] ^ 1) mark[a] = true;
	}
	rep(i,1,n) find(i), mark[f[i]] |= mark[i];
	rep(i,1,n) if (f[i] == i) {
		if (sz[i] == 1) c0++;
		else if (!mark[i]) c2++, szsum += sz[i];
		else c1++, szsum += sz[i];
	}
	LL ans = 1LL * c0 * c0 + 2LL * c0 * szsum + 1LL * (c1 + c2) * (c1 + c2) + 1LL * c2 * c2;
	cout <<ans<<endl; 
	return 0;
}