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
typedef set<int ,int>::iterator sit;
const int N = 100010;
char c;
int a[N]; bool b[N];
LL s[N], sa[N];
int main() {
	int n; scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d",&a[i]);
		if (i < n) {
			c = getchar(); while (c != '-' && c != '+') c = getchar();
			if (c == '-') b[i + 1] = true; else b[i + 1] = false;
		}
	}
	dep(i,n,1) sa[i] = sa[i + 1] + a[i];
	rep(i,1,n) if (b[i]) a[i] = -a[i];
	rep(i,1,n) s[i] = s[i - 1] + a[i];
	LL ans = s[n]; int last = 0;
	rep(i,1,n) if (b[i]) {
		if (last) {
			ans = max(ans, s[last] - (sa[last + 1] - sa[i]) + sa[i]);
		}
		last = i;
	}
	cout <<ans<<endl;
}