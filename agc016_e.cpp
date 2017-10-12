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
const int N = 410, M = 1e5 + 10;
int f[N][N], a[M], b[M];
int n, m;
bool t[N];
bool work(int f[], int x) {
	f[x] = m + 1; 
	dep(i,m,1) {
		if (f[a[i]] && f[b[i]]) return false;
		else if (f[a[i]]) f[b[i]] = i;
		else if (f[b[i]]) f[a[i]] = i;
	}
	return true;
}
 
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d",a + i, b + i);
	rep(i,1,n) t[i] = work(f[i], i);
	int ans = 0;
	rep(i,1,n) rep(j,i + 1,n) if (t[i] && t[j]) {
		int tmp = 1;
		rep(k,1,n) if (f[i][k] && f[j][k] && f[i][k] != f[j][k]) tmp = 0;
		ans += tmp;
	}
	printf("%d\n",ans);
	return 0;
}