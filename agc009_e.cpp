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
 
const int N = 2010, mod = 1e9 + 7;
int f[N << 1][N];
 
int main() {
	int n, m, k; scanf("%d%d%d",&n,&m,&k);
	rep(j,0,n) f[0][j] = 1; int ans = 0;
	rep(i,1,n + m) rep(j,0,n) {
		int l = max(j - (k - 1), 0), r = j;
		f[i][j] = (f[i - 1][r] - (l > 0 ? f[i - 1][l - 1] : 0)) % mod;
		int rev = (k - 1) * i - j;
		if (rev <= m - 1 && j % (k - 1) == n % (k - 1) && rev % (k - 1) == (m - 1 + (k - 1)) % (k - 1))
			(ans += ((f[i][j] - f[i - 1][j]) % mod + (j ? f[i - 1][j - 1] : 0)) % mod) %= mod;
		if (j) f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
	}
	if (ans < 0) ans += mod;
	cout <<ans<<endl;
	return 0;
}