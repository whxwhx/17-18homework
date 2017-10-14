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
const int N = 310;
int n, m, a[N][N];
bool vis[N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
	int ans = n; memset(vis, true, sizeof(vis));
	rep(i,1,m) {
		int mx = 0, mxa = 0;
		static int cnt[N]; memset(cnt, 0, sizeof(cnt));
		rep(j,1,n) rep(k,1,m) if (vis[a[j][k]]) { cnt[a[j][k]]++; break; }
		rep(j,1,m) if (cnt[j] > mx) mx = cnt[j], mxa = j;
		ans = min(ans, mx);
		vis[mxa] = false;
	}
	printf("%d\n",ans);
	return 0;
}
