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
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, f[N];
int main() {
	scanf("%d",&n);
	f[0] = f[1] = f[2] = 1; int s = 3;
	rep(i,3,n) f[i] = (s - f[i - 2]) % mod, s = (s + f[i]) % mod;
	int ans = 0;
	rep(i,1,n - 1) ans = (
		ans + 
		1LL * f[i - 1] * (n - 1) % mod * (n - 1) % mod + 
		1LL * f[i - 1] * i % mod
	) % mod;
	ans = (ans + 1LL * f[n - 1] * (n - 1) + f[n]) % mod;
	if (ans < 0) ans += mod;
	cout <<ans<<endl;
	return 0;
}