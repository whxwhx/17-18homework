#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 3010, mod = 1000000000 + 7;
char s[N], t[N];
int f[N][N];
int main() {
	int n, m; scanf("%d%d",&n,&m);
	scanf("%s",s + 1); rep(i,1,n) t[i] = s[i];
	rep(j,1,m) {
		int l, r; scanf("%d%d",&l,&r);
		int c = 0; rep(i,l,r) if (s[i] == '0') c++;
		rep(i,l,l+c-1) s[i] = '0'; rep(i,l + c,r) s[i] = '1';
		c = 0; rep(i,l,r) if (t[i] == '1') c++;
		rep(i,l,l+c-1) t[i] = '1'; rep(i,l + c,r) t[i] = '0';
	}
	f[0][0] = 1; int cnt_s = 0, cnt_t = 0;
	rep(i,1,n) {
		cnt_s += s[i] - '0', cnt_t += t[i] - '0';
		rep(j,0,i) if (cnt_s <= j && j <= cnt_t) {
			f[i][j] = f[i - 1][j]; if (j) ( f[i][j] += f[i - 1][j - 1] ) %= mod;
		}
	}
	cout <<f[n][cnt_s] % mod<<endl;
	return 0;
}