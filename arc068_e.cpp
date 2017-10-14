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
const int N = 300010;
int ans[N];
int main() {
	int n, m; scanf("%d%d",&n,&m);
	rep(i,1,n) {
		ans[1]++;
		int a, b; scanf("%d%d",&a,&b); a--;
		for(int l = 1, r; l <= a && l <= b; l = r + 1) {
			r = min(a / (a / l), b / (b / l));
			if (a / l == b / l) ans[l]--, ans[r + 1]++;
		}
		ans[b + 1]--;
	}
	rep(i,1,m) ans[i] += ans[i - 1];
	rep(i,1,m) printf("%d\n",ans[i]);
}